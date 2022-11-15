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
        
        # Camera mode setting
        if(camera_mode == 1):
            In_DepthInfo_Topic = "/camera/aligned_to_color/camera_info"
            In_Depth_Topic = "/camera/aligned_to_color/image_raw"
            In_Pose_Topic = "/human_pose"
            Out_Topic = "human_pose_3D"
            QOS_Profile = "best"
        elif(camera_mode == 2):
            In_DepthInfo_Topic = "/depth_to_rgb/camera_info"
            In_Depth_Topic = "/depth_to_rgb/image_raw"
            In_Pose_Topic = "/human_pose"
            Out_Topic = "human_pose_3d"
            QOS_Profile = "best"
        elif(camera_mode == 3):
            self.get_logger().error("Web Camera is not Supported")
        else:
            self.get_logger().error("out of range (camera_mode setting) or not supported camera mode")
        
        # Qos profile setting    
        if(QOS_Profile == "best"):
            video_qos = rclpy.qos.QoSProfile(depth = 10)
            video_qos.reliability = rclpy.qos.QoSReliabilityPolicy.BEST_EFFORT
        elif(QOS_Profile =="good"):
            video_qos = rclpy.qos.QoSProfile(depth = 5)
            video_qos.reliability = rclpy.qos.QoSReliabilityPolicy.BEST_EFFORT
            
        else:
            self.get_logger().error("out of range (QOS_Profile setting setting")
            
        # Subscriber area
        sub_depth =Subscriber(self,Image, In_Depth_Topic,qos_profile =video_qos)
        sub_info = Subscriber(self,CameraInfo, In_DepthInfo_Topic,qos_profile =video_qos)
        sub_poses = Subscriber(self,Poses,In_Pose_Topic,qos_profile =video_qos)
        
        ts = ApproximateTimeSynchronizer([sub_depth,sub_info,sub_poses],100,0.2)
        ts.registerCallback(self.RGBD_Callbacks)
        
        self.pub = self.create_publisher(Poses,Out_Topic,1)
        
    def RGBD_Callbacks(self,depth,info,poses):

        depth_img = self.bridge.imgmsg_to_cv2(depth)

        poses_3d = []
        for p in poses.poses:
            keypoints = np.asarray(p.keypoints).reshape(-1, 3)  # x, y, conf
            keypoints_pos = np.floor(keypoints).astype(np.int64)

            idx = keypoints_pos[:, 1] * depth_img.shape[1] + keypoints_pos[:, 0]
            flag = idx >= 0
            flag[flag] = idx[flag] < (depth_img.shape[0] * depth_img.shape[1])
            flag[flag] = keypoints[flag, 2] != 0

            depth_values = np.zeros((len(keypoints_pos), 1))
            depth_values[flag] = depth_img.reshape(-1, 1)[idx[flag]]

            xy = (keypoints[:, :2] - np.array([info.k[2], info.k[5]])) / np.array([info.k[0], info.k[4]])
            xy = xy * depth_values

            keypoints_3d = np.hstack((xy, depth_values, keypoints[:, 2:]))
            keypoints_3d[~flag] = np.array([0, 0, 0, 0])

            pose_3d = Pose()
            pose_3d.keypoints = list(keypoints_3d.reshape(-1))
            poses_3d.append(pose_3d)
            
        self.publish(poses.header,poses_3d)
        
    def publishV2(self,header,poses_3d):
        msg = Pose()
        pmsg = Pose()
        msg.poses = []
        
        for p in poses_3d:
            
            pmsg = Pose()
            pmsg.keypoints = p.keypoints
            msg.poses.append(pmsg)
            
        self.pub.publish(msg)
        
    def main():
        
        rclpy.init()
        
        node = RGBD_motpy_pifpaf()
        
        rclpy.spin(node)
        
        rclpy.shutdown()
        
    if __name__ == "__main__":
        main()
