// Auto-generated. Do not edit!

// (in-package kkanbu_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let C_Obstacle = require('./C_Obstacle.js');

//-----------------------------------------------------------

class C_Obstacles {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.camera_obstacle = null;
    }
    else {
      if (initObj.hasOwnProperty('camera_obstacle')) {
        this.camera_obstacle = initObj.camera_obstacle
      }
      else {
        this.camera_obstacle = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type C_Obstacles
    // Serialize message field [camera_obstacle]
    // Serialize the length for message field [camera_obstacle]
    bufferOffset = _serializer.uint32(obj.camera_obstacle.length, buffer, bufferOffset);
    obj.camera_obstacle.forEach((val) => {
      bufferOffset = C_Obstacle.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type C_Obstacles
    let len;
    let data = new C_Obstacles(null);
    // Deserialize message field [camera_obstacle]
    // Deserialize array length for message field [camera_obstacle]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.camera_obstacle = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.camera_obstacle[i] = C_Obstacle.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    object.camera_obstacle.forEach((val) => {
      length += C_Obstacle.getMessageSize(val);
    });
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'kkanbu_msgs/C_Obstacles';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5642af538089baa9f16e54d156a84b50';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    kkanbu_msgs/C_Obstacle[] camera_obstacle
    
    ================================================================================
    MSG: kkanbu_msgs/C_Obstacle
    float64 angle
    float64 width
    float64 distance
    string name
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new C_Obstacles(null);
    if (msg.camera_obstacle !== undefined) {
      resolved.camera_obstacle = new Array(msg.camera_obstacle.length);
      for (let i = 0; i < resolved.camera_obstacle.length; ++i) {
        resolved.camera_obstacle[i] = C_Obstacle.Resolve(msg.camera_obstacle[i]);
      }
    }
    else {
      resolved.camera_obstacle = []
    }

    return resolved;
    }
};

module.exports = C_Obstacles;
