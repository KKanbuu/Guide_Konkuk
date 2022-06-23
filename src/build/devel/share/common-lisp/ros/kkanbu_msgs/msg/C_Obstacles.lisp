; Auto-generated. Do not edit!


(cl:in-package kkanbu_msgs-msg)


;//! \htmlinclude C_Obstacles.msg.html

(cl:defclass <C_Obstacles> (roslisp-msg-protocol:ros-message)
  ((camera_obstacle
    :reader camera_obstacle
    :initarg :camera_obstacle
    :type (cl:vector kkanbu_msgs-msg:C_Obstacle)
   :initform (cl:make-array 0 :element-type 'kkanbu_msgs-msg:C_Obstacle :initial-element (cl:make-instance 'kkanbu_msgs-msg:C_Obstacle))))
)

(cl:defclass C_Obstacles (<C_Obstacles>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <C_Obstacles>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'C_Obstacles)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kkanbu_msgs-msg:<C_Obstacles> is deprecated: use kkanbu_msgs-msg:C_Obstacles instead.")))

(cl:ensure-generic-function 'camera_obstacle-val :lambda-list '(m))
(cl:defmethod camera_obstacle-val ((m <C_Obstacles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kkanbu_msgs-msg:camera_obstacle-val is deprecated.  Use kkanbu_msgs-msg:camera_obstacle instead.")
  (camera_obstacle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <C_Obstacles>) ostream)
  "Serializes a message object of type '<C_Obstacles>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'camera_obstacle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'camera_obstacle))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <C_Obstacles>) istream)
  "Deserializes a message object of type '<C_Obstacles>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'camera_obstacle) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'camera_obstacle)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'kkanbu_msgs-msg:C_Obstacle))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<C_Obstacles>)))
  "Returns string type for a message object of type '<C_Obstacles>"
  "kkanbu_msgs/C_Obstacles")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'C_Obstacles)))
  "Returns string type for a message object of type 'C_Obstacles"
  "kkanbu_msgs/C_Obstacles")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<C_Obstacles>)))
  "Returns md5sum for a message object of type '<C_Obstacles>"
  "5642af538089baa9f16e54d156a84b50")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'C_Obstacles)))
  "Returns md5sum for a message object of type 'C_Obstacles"
  "5642af538089baa9f16e54d156a84b50")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<C_Obstacles>)))
  "Returns full string definition for message of type '<C_Obstacles>"
  (cl:format cl:nil "kkanbu_msgs/C_Obstacle[] camera_obstacle~%~%================================================================================~%MSG: kkanbu_msgs/C_Obstacle~%float64 angle~%float64 width~%float64 distance~%string name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'C_Obstacles)))
  "Returns full string definition for message of type 'C_Obstacles"
  (cl:format cl:nil "kkanbu_msgs/C_Obstacle[] camera_obstacle~%~%================================================================================~%MSG: kkanbu_msgs/C_Obstacle~%float64 angle~%float64 width~%float64 distance~%string name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <C_Obstacles>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'camera_obstacle) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <C_Obstacles>))
  "Converts a ROS message object to a list"
  (cl:list 'C_Obstacles
    (cl:cons ':camera_obstacle (camera_obstacle msg))
))
