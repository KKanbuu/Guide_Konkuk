#ifndef CONTROL_KKANBU_H
#define CONTROL_KKANBU_H
#include <math.h>
#include <ros/ros.h>

#include <tf/tf.h>

#include "kkanbu_msgs/ControlCommand.h"
#include "kkanbu_msgs/VehicleState.h"

#include "geometry_msgs/PoseStamped.h"
#include "nav_msgs/Odometry.h"
#include "nav_msgs/Path.h"

#define PI 3.14159265358979323846 /* pi */

class Control_Robot{
    private:
        ros::NodeHandle nh_;
        
        ros::Publisher pub_ControlCommand;

        ros::Subscriber sub_VehicleState;
        ros::Subscriber sub_LocalPath;

    public:
        Control_Robot();
        ~Control_Robot();

        // Callback Func
        void get_VehicleState(const kkanbu_msgs::VehicleState::ConstPtr& msg);
        void get_LocalPath(const nav_msgs::Path::ConstPtr& msg);

        //Func
        void LongitudinalControl();
        void LateralControl();
        void Publish_ControlCommand();
        void find_ClosestWaypoint();

    private:
        // Param
        double target_velocity_;
        double p_gain_;
        int lookAhead_;

        // Input
        kkanbu_msgs::VehicleState vehicle_state_;
        nav_msgs::Path best_local_path_;

        //Output
        kkanbu_msgs::ControlCommand control_cmd_;

        // Variables
        int closest_idx_;
        int lookAhead_idx_;
        double lookAhead_yaw_;
        double wheelBase_ = 0.6;
        geometry_msgs::PoseStamped lookAhead_Pose_;
        bool isPath = false;
};

#endif