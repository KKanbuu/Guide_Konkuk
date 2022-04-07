; Auto-generated. Do not edit!


(cl:in-package local_planning-msg)


;//! \htmlinclude MyFirstMsg.msg.html

(cl:defclass <MyFirstMsg> (roslisp-msg-protocol:ros-message)
  ((a
    :reader a
    :initarg :a
    :type cl:float
    :initform 0.0))
)

(cl:defclass MyFirstMsg (<MyFirstMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MyFirstMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MyFirstMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name local_planning-msg:<MyFirstMsg> is deprecated: use local_planning-msg:MyFirstMsg instead.")))

(cl:ensure-generic-function 'a-val :lambda-list '(m))
(cl:defmethod a-val ((m <MyFirstMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader local_planning-msg:a-val is deprecated.  Use local_planning-msg:a instead.")
  (a m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MyFirstMsg>) ostream)
  "Serializes a message object of type '<MyFirstMsg>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'a))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MyFirstMsg>) istream)
  "Deserializes a message object of type '<MyFirstMsg>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MyFirstMsg>)))
  "Returns string type for a message object of type '<MyFirstMsg>"
  "local_planning/MyFirstMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MyFirstMsg)))
  "Returns string type for a message object of type 'MyFirstMsg"
  "local_planning/MyFirstMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MyFirstMsg>)))
  "Returns md5sum for a message object of type '<MyFirstMsg>"
  "8d59eeb6f47744097bbc77f6e8d9be14")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MyFirstMsg)))
  "Returns md5sum for a message object of type 'MyFirstMsg"
  "8d59eeb6f47744097bbc77f6e8d9be14")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MyFirstMsg>)))
  "Returns full string definition for message of type '<MyFirstMsg>"
  (cl:format cl:nil "float64 a~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MyFirstMsg)))
  "Returns full string definition for message of type 'MyFirstMsg"
  (cl:format cl:nil "float64 a~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MyFirstMsg>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MyFirstMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'MyFirstMsg
    (cl:cons ':a (a msg))
))
