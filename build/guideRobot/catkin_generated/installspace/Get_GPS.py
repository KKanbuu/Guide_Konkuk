#!/usr/bin/env python2
import pandas as pd
import rospy
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import Quaternion
from std_msgs.msg import String, Empty
from nav_msgs.msg import Path
from tf.transformations import quaternion_from_euler


def GPS_Parsing(): 
    for i in range(len(data.index)):
        x_list.append(data.loc[[i],['.pose.position.x']]) 
        y_list.append(data.loc[[i],['.pose.position.y']])  
        yaw_list.append(data.loc[[i],['.pose.orientation.w']]) 




def GPS_to_WayPoints(self): 

    #if input_path.shape[0] == 0:
    #   return path

    #input_path = input_path[0]
    #print("X {}, Y, {}".format(input_path[0], input_path[1]))
    path = Path()
    path.header.frame_id = "/map"
    path.header.stamp = rospy.Time.now()
    if self.current_route is not None:
        for i in range(len(data.index)):

           pose = PoseStamped()
           pose.pose.position.x = x_list[i]
           pose.pose.position.y = y_list[i]
           pose.pose.position.z = 0.0

           q = quaternion_from_euler(0.0, 0.0,yaw_list[i])
           pose.pose.orientation.x = q[0]
           pose.pose.orientation.y = q[1]
           pose.pose.orientation.z = q[2]
           pose.pose.orientation.w = q[3]
           path.poses.append(pose)

        self.waypoint_publisher.publish(path)
        rospy.loginfo("Published {} waypoints.".format(len(path.poses)))



#       path = Path()
#    pose = PoseStamped()
#    pose.header.frame_id = "/map"
#    pose.pose.position.x = x_list[i]
#    pose.pose.position.y = y_list[i]
#    pose.pose.position.z = 0.0

#    q = quaternion_from_euler(0.0, 0.0,yaw_list[i])

#    pose.pose.orientation.x = q[0]
#    pose.pose.orientation.y = q[1]
#    pose.pose.orientation.z = q[2]
#    pose.pose.orientation.w = q[3]


#    #print(pose.pose.position.z)
#    pose.header.seq = path.header.seq + 1
#    path.header.frame_id = "/map"
#    path.header.stamp = rospy.Time.now()
#    pose.header.stamp = path.header.stamp
#    path.poses.append(pose)

#    #print(path)
#    i = i +1
#    pub_path.publish(path)

#    return path


if __name__ == "__main__":

    data=pd.read_csv("/home/jh/kkanbu/src/guideRobot/map/waypoint.csv")
    x_list = []*len(data.index)
    y_list = []*len(data.index)
    yaw_list = []*len(data.index)
    GPS_Parsing()
    GPS_to_WayPoints()
    rospy.init_node('Get_GPS', anonymous=True)

    goal_publisher = rospy.Publisher("GPS_to_WayPoints", PoseStamped, queue_size=10)
    pub_path = rospy.Publisher('/path', Path, queue_size=10)



    rospy.spin()

