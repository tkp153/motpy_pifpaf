import rclpy
from rclpy.node import Node
import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from openpifpaf.predictor import Predictor
from motpy_pifpaf_msg.msg import Pose,Poses
from motpy import Detection,MultiObjectTracker
import numpy as np

# ROS2 main class
class motpy_pifpaf():
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
        self.declare_parameter('camera_mode',"1")
        camera_mode = self.get.parameter('camera_mode').value
        
        if(camera_mode == 1):
            in_topic = "/camera/color/image_raw"
            out_topic = "human_pose"
            scale = 1.0
            qos_profile = "best quality"
        elif(camera_mode == 2):
            in_topic = "/rgb/image_raw"
            out_topic = "human_pose"
            scale = 1.0
            qos_profile = "best quality"
        elif(camera_mode == 3):
            in_topic = "/image_raw"
            out_topic = "human_pose"
            scale = 1.0
            qos_profile = "best quality"
        else:
            self.get_logger().error("out of ranges")
        
        # QoSProfile setting
        if(qos_profile == "best quality"):
            video_qos = rclpy.qos.QoSProfile(depth = 10)
            video_qos.reliability = rclpy.qos.QoSReliabilityPolicy.BEST_EFFORT
        elif(qos_profile == "good"):
            video_qos = rclpy.qos.QoSProfile(depth = 5)
            video_qos.reliability = rclpy.qos.QoSReliabilityPolicy.BEST_EFFORT
            
        # Generate subscription
        self.subscription = rclpy.create_subscription(Image,in_topic,self.motpy_callback,video_qos)
        
        # Generate Publisher
        self.publisher = rclpy.create_publisher(Poses,out_topic,video_qos)
        
        #CvBridge
        self.bride = CvBridge()
        self.scale = scale
        
    def motpy_callback(self,data):
        
        # Transform ROS2 Message data to OpenCV Message data type
        rgb_image = self.bride.imgmsg_to_cv2(data,"rgb8")
        
        # If the scale parameter is 1.0x below ,Perform OpenCV scale reduction processing (Keypoints Only)
        if float(self.scale)  < 1.0:
            rgb_image = cv2.resize(rgb_image,None,fx = self.scale, fy=self.scale)
            
        pred,_, meta = self.predictor.numpy_images()
        
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
        bbox,score,label = self.voc_publish(poses)
        tracks = Motpy_engine.track(bbox,score,label)
                
        
        self.publish(data.header,poses) 
        

    # Publish functions
    def publish(self,header,poses):
        
        msg = Poses()
        msg.header.stamp = header.stamp
        msg.poses = []
            
            
        
        for p in poses:
            pmsg = Pose()
            pmsg.keypoints = p['keypoints']
            msg.poses.append(pmsg)
    
    def voc_publish(self,poses):
        bbox = []
        score =[]
        label = []
        
        for p in poses:
            my_coco_box = p['bbox']
            coco_box = Motpy_engine.xywh_to_xyxy(my_coco_box)
            scores = p['score']
            labels = p['category_id']
            bbox.append(coco_box)
            score.append(scores)
            label.append(labels)
        
        return bbox,score,label    
            
class Motpy_engine():
    def __init__(self):
        self.mode = None
        self.tracker = MultiObjectTracker(dt = 0.1)
        
    def track(self,boxes,scores,labels):
        
        outputs = [Detection(box = b,score= s, class_id = l) for b,s,l in zip(boxes,scores,labels)]
        
        self.tracker.step(detections = outputs)
        
        tracks = self.tracker.active_tracks()
        return tracks
    
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