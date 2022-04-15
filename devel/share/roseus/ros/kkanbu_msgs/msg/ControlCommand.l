;; Auto-generated. Do not edit!


(when (boundp 'kkanbu_msgs::ControlCommand)
  (if (not (find-package "KKANBU_MSGS"))
    (make-package "KKANBU_MSGS"))
  (shadow 'ControlCommand (find-package "KKANBU_MSGS")))
(unless (find-package "KKANBU_MSGS::CONTROLCOMMAND")
  (make-package "KKANBU_MSGS::CONTROLCOMMAND"))

(in-package "ROS")
;;//! \htmlinclude ControlCommand.msg.html


(defclass kkanbu_msgs::ControlCommand
  :super ros::object
  :slots (_steering _accel _brake ))

(defmethod kkanbu_msgs::ControlCommand
  (:init
   (&key
    ((:steering __steering) 0.0)
    ((:accel __accel) 0.0)
    ((:brake __brake) 0.0)
    )
   (send-super :init)
   (setq _steering (float __steering))
   (setq _accel (float __accel))
   (setq _brake (float __brake))
   self)
  (:steering
   (&optional __steering)
   (if __steering (setq _steering __steering)) _steering)
  (:accel
   (&optional __accel)
   (if __accel (setq _accel __accel)) _accel)
  (:brake
   (&optional __brake)
   (if __brake (setq _brake __brake)) _brake)
  (:serialization-length
   ()
   (+
    ;; float64 _steering
    8
    ;; float64 _accel
    8
    ;; float64 _brake
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _steering
       (sys::poke _steering (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _accel
       (sys::poke _accel (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _brake
       (sys::poke _brake (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _steering
     (setq _steering (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _accel
     (setq _accel (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _brake
     (setq _brake (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get kkanbu_msgs::ControlCommand :md5sum-) "78d4e62033b2c4038de1aac2b20b2457")
(setf (get kkanbu_msgs::ControlCommand :datatype-) "kkanbu_msgs/ControlCommand")
(setf (get kkanbu_msgs::ControlCommand :definition-)
      "float64 steering
float64 accel
float64 brake
")



(provide :kkanbu_msgs/ControlCommand "78d4e62033b2c4038de1aac2b20b2457")


