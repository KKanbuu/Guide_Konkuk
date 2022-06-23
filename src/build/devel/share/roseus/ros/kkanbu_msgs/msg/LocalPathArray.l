;; Auto-generated. Do not edit!


(when (boundp 'kkanbu_msgs::LocalPathArray)
  (if (not (find-package "KKANBU_MSGS"))
    (make-package "KKANBU_MSGS"))
  (shadow 'LocalPathArray (find-package "KKANBU_MSGS")))
(unless (find-package "KKANBU_MSGS::LOCALPATHARRAY")
  (make-package "KKANBU_MSGS::LOCALPATHARRAY"))

(in-package "ROS")
;;//! \htmlinclude LocalPathArray.msg.html
(if (not (find-package "NAV_MSGS"))
  (ros::roseus-add-msgs "nav_msgs"))


(defclass kkanbu_msgs::LocalPathArray
  :super ros::object
  :slots (_local_paths _collision_a ))

(defmethod kkanbu_msgs::LocalPathArray
  (:init
   (&key
    ((:local_paths __local_paths) (let (r) (dotimes (i 0) (push (instance nav_msgs::Path :init) r)) r))
    ((:collision_a __collision_a) (let (r) (dotimes (i 0) (push nil r)) r))
    )
   (send-super :init)
   (setq _local_paths __local_paths)
   (setq _collision_a __collision_a)
   self)
  (:local_paths
   (&rest __local_paths)
   (if (keywordp (car __local_paths))
       (send* _local_paths __local_paths)
     (progn
       (if __local_paths (setq _local_paths (car __local_paths)))
       _local_paths)))
  (:collision_a
   (&optional __collision_a)
   (if __collision_a (setq _collision_a __collision_a)) _collision_a)
  (:serialization-length
   ()
   (+
    ;; nav_msgs/Path[] _local_paths
    (apply #'+ (send-all _local_paths :serialization-length)) 4
    ;; bool[] _collision_a
    (* 1    (length _collision_a)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; nav_msgs/Path[] _local_paths
     (write-long (length _local_paths) s)
     (dolist (elem _local_paths)
       (send elem :serialize s)
       )
     ;; bool[] _collision_a
     (write-long (length _collision_a) s)
     (dotimes (i (length _collision_a))
       (if (elt _collision_a i) (write-byte -1 s) (write-byte 0 s))
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; nav_msgs/Path[] _local_paths
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _local_paths (let (r) (dotimes (i n) (push (instance nav_msgs::Path :init) r)) r))
     (dolist (elem- _local_paths)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; bool[] _collision_a
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _collision_a (make-list n))
     (dotimes (i n)
     (setf (elt _collision_a i) (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
     ))
   ;;
   self)
  )

(setf (get kkanbu_msgs::LocalPathArray :md5sum-) "e0b308c9bef08f15a4ea70121d79659d")
(setf (get kkanbu_msgs::LocalPathArray :datatype-) "kkanbu_msgs/LocalPathArray")
(setf (get kkanbu_msgs::LocalPathArray :definition-)
      "nav_msgs/Path[] local_paths
bool[] collision_a
================================================================================
MSG: nav_msgs/Path
#An array of poses that represents a Path for a robot to follow
Header header
geometry_msgs/PoseStamped[] poses

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: geometry_msgs/PoseStamped
# A Pose with reference coordinate frame and timestamp
Header header
Pose pose

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

")



(provide :kkanbu_msgs/LocalPathArray "e0b308c9bef08f15a4ea70121d79659d")


