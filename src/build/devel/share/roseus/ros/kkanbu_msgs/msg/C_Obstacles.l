;; Auto-generated. Do not edit!


(when (boundp 'kkanbu_msgs::C_Obstacles)
  (if (not (find-package "KKANBU_MSGS"))
    (make-package "KKANBU_MSGS"))
  (shadow 'C_Obstacles (find-package "KKANBU_MSGS")))
(unless (find-package "KKANBU_MSGS::C_OBSTACLES")
  (make-package "KKANBU_MSGS::C_OBSTACLES"))

(in-package "ROS")
;;//! \htmlinclude C_Obstacles.msg.html


(defclass kkanbu_msgs::C_Obstacles
  :super ros::object
  :slots (_camera_obstacle ))

(defmethod kkanbu_msgs::C_Obstacles
  (:init
   (&key
    ((:camera_obstacle __camera_obstacle) (let (r) (dotimes (i 0) (push (instance kkanbu_msgs::C_Obstacle :init) r)) r))
    )
   (send-super :init)
   (setq _camera_obstacle __camera_obstacle)
   self)
  (:camera_obstacle
   (&rest __camera_obstacle)
   (if (keywordp (car __camera_obstacle))
       (send* _camera_obstacle __camera_obstacle)
     (progn
       (if __camera_obstacle (setq _camera_obstacle (car __camera_obstacle)))
       _camera_obstacle)))
  (:serialization-length
   ()
   (+
    ;; kkanbu_msgs/C_Obstacle[] _camera_obstacle
    (apply #'+ (send-all _camera_obstacle :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; kkanbu_msgs/C_Obstacle[] _camera_obstacle
     (write-long (length _camera_obstacle) s)
     (dolist (elem _camera_obstacle)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; kkanbu_msgs/C_Obstacle[] _camera_obstacle
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _camera_obstacle (let (r) (dotimes (i n) (push (instance kkanbu_msgs::C_Obstacle :init) r)) r))
     (dolist (elem- _camera_obstacle)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get kkanbu_msgs::C_Obstacles :md5sum-) "5642af538089baa9f16e54d156a84b50")
(setf (get kkanbu_msgs::C_Obstacles :datatype-) "kkanbu_msgs/C_Obstacles")
(setf (get kkanbu_msgs::C_Obstacles :definition-)
      "kkanbu_msgs/C_Obstacle[] camera_obstacle

================================================================================
MSG: kkanbu_msgs/C_Obstacle
float64 angle
float64 width
float64 distance
string name

")



(provide :kkanbu_msgs/C_Obstacles "5642af538089baa9f16e54d156a84b50")


