// Auto-generated. Do not edit!

// (in-package kkanbu_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let nav_msgs = _finder('nav_msgs');

//-----------------------------------------------------------

class LocalPathArray {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.local_paths = null;
      this.collision_a = null;
    }
    else {
      if (initObj.hasOwnProperty('local_paths')) {
        this.local_paths = initObj.local_paths
      }
      else {
        this.local_paths = [];
      }
      if (initObj.hasOwnProperty('collision_a')) {
        this.collision_a = initObj.collision_a
      }
      else {
        this.collision_a = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type LocalPathArray
    // Serialize message field [local_paths]
    // Serialize the length for message field [local_paths]
    bufferOffset = _serializer.uint32(obj.local_paths.length, buffer, bufferOffset);
    obj.local_paths.forEach((val) => {
      bufferOffset = nav_msgs.msg.Path.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [collision_a]
    bufferOffset = _arraySerializer.bool(obj.collision_a, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type LocalPathArray
    let len;
    let data = new LocalPathArray(null);
    // Deserialize message field [local_paths]
    // Deserialize array length for message field [local_paths]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.local_paths = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.local_paths[i] = nav_msgs.msg.Path.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [collision_a]
    data.collision_a = _arrayDeserializer.bool(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    object.local_paths.forEach((val) => {
      length += nav_msgs.msg.Path.getMessageSize(val);
    });
    length += object.collision_a.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'kkanbu_msgs/LocalPathArray';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e0b308c9bef08f15a4ea70121d79659d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    nav_msgs/Path[] local_paths
    bool[] collision_a
    ================================================================================
    MSG: nav_msgs/Path
    #An array of poses that represents a Path for a robot to follow
    Header header
    geometry_msgs/PoseStamped[] poses
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    string frame_id
    
    ================================================================================
    MSG: geometry_msgs/PoseStamped
    # A Pose with reference coordinate frame and timestamp
    Header header
    Pose pose
    
    ================================================================================
    MSG: geometry_msgs/Pose
    # A representation of pose in free space, composed of position and orientation. 
    Point position
    Quaternion orientation
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    ================================================================================
    MSG: geometry_msgs/Quaternion
    # This represents an orientation in free space in quaternion form.
    
    float64 x
    float64 y
    float64 z
    float64 w
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new LocalPathArray(null);
    if (msg.local_paths !== undefined) {
      resolved.local_paths = new Array(msg.local_paths.length);
      for (let i = 0; i < resolved.local_paths.length; ++i) {
        resolved.local_paths[i] = nav_msgs.msg.Path.Resolve(msg.local_paths[i]);
      }
    }
    else {
      resolved.local_paths = []
    }

    if (msg.collision_a !== undefined) {
      resolved.collision_a = msg.collision_a;
    }
    else {
      resolved.collision_a = []
    }

    return resolved;
    }
};

module.exports = LocalPathArray;
