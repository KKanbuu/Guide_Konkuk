// Auto-generated. Do not edit!

// (in-package kkanbu_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let SensorPoint = require('./SensorPoint.js');

//-----------------------------------------------------------

class SensorPointArray {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.obs_info = null;
    }
    else {
      if (initObj.hasOwnProperty('obs_info')) {
        this.obs_info = initObj.obs_info
      }
      else {
        this.obs_info = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SensorPointArray
    // Serialize message field [obs_info]
    // Serialize the length for message field [obs_info]
    bufferOffset = _serializer.uint32(obj.obs_info.length, buffer, bufferOffset);
    obj.obs_info.forEach((val) => {
      bufferOffset = SensorPoint.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SensorPointArray
    let len;
    let data = new SensorPointArray(null);
    // Deserialize message field [obs_info]
    // Deserialize array length for message field [obs_info]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.obs_info = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.obs_info[i] = SensorPoint.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 25 * object.obs_info.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'kkanbu_msgs/SensorPointArray';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5907528083b582d6aa61200010c67a24';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    SensorPoint[] obs_info
    ================================================================================
    MSG: kkanbu_msgs/SensorPoint
    float64 x
    float64 y
    float64 r
    bool mode
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SensorPointArray(null);
    if (msg.obs_info !== undefined) {
      resolved.obs_info = new Array(msg.obs_info.length);
      for (let i = 0; i < resolved.obs_info.length; ++i) {
        resolved.obs_info[i] = SensorPoint.Resolve(msg.obs_info[i]);
      }
    }
    else {
      resolved.obs_info = []
    }

    return resolved;
    }
};

module.exports = SensorPointArray;
