;; Auto-generated. Do not edit!


(when (boundp 'kkanbu_msgs::current_state)
  (if (not (find-package "KKANBU_MSGS"))
    (make-package "KKANBU_MSGS"))
  (shadow 'current_state (find-package "KKANBU_MSGS")))
(unless (find-package "KKANBU_MSGS::CURRENT_STATE")
  (make-package "KKANBU_MSGS::CURRENT_STATE"))

(in-package "ROS")
;;//! \htmlinclude current_state.msg.html


(defclass kkanbu_msgs::current_state
  :super ros::object
  :slots (_x _y _velocity _yaw _yaw_rate ))

(defmethod kkanbu_msgs::current_state
  (:init
   (&key
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:velocity __velocity) 0.0)
    ((:yaw __yaw) 0.0)
    ((:yaw_rate __yaw_rate) 0.0)
    )
   (send-super :init)
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _velocity (float __velocity))
   (setq _yaw (float __yaw))
   (setq _yaw_rate (float __yaw_rate))
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:velocity
   (&optional __velocity)
   (if __velocity (setq _velocity __velocity)) _velocity)
  (:yaw
   (&optional __yaw)
   (if __yaw (setq _yaw __yaw)) _yaw)
  (:yaw_rate
   (&optional __yaw_rate)
   (if __yaw_rate (setq _yaw_rate __yaw_rate)) _yaw_rate)
  (:serialization-length
   ()
   (+
    ;; float64 _x
    8
    ;; float64 _y
    8
    ;; float64 _velocity
    8
    ;; float64 _yaw
    8
    ;; float64 _yaw_rate
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _velocity
       (sys::poke _velocity (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _yaw
       (sys::poke _yaw (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _yaw_rate
       (sys::poke _yaw_rate (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _velocity
     (setq _velocity (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _yaw
     (setq _yaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _yaw_rate
     (setq _yaw_rate (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get kkanbu_msgs::current_state :md5sum-) "72d431a48e04cf2acb1d72d1db2b23ed")
(setf (get kkanbu_msgs::current_state :datatype-) "kkanbu_msgs/current_state")
(setf (get kkanbu_msgs::current_state :definition-)
      "float64 x
float64 y
float64 velocity
float64 yaw
float64 yaw_rate
")



(provide :kkanbu_msgs/current_state "72d431a48e04cf2acb1d72d1db2b23ed")


