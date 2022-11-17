import rclpy
from rclpy.node import Node
import numpy as np

from motpy_pifpaf_msg.msg import Poses
from visualization_msgs.msg import MarkerArray,Marker

class check(Node):
    def __init__(self):
        super().__init__("motpy_check")
        
        # Camera mode parameters
        self.declare_parameter("camera_mode",1)
        self.camera_mode = self.get_parameter("camera_mode").value
        '''
        ↑Camera mode
        1. RealSense
        2. Azure Kinect SDK
        3. Web Camera
        other -> Error
        '''
        in_topic = "/human_pose_3d"
        out_topic = "pose_vis"
        
        self.sub = self.create_subscription(Poses,in_topic,self.check,1)
        
        self.pub = self.create_publisher(MarkerArray,out_topic,10)
        
    def check(self,pose):
        ms = MarkerArray()
        
        i = 0
        p = 0
        for person in pose.poses:
            keypoints = np.array(person.keypoints).reshape(-1, 4)
            keypoints = keypoints[keypoints[:, 3] != 0]

            for k in keypoints:
                m = Marker()
                m.header.stamp = pose.header.stamp
                if(self.device_name == "RealSense"):
                    m.header.frame_id = "camera_color_optical_frame"
                elif(self.device_name == "Kinect"):
                    m.header.frame_id = "rgb_camera_link"
                m.id = i
                i += 1

                m.type = Marker.SPHERE
                float_value = np.array(k[:3] / 100.0,dtype=float)
                m.pose.position.x, m.pose.position.y, m.pose.position.z = float_value #k[:3] / 100.0
                #m.pose.orientation = Quaternion(0, 0, 0, 1) error起きる
                m.pose.orientation.x,m.pose.orientation.y,m.pose.orientation.z,m.pose.orientation.w =np.array([0,0,0,1],dtype=float)
                if(m.id == 5 or m.id == 6 or m.id == 11 or m.id == 12):
                    m.color.r, m.color.g, m.color.b, m.color.a = np.array([10, 100,184, 1],dtype=float)
                else:
                    m.color.r, m.color.g, m.color.b, m.color.a = np.array([0, 1, 0, 1],dtype=float)
                #m.scale = Vector3(0.1, 0.1, 0.1)#TypeError: __init__() takes 1 positional argument but 4 were given
                m.scale.x =0.25
                m.scale.y =0.25
                m.scale.z =0.25
                m.ns = pose.id[p]

                #print(m)
                ms.markers.append(m)
        p += 1
        self.pub.publish(ms)
        #print(ms)

        
def main(args = None):
    print("Starting camera_color_optical_frame")
    rclpy.init(args=args)
    
    node = check()
    
    rclpy.spin(node)
    
    rclpy.shutdown()            

if __name__ == "__main__":
    
    main()
            