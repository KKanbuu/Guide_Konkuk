; Auto-generated. Do not edit!


(cl:in-package kkanbu_msgs-msg)


;//! \htmlinclude LocalPathArray.msg.html

(cl:defclass <LocalPathArray> (roslisp-msg-protocol:ros-message)
  ((local_paths
    :reader local_paths
    :initarg :local_paths
    :type (cl:vector nav_msgs-msg:Path)
   :initform (cl:make-array 0 :element-type 'nav_msgs-msg:Path :initial-element (cl:make-instance 'nav_msgs-msg:Path)))
   (collision_a
    :reader collision_a
    :initarg :collision_a
    :type (cl:vector cl:boolean)
   :initform (cl:make-array 0 :element-type 'cl:boolean :initial-element cl:nil)))
)

(cl:defclass LocalPathArray (<LocalPathArray>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LocalPathArray>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LocalPathArray)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kkanbu_msgs-msg:<LocalPathArray> is deprecated: use kkanbu_msgs-msg:LocalPathArray instead.")))

(cl:ensure-generic-function 'local_paths-val :lambda-list '(m))
(cl:defmethod local_paths-val ((m <LocalPathArray>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kkanbu_msgs-msg:local_paths-val is deprecated.  Use kkanbu_msgs-msg:local_paths instead.")
  (local_paths m))

(cl:ensure-generic-function 'collision_a-val :lambda-list '(m))
(cl:defmethod collision_a-val ((m <LocalPathArray>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kkanbu_msgs-msg:collision_a-val is deprecated.  Use kkanbu_msgs-msg:collision_a instead.")
  (collision_a m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LocalPathArray>) ostream)
  "Serializes a message object of type '<LocalPathArray>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'local_paths))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'local_paths))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'collision_a))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if ele 1 0)) ostream))
   (cl:slot-value msg 'collision_a))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LocalPathArray>) istream)
  "Deserializes a message object of type '<LocalPathArray>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'local_paths) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'local_paths)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'nav_msgs-msg:Path))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'collision_a) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'collision_a)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:not (cl:zerop (cl:read-byte istream)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LocalPathArray>)))
  "Returns string type for a message object of type '<LocalPathArray>"
  "kkanbu_msgs/LocalPathArray")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LocalPathArray)))
  "Returns string type for a message object of type 'LocalPathArray"
  "kkanbu_msgs/LocalPathArray")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LocalPathArray>)))
  "Returns md5sum for a message object of type '<LocalPathArray>"
  "e0b308c9bef08f15a4ea70121d79659d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LocalPathArray)))
  "Returns md5sum for a message object of type 'LocalPathArray"
  "e0b308c9bef08f15a4ea70121d79659d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LocalPathArray>)))
  "Returns full string definition for message of type '<LocalPathArray>"
  (cl:format cl:nil "nav_msgs/Path[] local_paths~%bool[] collision_a~%================================================================================~%MSG: nav_msgs/Path~%#An array of poses that represents a Path for a robot to follow~%Header header~%geometry_msgs/PoseStamped[] poses~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/PoseStamped~%# A Pose with reference coordinate frame and timestamp~%Header header~%Pose pose~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LocalPathArray)))
  "Returns full string definition for message of type 'LocalPathArray"
  (cl:format cl:nil "nav_msgs/Path[] local_paths~%bool[] collision_a~%================================================================================~%MSG: nav_msgs/Path~%#An array of poses that represents a Path for a robot to follow~%Header header~%geometry_msgs/PoseStamped[] poses~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/PoseStamped~%# A Pose with reference coordinate frame and timestamp~%Header header~%Pose pose~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LocalPathArray>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'local_paths) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'collision_a) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LocalPathArray>))
  "Converts a ROS message object to a list"
  (cl:list 'LocalPathArray
    (cl:cons ':local_paths (local_paths msg))
    (cl:cons ':collision_a (collision_a msg))
))
