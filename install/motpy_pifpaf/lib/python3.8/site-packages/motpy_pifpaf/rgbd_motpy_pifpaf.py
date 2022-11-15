import rclpy
from rclpy.node import Node
import cv2
from sensor_msgs.msg import Image,CameraInfo
from cv_bridge import CvBridge
from motpy_pifpaf_msg.msg import Poses,Pose
from message_filters import ApproximateTimeSynchronizer,Subscriber
import numpy as np

class RGBD_motpy_pifpaf(Node):
    def __init__(self):
        super().__init__("rgbd_motpy_pifpaf")
        
        self.bridge = CvBridge()
        
        #Camera mode parameters declare -> Default 1(RealSense)
        ''' 
        Camera mode
        1. RealSense
        2. Azure Kinect SDK
        3. Web Camera
        other -> Error
        '''
        self.declare_parameter('camera_mode','1')
        camera_mode = int(self.declare_parameter('camera_mode').value)
        
        if(camera_mode == 1):
            In_DepthInfo_Topic = "/camera/aligned_to_color/camera_info"
            In_Depth_Topic = "/camera/aligned_to_color/image_raw"
            In_Pose_Topic = ""