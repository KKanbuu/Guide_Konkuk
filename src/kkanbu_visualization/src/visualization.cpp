#include "visualization.h"

void Visualizatoin::makeVehicleModelMarker(){
    
    vehicle_model_marker_.header.frame_id = "/ego";
    vehicle_model_marker_.header.stamp = ros::Time::now();
    vehicle_model_marker_.ns = "--KKANBU--";
    vehicle_model_marker_.id = 0;
    // Set the marker type
    vehicle_model_marker_.type = visualization_msgs::Marker::MESH_RESOURCE;
    vehicle_model_marker_.mesh_resource =
        "package://kkanbu_visualization/resources/car.dae";
    vehicle_model_marker_.mesh_use_embedded_materials = true;
    tf::Quaternion q;
    q.setRPY(PI/2,0,0);

    vehicle_model_marker_.pose.position.x = 0;
    vehicle_model_marker_.pose.position.y = 0;
    vehicle_model_marker_.pose.position.z = 0.0;
    vehicle_model_marker_.pose.orientation.x = q.getX();
    vehicle_model_marker_.pose.orientation.y = q.getY();
    vehicle_model_marker_.pose.orientation.z = q.getZ();
    vehicle_model_marker_.pose.orientation.w = q.getW();
    
    // Set the scale of the marker
    vehicle_model_marker_.scale.x = 0.2;
    vehicle_model_marker_.scale.y = 0.2;
    vehicle_model_marker_.scale.z = 0.2;
    // Color Pink
    vehicle_model_marker_.color.r = 1.0;
    vehicle_model_marker_.color.g = 0.3;
    vehicle_model_marker_.color.b = 0.5;
    vehicle_model_marker_.color.a = 1.0;

    vehicle_model_marker_.lifetime = ros::Duration(0.1);
}

void Visualizatoin::publishAllMarker(){
    pub_vehicleModelMarker.publish(vehicle_model_marker_);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "kkanbu_visualization");
  // Vehicle vehicle;
  Visualizatoin visualization;

  // 60 Hz visualization
  ros::Rate loop_rate(60);
  while (ros::ok()) {
    visualization.makeVehicleModelMarker();
    visualization.publishAllMarker();
    
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}