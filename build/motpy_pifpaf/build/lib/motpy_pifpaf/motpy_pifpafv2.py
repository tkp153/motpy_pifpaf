import rclpy
from rclpy.node import Node
import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from openpifpaf.predictor import Predictor
from motpy_pifpaf_msg.msg import Pose,Poses
from motpy import Detection,MultiObjectTracker
from motpy import track_to_string
from motpy.core import Detection,Track
import numpy as np
from motpy.testing_viz import draw_rectangle,draw_text

# ROS2 main class
class motpy_pifpafV2(Node):
    def __init__(self):
        super().__init__("motpy_pifpaf")
        
        
        ''' 
            Camera mode
            1. RealSense
            2. Azure Kinect SDK
            3. Web Camera
        '''
        
        # Calling a Openpifpaf.predictor module
        self.predictor = Predictor()
        # Camera mode parameters -> Default parameters 1: RealSense
        self.declare_parameter('camera_mode',"3")
        camera_mode = int(self.get_parameter('camera_mode').value)
        
        # Debug mode parameters (OpenCV imshow mode) -> Default parameters: False
        self.declare_parameter('debug','True')
        debug = self.get_parameter('debug').value
        if(camera_mode == 1):
            in_topic = "/camera/color/image_raw"
            out_topic = "human_pose"
            scale = 1.0
            qos_profile = "best"
        elif(camera_mode == 2):
            in_topic = "/rgb/image_raw"
            out_topic = "human_pose"
            scale = 1.0
            qos_profile = "best"
        elif(camera_mode == 3):
            in_topic = "/image_raw"
            out_topic = "human_pose"
            scale = 1.0
            qos_profile = "best"
        else:
            self.get_logger().error("out of ranges(Camera mode)")
        
        # QoSProfile setting
        if(qos_profile == "best"):
            print("best QoSProfile")
            video_qos = rclpy.qos.QoSProfile(depth = 10)
            video_qos.reliability = rclpy.qos.QoSReliabilityPolicy.BEST_EFFORT
        elif(qos_profile == "good"):
            print("good QoSProfile")
            video_qos = rclpy.qos.QoSProfile(depth = 5)
            video_qos.reliability = rclpy.qos.QoSReliabilityPolicy.BEST_EFFORT
            
        else:
            self.get_logger().error("out of range(QoSProfile)")
            
        # Generate subscription
        self.subscription = self.create_subscription(Image,in_topic,self.motpy_callback,video_qos)
        
        # Generate Publisher
        self.publisher = self.create_publisher(Poses,out_topic,video_qos)
        
        #CvBridge
        self.bride = CvBridge()
        self.scale = scale
        
        #Motpy
        self.tracker = MultiObjectTracker(dt = 0.1)
        
        # Debug Mode
        if(debug == "True"):
            self.debug = True
        elif(debug == "False"):
            self.debug = False
        else:
            self.get_logger().error("out of range(Debug Mode setting)")
        
    def motpy_callback(self,data):
        
        # Transform ROS2 Message data to OpenCV Message data type
        rgb_image = self.bride.imgmsg_to_cv2(data,"rgb8")
        
        # If the scale parameter is 1.0x below ,Perform OpenCV scale reduction processing (Keypoints Only)
        if float(self.scale)  < 1.0:
            rgb_image = cv2.resize(rgb_image,None,fx = self.scale, fy=self.scale)
            
        pred,_, meta = self.predictor.numpy_image(rgb_image)
        
        poses = []
        
        # Getting a Openpifpaf outputs data(Json Format)
        for p in pred:
            pose = p.json_data()
            
            # If the scale parameter is 1.0x below ,Perform OpenCV scale reduction processing (Keypoints Only)
            if float(self.scale) < 1.0:
                d = p.data.reshape((-1, 3))
                d[d[:, 2] != 0, 0:2] /= self.scale
                d = d.reshape(-1)
                pose['keypoints'] = list(d)
                
            
            poses.append(pose)
            
        '''
        motpy_area
        '''
        motpy_id = []
        bbox,score,label = self.voc_publish(poses)
        tracks = self.track(bbox,score,label)
        for trc in tracks:
                img,id_data = self.id_track(rgb_image,trc,thickness=1)
                #print("tracksid: " + id_data)
                motpy_id.append(id_data)
        
        if (self.debug == True):
            cv2.imshow('motpy_pifpaf(DEBUG MODE)',img)
            print(img.get(cv2.CAP_PROP_FPS))
            self.publish(data.header,poses,motpy_id)
        elif(self.debug == False):
            self.publish(data.header,poses,motpy_id)
        else:
            self.get_logger().error("out of range (Debug mode - OpenCV viewer)")
            self.publish(data.header,poses,motpy_id)
        

    # Publish functions
    def publish(self,header,poses,m_id):
        
        msg = Poses()
        msg.header.stamp = header.stamp
        msg.poses = []
            
        for p in poses:
            pmsg = Pose()
            pmsg.keypoints = p['keypoints']
            msg.poses.append(pmsg)
        msg.id = m_id
        
        self.publisher.publish(msg)
    
    # COCO format (x,y,w,h)-> VOC format(xmin,ymin,xHigh,yHigh) publisher function
    def voc_publish(self,poses):
        bbox = []
        score =[]
        label = []
        
        for p in poses:
            my_coco_box = p['bbox']
            coco_box = self.xywh_to_xyxy(my_coco_box)
            scores = p['score']
            labels = p['category_id']
            bbox.append(coco_box)
            score.append(scores)
            label.append(labels)
        
        return bbox,score,label  
    
    # Motpy track function(追跡アルゴリズム実行) : Output -> tracks (人の情報など)   
    def track(self,boxes,scores,labels):
        outputs = [Detection(box = b,score= s, class_id = l) for b,s,l in zip(boxes,scores,labels)]
        
        self.tracker.step(detections = outputs)
        
        tracks = self.tracker.active_tracks()
        
        return tracks
    
    # id generator and OpenCV show system (ID生成とOpenCV表示):
    def id_track(self,img, track: Track, random_color: bool = True, fallback_color=(200, 20, 20), thickness: int = 5, text_at_bottom: bool = False, text_verbose: int = 1):
        color = [ord(c) * ord(c) % 256 for c in track.id[:3]] if random_color else fallback_color
        draw_rectangle(img, track.box, color=color, thickness=thickness)
        pos = (track.box[0], track.box[3]) if text_at_bottom else (track.box[0], track.box[1])

        if text_verbose > 0:
            text = track_to_string(track) if text_verbose == 2 else track.id[:8]
            draw_text(img, text, pos=pos)

        return img,text
    
    # convert xywh_to_xyxy calculate function: Output -> x1: xLow, y1: yLow, x2: xHigh, y2:yHigh
    def xywh_to_xyxy(self,data):
        
        """convert xywh format to xyxy format"""
        x1 = data[0]
        y1 = data[1]
        w  = data[2]
        h  = data[3]
        
        x2 = x1 + w
        y2 = y1 + h
        voc = np.array([x1,y1,x2,y2])
        return  voc
    
            
def main():
    
    print("starts")
    
    #Node initialization
    rclpy.init()
    
    node = motpy_pifpafV2()
    
    #Node spin
    rclpy.spin(node)
    
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()