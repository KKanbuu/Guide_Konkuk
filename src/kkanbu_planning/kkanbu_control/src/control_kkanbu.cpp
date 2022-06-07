#include "control_kkanbu.h"

Control_Robot::Control_Robot(){
    // Param
    nh_.param("kkanbu_control/ego/target_velocity", target_velocity_, 0.0);
    nh_.param("kkanbu_control/ego/p_gain", p_gain_, 0.0);
    nh_.param("kkanbu_control/ego/lookAhead", lookAhead_, 0);
    
    // Publisher
    pub_ControlCommand = nh_.advertise<kkanbu_msgs::ControlCommand>("/ego/control_cmd",10);
    pub_ArduinoCommand = nh_.advertise<kkanbu_msgs::ControlCommand>("/ego/arduino_cmd",10);
    pub_lookAheadPose = nh_.advertise<visualization_msgs::Marker>("/ego/lookahead_pose",10);
    // Subscriber
    sub_VehicleState = nh_.subscribe("/ego/vehicle_state",10,&Control_Robot::get_VehicleState,this);
    sub_LocalPath = nh_.subscribe("/local/best_path",10,&Control_Robot::get_LocalPath,this);
}

Control_Robot::~Control_Robot(){}

void Control_Robot::get_VehicleState(const kkanbu_msgs::VehicleState::ConstPtr& msg){
    vehicle_state_ = *msg;
}

void Control_Robot::get_LocalPath(const nav_msgs::Path::ConstPtr& msg){
    best_local_path_ = *msg;
    isPath = true;
}

void Control_Robot::LongitudinalControl(){
    double error_velocity = target_velocity_ - vehicle_state_.velocity;
    if(error_velocity < 0){
        control_cmd_.accel = 0;
        control_cmd_.brake = fabs(error_velocity) * p_gain_;
    }else{
        control_cmd_.accel = error_velocity;//error_velocity * p_gain_;
        arduino_control_cmd_.accel = 100;
        control_cmd_.brake = 0;
    }
}

geometry_msgs::PoseStamped Control_Robot::transformEgo2World(geometry_msgs::PoseStamped ego_frame_pose){
    geometry_msgs::PoseStamped world_frame_pose;
    world_frame_pose.header.frame_id = "/map";
    try{
        ego_frame_pose.header.frame_id = "/ego";
        ego2map.transformPose("/map",ego_frame_pose,world_frame_pose);
    }catch (tf::TransformException &ex){
        ROS_ERROR("%s",ex.what());
        // ros::Duration(1.0).sleep();
        // continue;
    }
    return world_frame_pose;
    

    // double min_distance = 1000;
    
    // for(int i=0;i<best_local_path_.poses.size();i++){
    //     double temp_distance = sqrt(pow(vehicle_state_.x - best_local_path_.poses[i].pose.position.x,2)+pow(vehicle_state_.y - best_local_path_.poses[i].pose.position.y,2));
    //     if(temp_distance < min_distance){
    //         closest_idx_ = i;
    //         min_distance = temp_distance;
    //     }
    // }
}

void Control_Robot::Make_LookAheadMarker(geometry_msgs::PoseStamped lookAhead_Pose){
    lookAhead_pose_maker_.header.frame_id = "/map";
    lookAhead_pose_maker_.header.stamp = ros::Time::now();
    // lookAhead_pose_maker_.ns = "Lateral Control";
    // lookAhead_pose_maker_.id = 0;
    lookAhead_pose_maker_.type = visualization_msgs::Marker::SPHERE;
    lookAhead_pose_maker_.pose.position.x = lookAhead_Pose.pose.position.x;
    lookAhead_pose_maker_.pose.position.y = lookAhead_Pose.pose.position.y;
    lookAhead_pose_maker_.scale.x = 0.5;
    lookAhead_pose_maker_.scale.y = 0.5;
    lookAhead_pose_maker_.scale.z = 0.5;
    lookAhead_pose_maker_.color.r = 1.0;
    lookAhead_pose_maker_.color.g = 0.0;
    lookAhead_pose_maker_.color.b = 0.0;
    lookAhead_pose_maker_.color.a = 1.0;
}

void Control_Robot::LateralControl(){
    if(isPath){
        lookAhead_idx_ = closest_idx_ + lookAhead_;
        lookAhead_Pose_ = transformEgo2World(best_local_path_.poses[lookAhead_idx_]);
        Make_LookAheadMarker(lookAhead_Pose_);
        double lookAhead_distance = sqrt(pow(vehicle_state_.x - lookAhead_Pose_.pose.position.x,2)+pow(vehicle_state_.y - lookAhead_Pose_.pose.position.y,2));
        double alpha = atan2(lookAhead_Pose_.pose.position.y -vehicle_state_.y,lookAhead_Pose_.pose.position.x -vehicle_state_.x ) - vehicle_state_.yaw;
        control_cmd_.steering = atan2(2 * wheelBase_ * sin(alpha),lookAhead_distance);
        arduino_control_cmd_.steering = -(control_cmd_.steering * (180/PI) * 10) + 90;//-();
    }else{
        control_cmd_.steering = 0;
        ROS_WARN("Path isn't subscribed yet!");
    }
    
}

void Control_Robot::Publish_ControlCommand(){
    LongitudinalControl();
    LateralControl();
    pub_ControlCommand.publish(control_cmd_);
    pub_ArduinoCommand.publish(arduino_control_cmd_);
    pub_lookAheadPose.publish(lookAhead_pose_maker_);
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "kkanbu_control");
  Control_Robot cr;

  // The approximate control time is 100 Hz
  ros::Rate loop_rate(100);
  
  while (ros::ok()) {
    cr.Publish_ControlCommand();
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}



