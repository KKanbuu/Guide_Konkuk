;; Auto-generated. Do not edit!


(when (boundp 'kkanbu_msgs::CircleObstacle)
  (if (not (find-package "KKANBU_MSGS"))
    (make-package "KKANBU_MSGS"))
  (shadow 'CircleObstacle (find-package "KKANBU_MSGS")))
(unless (find-package "KKANBU_MSGS::CIRCLEOBSTACLE")
  (make-package "KKANBU_MSGS::CIRCLEOBSTACLE"))

(in-package "ROS")
;;//! \htmlinclude CircleObstacle.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass kkanbu_msgs::CircleObstacle
  :super ros::object
  :slots (_center _velocity _radius _true_radius _angle _c_distance _min_distance ))

(defmethod kkanbu_msgs::CircleObstacle
  (:init
   (&key
    ((:center __center) (instance geometry_msgs::Point :init))
    ((:velocity __velocity) (instance geometry_msgs::Vector3 :init))
    ((:radius __radius) 0.0)
    ((:true_radius __true_radius) 0.0)
    ((:angle __angle) 0.0)
    ((:c_distance __c_distance) 0.0)
    ((:min_distance __min_distance) 0.0)
    )
   (send-super :init)
   (setq _center __center)
   (setq _velocity __velocity)
   (setq _radius (float __radius))
   (setq _true_radius (float __true_radius))
   (setq _angle (float __angle))
   (setq _c_distance (float __c_distance))
   (setq _min_distance (float __min_distance))
   self)
  (:center
   (&rest __center)
   (if (keywordp (car __center))
       (send* _center __center)
     (progn
       (if __center (setq _center (car __center)))
       _center)))
  (:velocity
   (&rest __velocity)
   (if (keywordp (car __velocity))
       (send* _velocity __velocity)
     (progn
       (if __velocity (setq _velocity (car __velocity)))
       _velocity)))
  (:radius
   (&optional __radius)
   (if __radius (setq _radius __radius)) _radius)
  (:true_radius
   (&optional __true_radius)
   (if __true_radius (setq _true_radius __true_radius)) _true_radius)
  (:angle
   (&optional __angle)
   (if __angle (setq _angle __angle)) _angle)
  (:c_distance
   (&optional __c_distance)
   (if __c_distance (setq _c_distance __c_distance)) _c_distance)
  (:min_distance
   (&optional __min_distance)
   (if __min_distance (setq _min_distance __min_distance)) _min_distance)
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Point _center
    (send _center :serialization-length)
    ;; geometry_msgs/Vector3 _velocity
    (send _velocity :serialization-length)
    ;; float64 _radius
    8
    ;; float64 _true_radius
    8
    ;; float64 _angle
    8
    ;; float64 _c_distance
    8
    ;; float64 _min_distance
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Point _center
       (send _center :serialize s)
     ;; geometry_msgs/Vector3 _velocity
       (send _velocity :serialize s)
     ;; float64 _radius
       (sys::poke _radius (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _true_radius
       (sys::poke _true_radius (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _angle
       (sys::poke _angle (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _c_distance
       (sys::poke _c_distance (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _min_distance
       (sys::poke _min_distance (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Point _center
     (send _center :deserialize buf ptr-) (incf ptr- (send _center :serialization-length))
   ;; geometry_msgs/Vector3 _velocity
     (send _velocity :deserialize buf ptr-) (incf ptr- (send _velocity :serialization-length))
   ;; float64 _radius
     (setq _radius (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _true_radius
     (setq _true_radius (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _angle
     (setq _angle (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _c_distance
     (setq _c_distance (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _min_distance
     (setq _min_distance (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get kkanbu_msgs::CircleObstacle :md5sum-) "05bb128df3c5085b6180e623f9261236")
(setf (get kkanbu_msgs::CircleObstacle :datatype-) "kkanbu_msgs/CircleObstacle")
(setf (get kkanbu_msgs::CircleObstacle :definition-)
      "geometry_msgs/Point center      # Central point [m]
geometry_msgs/Vector3 velocity  # Linear velocity [m/s]
float64 radius                  # Radius with added margin [m]
float64 true_radius             # True measured radius [m]
float64 angle			# Angle of Center [degree]
float64 c_distance		# Distance from Center [m]
float64 min_distance		# Min_Distance [m]

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
")



(provide :kkanbu_msgs/CircleObstacle "05bb128df3c5085b6180e623f9261236")


