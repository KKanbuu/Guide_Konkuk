;; Auto-generated. Do not edit!


(when (boundp 'kkanbu_msgs::LandmarkPath)
  (if (not (find-package "KKANBU_MSGS"))
    (make-package "KKANBU_MSGS"))
  (shadow 'LandmarkPath (find-package "KKANBU_MSGS")))
(unless (find-package "KKANBU_MSGS::LANDMARKPATH")
  (make-package "KKANBU_MSGS::LANDMARKPATH"))

(in-package "ROS")
;;//! \htmlinclude LandmarkPath.msg.html


(defclass kkanbu_msgs::LandmarkPath
  :super ros::object
  :slots (_path ))

(defmethod kkanbu_msgs::LandmarkPath
  (:init
   (&key
    ((:path __path) (let (r) (dotimes (i 0) (push (instance kkanbu_msgs::LandmarkPoint :init) r)) r))
    )
   (send-super :init)
   (setq _path __path)
   self)
  (:path
   (&rest __path)
   (if (keywordp (car __path))
       (send* _path __path)
     (progn
       (if __path (setq _path (car __path)))
       _path)))
  (:serialization-length
   ()
   (+
    ;; kkanbu_msgs/LandmarkPoint[] _path
    (apply #'+ (send-all _path :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; kkanbu_msgs/LandmarkPoint[] _path
     (write-long (length _path) s)
     (dolist (elem _path)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; kkanbu_msgs/LandmarkPoint[] _path
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _path (let (r) (dotimes (i n) (push (instance kkanbu_msgs::LandmarkPoint :init) r)) r))
     (dolist (elem- _path)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get kkanbu_msgs::LandmarkPath :md5sum-) "2f561f1dae5c847ab458bdcaa0be33f2")
(setf (get kkanbu_msgs::LandmarkPath :datatype-) "kkanbu_msgs/LandmarkPath")
(setf (get kkanbu_msgs::LandmarkPath :definition-)
      "LandmarkPoint[] path

================================================================================
MSG: kkanbu_msgs/LandmarkPoint
float64 x
float64 y
float64 yaw
")



(provide :kkanbu_msgs/LandmarkPath "2f561f1dae5c847ab458bdcaa0be33f2")


