; Auto-generated. Do not edit!


(cl:in-package kkanbu_msgs-msg)


;//! \htmlinclude LandmarkPath.msg.html

(cl:defclass <LandmarkPath> (roslisp-msg-protocol:ros-message)
  ((path
    :reader path
    :initarg :path
    :type (cl:vector kkanbu_msgs-msg:LandmarkPoint)
   :initform (cl:make-array 0 :element-type 'kkanbu_msgs-msg:LandmarkPoint :initial-element (cl:make-instance 'kkanbu_msgs-msg:LandmarkPoint))))
)

(cl:defclass LandmarkPath (<LandmarkPath>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LandmarkPath>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LandmarkPath)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kkanbu_msgs-msg:<LandmarkPath> is deprecated: use kkanbu_msgs-msg:LandmarkPath instead.")))

(cl:ensure-generic-function 'path-val :lambda-list '(m))
(cl:defmethod path-val ((m <LandmarkPath>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kkanbu_msgs-msg:path-val is deprecated.  Use kkanbu_msgs-msg:path instead.")
  (path m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LandmarkPath>) ostream)
  "Serializes a message object of type '<LandmarkPath>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'path))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'path))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LandmarkPath>) istream)
  "Deserializes a message object of type '<LandmarkPath>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'path) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'path)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'kkanbu_msgs-msg:LandmarkPoint))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LandmarkPath>)))
  "Returns string type for a message object of type '<LandmarkPath>"
  "kkanbu_msgs/LandmarkPath")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LandmarkPath)))
  "Returns string type for a message object of type 'LandmarkPath"
  "kkanbu_msgs/LandmarkPath")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LandmarkPath>)))
  "Returns md5sum for a message object of type '<LandmarkPath>"
  "2f561f1dae5c847ab458bdcaa0be33f2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LandmarkPath)))
  "Returns md5sum for a message object of type 'LandmarkPath"
  "2f561f1dae5c847ab458bdcaa0be33f2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LandmarkPath>)))
  "Returns full string definition for message of type '<LandmarkPath>"
  (cl:format cl:nil "LandmarkPoint[] path~%~%================================================================================~%MSG: kkanbu_msgs/LandmarkPoint~%float64 x~%float64 y~%float64 yaw~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LandmarkPath)))
  "Returns full string definition for message of type 'LandmarkPath"
  (cl:format cl:nil "LandmarkPoint[] path~%~%================================================================================~%MSG: kkanbu_msgs/LandmarkPoint~%float64 x~%float64 y~%float64 yaw~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LandmarkPath>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'path) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LandmarkPath>))
  "Converts a ROS message object to a list"
  (cl:list 'LandmarkPath
    (cl:cons ':path (path msg))
))
