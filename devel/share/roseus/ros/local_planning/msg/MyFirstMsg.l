;; Auto-generated. Do not edit!


(when (boundp 'local_planning::MyFirstMsg)
  (if (not (find-package "LOCAL_PLANNING"))
    (make-package "LOCAL_PLANNING"))
  (shadow 'MyFirstMsg (find-package "LOCAL_PLANNING")))
(unless (find-package "LOCAL_PLANNING::MYFIRSTMSG")
  (make-package "LOCAL_PLANNING::MYFIRSTMSG"))

(in-package "ROS")
;;//! \htmlinclude MyFirstMsg.msg.html


(defclass local_planning::MyFirstMsg
  :super ros::object
  :slots (_a ))

(defmethod local_planning::MyFirstMsg
  (:init
   (&key
    ((:a __a) 0.0)
    )
   (send-super :init)
   (setq _a (float __a))
   self)
  (:a
   (&optional __a)
   (if __a (setq _a __a)) _a)
  (:serialization-length
   ()
   (+
    ;; float64 _a
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _a
       (sys::poke _a (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _a
     (setq _a (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get local_planning::MyFirstMsg :md5sum-) "8d59eeb6f47744097bbc77f6e8d9be14")
(setf (get local_planning::MyFirstMsg :datatype-) "local_planning/MyFirstMsg")
(setf (get local_planning::MyFirstMsg :definition-)
      "float64 a

")



(provide :local_planning/MyFirstMsg "8d59eeb6f47744097bbc77f6e8d9be14")


