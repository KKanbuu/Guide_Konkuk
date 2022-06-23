;; Auto-generated. Do not edit!


(when (boundp 'kkanbu_msgs::SensorPoint)
  (if (not (find-package "KKANBU_MSGS"))
    (make-package "KKANBU_MSGS"))
  (shadow 'SensorPoint (find-package "KKANBU_MSGS")))
(unless (find-package "KKANBU_MSGS::SENSORPOINT")
  (make-package "KKANBU_MSGS::SENSORPOINT"))

(in-package "ROS")
;;//! \htmlinclude SensorPoint.msg.html


(defclass kkanbu_msgs::SensorPoint
  :super ros::object
  :slots (_x _y _r _mode ))

(defmethod kkanbu_msgs::SensorPoint
  (:init
   (&key
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:r __r) 0.0)
    ((:mode __mode) nil)
    )
   (send-super :init)
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _r (float __r))
   (setq _mode __mode)
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:r
   (&optional __r)
   (if __r (setq _r __r)) _r)
  (:mode
   (&optional __mode)
   (if __mode (setq _mode __mode)) _mode)
  (:serialization-length
   ()
   (+
    ;; float64 _x
    8
    ;; float64 _y
    8
    ;; float64 _r
    8
    ;; bool _mode
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _r
       (sys::poke _r (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; bool _mode
       (if _mode (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _r
     (setq _r (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; bool _mode
     (setq _mode (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get kkanbu_msgs::SensorPoint :md5sum-) "37283248e3bfbd787f4ded58467d8ace")
(setf (get kkanbu_msgs::SensorPoint :datatype-) "kkanbu_msgs/SensorPoint")
(setf (get kkanbu_msgs::SensorPoint :definition-)
      "float64 x
float64 y
float64 r
bool mode
")



(provide :kkanbu_msgs/SensorPoint "37283248e3bfbd787f4ded58467d8ace")


