#!/usr/bin/env python2
from os import path
import pandas as pd
import numpy as np
import rospy
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import Quaternion
from std_msgs.msg import String, Empty
from nav_msgs.msg import Path
from tf.transformations import quaternion_from_euler
from kkanbu_msgs.msg import LandmarkPath
from kkanbu_msgs.msg import LandmarkPoint

class GlobalPlanner():
    def __init__(self):
        # ROS node Initiate
        rospy.init_node('Get_GPS', anonymous=True)
        
        ## Parameters(Launch Param)
        self._map = rospy.get_param('map') #'/home/jh/Documents/GitHub/Guide_Konkuk/src/global_planning/map/waypoint.csv' 
        
        # Variables
        self._data = pd.read_csv(self._map)
        self._x_df = []
        self._y_df = []
        self._yaw_df = []
        self._x_list = []
        self._y_list = []
        self._yaw_list = []
        self._entire_path = Path()
        self._landmark_path=LandmarkPath()

        # Publisher
        self.entire_path_publisher = rospy.Publisher(
            "/map/entire_path",Path,queue_size=1)

        self.landmark_publisher = rospy.Publisher(
            "/map/landmark_point",LandmarkPath,queue_size=1)
        # Subscriber

    def destroy(self):
        self.entire_path_publisher.unregister()


    def GPS_Parsing(self): 
        for i in range(len(self._data.index)):
            self._x_df.append(self._data.loc[[i],['.pose.position.x']]) 
            self._y_df.append(self._data.loc[[i],['.pose.position.y']])  
            self._yaw_df.append(self._data.loc[[i],['.pose.orientation.w']])
        for i in range(len(self._x_df)):
            self._x_list.append(self._x_df[i].iloc[0]['.pose.position.x'])
            self._y_list.append(self._y_df[i].iloc[0]['.pose.position.y'])
            self._yaw_list.append(self._yaw_df[i].iloc[0]['.pose.orientation.w'])
        
        # print(self._x_df[1])
        # print(len(self._data.index))
        # print(len(self._x_df[1].iloc[0]['.pose.position.x']))
        # print(self._x_df[2201].iloc[0]['.pose.position.x'])


    def GPS_to_WayPoints(self): 

        self._entire_path.header.frame_id = "/map"
        self._entire_path.header.stamp = rospy.Time.now()
        if self._data is not None:
            for i in range(len(self._data.index)):
                if i % 3 == 0:
                    pose = PoseStamped()
                    point = LandmarkPoint()
                    pose.pose.position.x = self._x_list[i]
                    pose.pose.position.y = self._y_list[i]
                    pose.pose.position.z = 0.0
                    point.x =  self._x_list[i]
                    point.y = self._y_list[i]
                    point.yaw=self._yaw_list[i]
                    

                    q = quaternion_from_euler(0.0, 0.0,self._yaw_list[i])
                    pose.pose.orientation.x = q[0]
                    pose.pose.orientation.y = q[1]
                    pose.pose.orientation.z = q[2]
                    pose.pose.orientation.w = q[3]
                    self._entire_path.poses.append(pose)
                    self._landmark_path.path.append(point)


            
            rospy.loginfo("Published {} waypoints.".format(len(self._entire_path.poses)))

    
    def publish_entire_path(self):
        self.entire_path_publisher.publish(self._entire_path)
        self.landmark_publisher.publish(self._landmark_path)

    def run(self):
        rate = rospy.Rate(100)
        self.GPS_Parsing()
        self.GPS_to_WayPoints()

        while not rospy.is_shutdown():
            self.publish_entire_path()

            rate.sleep()

# ==============================================================================
# -- main() --------------------------------------------------------------------
# ==============================================================================


def main():
    GB = GlobalPlanner()
    try:
        GB.run()
    finally:
        if GB is not None:
            GB.destroy()

if __name__ == "__main__":
    main()

