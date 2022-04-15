#!/bin/sh

gnome-terminal -e  " roslaunch global_planning global_planner.launch " &
sleep 1
gnome-terminal  -e  " roslaunch kkanbu_tf broadcast_tf.launch "  &
sleep 1
gnome-terminal  -e  " roslaunch kkanbu_visualization visualization.launch "  &
sleep 1
gnome-terminal  -e  " roslaunch communication_arduino communication.launch "  &
sleep 3
gnome-terminal  -e  " roslaunch kkanbu_control control.launch " 
# gnome-terminal -e  " roslaunch vehicle_control vehicle_control.launch "
