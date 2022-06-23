;; Auto-generated. Do not edit!


(when (boundp 'kkanbu_msgs::C_Obstacle)
  (if (not (find-package "KKANBU_MSGS"))
    (make-package "KKANBU_MSGS"))
  (shadow 'C_Obstacle (find-package "KKANBU_MSGS")))
(unless (find-package "KKANBU_MSGS::C_OBSTACLE")
  (make-package "KKANBU_MSGS::C_OBSTACLE"))

(in-package "ROS")
;;//! \htmlinclude C_Obstacle.msg.html


(defclass kkanbu_msgs::C_Obstacle
  :super ros::object
  :slots (_angle _width _distance _name ))

(defmethod kkanbu_msgs::C_Obstacle
  (:init
   (&key
    ((:angle __angle) 0.0)
    ((:width __width) 0.0)
    ((:distance __distance) 0.0)
    ((:name __name) "")
    )
   (send-super :init)
   (setq _angle (float __angle))
   (setq _width (float __width))
   (setq _distance (float __distance))
   (setq _name (string __name))
   self)
  (:angle
   (&optional __angle)
   (if __angle (setq _angle __angle)) _angle)
  (:width
   (&optional __width)
   (if __width (setq _width __width)) _width)
  (:distance
   (&optional __distance)
   (if __distance (setq _distance __distance)) _distance)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:serialization-length
   ()
   (+
    ;; float64 _angle
    8
    ;; float64 _width
    8
    ;; float64 _distance
    8
    ;; string _name
    4 (length _name)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _angle
       (sys::poke _angle (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _width
       (sys::poke _width (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _distance
       (sys::poke _distance (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _angle
     (setq _angle (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _width
     (setq _width (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _distance
     (setq _distance (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get kkanbu_msgs::C_Obstacle :md5sum-) "053445bdb8cb0f34db3951850719d3b0")
(setf (get kkanbu_msgs::C_Obstacle :datatype-) "kkanbu_msgs/C_Obstacle")
(setf (get kkanbu_msgs::C_Obstacle :definition-)
      "float64 angle
float64 width
float64 distance
string name

")



(provide :kkanbu_msgs/C_Obstacle "053445bdb8cb0f34db3951850719d3b0")


