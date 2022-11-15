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
class motpy_pifpaf(Node):
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
            self.get_logger().error("out of ranges")
        
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
            self.get_logger().error("out of range")
            
        # Generate subscription
        self.subscription = self.create_subscription(Image,in_topic,self.motpy_callback,video_qos)
        
        # Generate Publisher
        self.publisher = self.create_publisher(Poses,out_topic,video_qos)
        
        #CvBridge
        self.bride = CvBridge()
        self.scale = scale
        
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
        id = []
        bbox,score,label = self.voc_publish(poses)
        tracks = Motpy_engine.track(self,bbox,score,label)
        for trc in tracks:
                id_data = Motpy_engine.id_track(self,rgb_image,trc,thickness=1)
                print("tracksid: " + id_data)
                id.append(id_data)
        self.publish(data.header,poses,id) 
        

    # Publish functions
    def publish(self,header,poses,id):
        
        msg = Poses()
        msg.header.stamp = header.stamp
        msg.poses = []
            
            
        
        for p in poses:
            pmsg = Pose()
            pmsg.keypoints = p['keypoints']
            msg.poses.append(pmsg)
        msg.id = id
        
        self.publisher.publish(msg)
    
    def voc_publish(self,poses):
        bbox = []
        score =[]
        label = []
        
        for p in poses:
            my_coco_box = p['bbox']
            coco_box = Motpy_engine.xywh_to_xyxy(self,my_coco_box)
            scores = p['score']
            labels = p['category_id']
            bbox.append(coco_box)
            score.append(scores)
            label.append(labels)
        
        return bbox,score,label    
            
class Motpy_engine():
    def __init__(self):
        self.mode = None
        
        
    def track(self,boxes,scores,labels):
        id = []
        tracker = MultiObjectTracker(dt = 0.1)
        outputs = [Detection(box = b,score= s, class_id = l) for b,s,l in zip(boxes,scores,labels)]
        
        tracker.step(detections = outputs)
        
        tracks = tracker.active_tracks()
        
        return tracks
    
    def id_track(self,img, track: Track, random_color: bool = True, fallback_color=(200, 20, 20), thickness: int = 5, text_at_bottom: bool = False, text_verbose: int = 1):
        color = [ord(c) * ord(c) % 256 for c in track.id[:3]] if random_color else fallback_color
        draw_rectangle(img, track.box, color=color, thickness=thickness)
        pos = (track.box[0], track.box[3]) if text_at_bottom else (track.box[0], track.box[1])

        if text_verbose > 0:
            text = track_to_string(track) if text_verbose == 2 else track.id[:8]
            draw_text(img, text, pos=pos)

        return text
    
    
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
    
    node = motpy_pifpaf()
    
    rclpy.spin(node)
    
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()