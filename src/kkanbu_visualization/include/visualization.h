#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "kkanbu_msgs/VehicleState.h"

#include <math.h>
#include "std_msgs/Float32.h"

#include <ros/ros.h>
#include <tf/tf.h>

#include "nav_msgs/Odometry.h"
#include "visualization_msgs/Marker.h"
#include "visualization_msgs/MarkerArray.h"

#define PI 3.14159265358979323846 /* pi */

class Visualizatoin{
    private:
        ros::NodeHandle nh_;

        ros::Publisher pub_vehicleModelMarker;
        ros::Publisher pub_vehicleSpeed;
        ros::Publisher pub_vehicleOdom;

        visualization_msgs::Marker vehicle_model_marker_;

    public:
        Visualizatoin(){
            pub_vehicleModelMarker = nh_.advertise<visualization_msgs::Marker>("vehicleDae",100);
            pub_vehicleSpeed = nh_.advertise<std_msgs::Float32>("vehicle_speed", 100);
            pub_vehicleOdom  = nh_.advertise<nav_msgs::Odometry>("vehicle_odom", 100);
        }
        ~Visualizatoin(){}
    public:
        void makeVehicleModelMarker();
        void publishAllMarker();

};



#endif