; Auto-generated. Do not edit!


(cl:in-package kkanbu_msgs-msg)


;//! \htmlinclude SensorPointArray.msg.html

(cl:defclass <SensorPointArray> (roslisp-msg-protocol:ros-message)
  ((obs_info
    :reader obs_info
    :initarg :obs_info
    :type (cl:vector kkanbu_msgs-msg:SensorPoint)
   :initform (cl:make-array 0 :element-type 'kkanbu_msgs-msg:SensorPoint :initial-element (cl:make-instance 'kkanbu_msgs-msg:SensorPoint))))
)

(cl:defclass SensorPointArray (<SensorPointArray>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SensorPointArray>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SensorPointArray)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kkanbu_msgs-msg:<SensorPointArray> is deprecated: use kkanbu_msgs-msg:SensorPointArray instead.")))

(cl:ensure-generic-function 'obs_info-val :lambda-list '(m))
(cl:defmethod obs_info-val ((m <SensorPointArray>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kkanbu_msgs-msg:obs_info-val is deprecated.  Use kkanbu_msgs-msg:obs_info instead.")
  (obs_info m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SensorPointArray>) ostream)
  "Serializes a message object of type '<SensorPointArray>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'obs_info))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'obs_info))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SensorPointArray>) istream)
  "Deserializes a message object of type '<SensorPointArray>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'obs_info) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'obs_info)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'kkanbu_msgs-msg:SensorPoint))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SensorPointArray>)))
  "Returns string type for a message object of type '<SensorPointArray>"
  "kkanbu_msgs/SensorPointArray")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SensorPointArray)))
  "Returns string type for a message object of type 'SensorPointArray"
  "kkanbu_msgs/SensorPointArray")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SensorPointArray>)))
  "Returns md5sum for a message object of type '<SensorPointArray>"
  "5907528083b582d6aa61200010c67a24")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SensorPointArray)))
  "Returns md5sum for a message object of type 'SensorPointArray"
  "5907528083b582d6aa61200010c67a24")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SensorPointArray>)))
  "Returns full string definition for message of type '<SensorPointArray>"
  (cl:format cl:nil "SensorPoint[] obs_info~%================================================================================~%MSG: kkanbu_msgs/SensorPoint~%float64 x~%float64 y~%float64 r~%bool mode~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SensorPointArray)))
  "Returns full string definition for message of type 'SensorPointArray"
  (cl:format cl:nil "SensorPoint[] obs_info~%================================================================================~%MSG: kkanbu_msgs/SensorPoint~%float64 x~%float64 y~%float64 r~%bool mode~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SensorPointArray>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'obs_info) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SensorPointArray>))
  "Converts a ROS message object to a list"
  (cl:list 'SensorPointArray
    (cl:cons ':obs_info (obs_info msg))
))
