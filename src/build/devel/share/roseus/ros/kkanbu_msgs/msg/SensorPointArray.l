;; Auto-generated. Do not edit!


(when (boundp 'kkanbu_msgs::SensorPointArray)
  (if (not (find-package "KKANBU_MSGS"))
    (make-package "KKANBU_MSGS"))
  (shadow 'SensorPointArray (find-package "KKANBU_MSGS")))
(unless (find-package "KKANBU_MSGS::SENSORPOINTARRAY")
  (make-package "KKANBU_MSGS::SENSORPOINTARRAY"))

(in-package "ROS")
;;//! \htmlinclude SensorPointArray.msg.html


(defclass kkanbu_msgs::SensorPointArray
  :super ros::object
  :slots (_obs_info ))

(defmethod kkanbu_msgs::SensorPointArray
  (:init
   (&key
    ((:obs_info __obs_info) (let (r) (dotimes (i 0) (push (instance kkanbu_msgs::SensorPoint :init) r)) r))
    )
   (send-super :init)
   (setq _obs_info __obs_info)
   self)
  (:obs_info
   (&rest __obs_info)
   (if (keywordp (car __obs_info))
       (send* _obs_info __obs_info)
     (progn
       (if __obs_info (setq _obs_info (car __obs_info)))
       _obs_info)))
  (:serialization-length
   ()
   (+
    ;; kkanbu_msgs/SensorPoint[] _obs_info
    (apply #'+ (send-all _obs_info :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; kkanbu_msgs/SensorPoint[] _obs_info
     (write-long (length _obs_info) s)
     (dolist (elem _obs_info)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; kkanbu_msgs/SensorPoint[] _obs_info
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _obs_info (let (r) (dotimes (i n) (push (instance kkanbu_msgs::SensorPoint :init) r)) r))
     (dolist (elem- _obs_info)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get kkanbu_msgs::SensorPointArray :md5sum-) "5907528083b582d6aa61200010c67a24")
(setf (get kkanbu_msgs::SensorPointArray :datatype-) "kkanbu_msgs/SensorPointArray")
(setf (get kkanbu_msgs::SensorPointArray :definition-)
      "SensorPoint[] obs_info
================================================================================
MSG: kkanbu_msgs/SensorPoint
float64 x
float64 y
float64 r
bool mode
")



(provide :kkanbu_msgs/SensorPointArray "5907528083b582d6aa61200010c67a24")


