#!/usr/bin/env python2
import pandas as pd
import rospy
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import Quaternion
from std_msgs.msg import String, Empty
from nav_msgs.msg import Path
from tf.transformations import quaternion_from_euler


class GlobalPlanner():
    def __init__(self):
        # ROS node Initiate
        rospy.init_node('Get_GPS', anonymous=True)
        
        ## Parameters(Launch Param)
        self._map = rospy.get_param('map')
        
        # Variables
        self._data
        self._x_list = []
        self._y_list = []
        self._yaw_list = []
        self._entire_path = Path()

        # Publisher
        self.entire_path_publisher = rospy.Publisher(
            "/map/entire_path",Path,queue_size=1)

        # Subscriber

    def destroy(self):
        self.entire_path_publisher.unregister()


    def GPS_Parsing(self): 
        self._data=pd.read_csv(self._map)
        for i in range(len(self._data.index)):
            self._x_list.append(self._data.loc[[i],['.pose.position.x']]) 
            self._y_list.append(self._data.loc[[i],['.pose.position.y']])  
            self._yaw_list.append(self._data.loc[[i],['.pose.orientation.w']]) 


    def GPS_to_WayPoints(self): 

        self._path.header.frame_id = "/map"
        self._path.header.stamp = rospy.Time.now()
        if self.current_route is not None:
            for i in range(len(self._data.index)):

                pose = PoseStamped()
                pose.pose.position.x = self._x_list[i]
                pose.pose.position.y = self._y_list[i]
                pose.pose.position.z = 0.0

                q = quaternion_from_euler(0.0, 0.0,self._yaw_list[i])
                pose.pose.orientation.x = q[0]
                pose.pose.orientation.y = q[1]
                pose.pose.orientation.z = q[2]
                pose.pose.orientation.w = q[3]
                self._entire_path.poses.append(pose)

            
            rospy.loginfo("Published {} waypoints.".format(len(self._entire_path.poses)))

    def publish_entire_path(self):
        self.waypoint_publisher.publish(self._entire_path)

    def run(self):
        rate = rospy.Rate(1)
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

