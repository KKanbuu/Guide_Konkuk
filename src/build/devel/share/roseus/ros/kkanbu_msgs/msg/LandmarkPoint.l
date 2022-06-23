;; Auto-generated. Do not edit!


(when (boundp 'kkanbu_msgs::LandmarkPoint)
  (if (not (find-package "KKANBU_MSGS"))
    (make-package "KKANBU_MSGS"))
  (shadow 'LandmarkPoint (find-package "KKANBU_MSGS")))
(unless (find-package "KKANBU_MSGS::LANDMARKPOINT")
  (make-package "KKANBU_MSGS::LANDMARKPOINT"))

(in-package "ROS")
;;//! \htmlinclude LandmarkPoint.msg.html


(defclass kkanbu_msgs::LandmarkPoint
  :super ros::object
  :slots (_x _y _yaw ))

(defmethod kkanbu_msgs::LandmarkPoint
  (:init
   (&key
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:yaw __yaw) 0.0)
    )
   (send-super :init)
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _yaw (float __yaw))
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:yaw
   (&optional __yaw)
   (if __yaw (setq _yaw __yaw)) _yaw)
  (:serialization-length
   ()
   (+
    ;; float64 _x
    8
    ;; float64 _y
    8
    ;; float64 _yaw
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
     ;; float64 _yaw
       (sys::poke _yaw (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _yaw
     (setq _yaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get kkanbu_msgs::LandmarkPoint :md5sum-) "b71344c0ba01936756dc45bcd89ef437")
(setf (get kkanbu_msgs::LandmarkPoint :datatype-) "kkanbu_msgs/LandmarkPoint")
(setf (get kkanbu_msgs::LandmarkPoint :definition-)
      "float64 x
float64 y
float64 yaw
")



(provide :kkanbu_msgs/LandmarkPoint "b71344c0ba01936756dc45bcd89ef437")


