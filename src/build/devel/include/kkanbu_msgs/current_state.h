// Generated by gencpp from file kkanbu_msgs/current_state.msg
// DO NOT EDIT!


#ifndef KKANBU_MSGS_MESSAGE_CURRENT_STATE_H
#define KKANBU_MSGS_MESSAGE_CURRENT_STATE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace kkanbu_msgs
{
template <class ContainerAllocator>
struct current_state_
{
  typedef current_state_<ContainerAllocator> Type;

  current_state_()
    : x(0.0)
    , y(0.0)
    , velocity(0.0)
    , yaw(0.0)
    , yaw_rate(0.0)  {
    }
  current_state_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , velocity(0.0)
    , yaw(0.0)
    , yaw_rate(0.0)  {
  (void)_alloc;
    }



   typedef double _x_type;
  _x_type x;

   typedef double _y_type;
  _y_type y;

   typedef double _velocity_type;
  _velocity_type velocity;

   typedef double _yaw_type;
  _yaw_type yaw;

   typedef double _yaw_rate_type;
  _yaw_rate_type yaw_rate;





  typedef boost::shared_ptr< ::kkanbu_msgs::current_state_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kkanbu_msgs::current_state_<ContainerAllocator> const> ConstPtr;

}; // struct current_state_

typedef ::kkanbu_msgs::current_state_<std::allocator<void> > current_state;

typedef boost::shared_ptr< ::kkanbu_msgs::current_state > current_statePtr;
typedef boost::shared_ptr< ::kkanbu_msgs::current_state const> current_stateConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kkanbu_msgs::current_state_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kkanbu_msgs::current_state_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::kkanbu_msgs::current_state_<ContainerAllocator1> & lhs, const ::kkanbu_msgs::current_state_<ContainerAllocator2> & rhs)
{
  return lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.velocity == rhs.velocity &&
    lhs.yaw == rhs.yaw &&
    lhs.yaw_rate == rhs.yaw_rate;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::kkanbu_msgs::current_state_<ContainerAllocator1> & lhs, const ::kkanbu_msgs::current_state_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace kkanbu_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::kkanbu_msgs::current_state_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::kkanbu_msgs::current_state_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kkanbu_msgs::current_state_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kkanbu_msgs::current_state_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kkanbu_msgs::current_state_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kkanbu_msgs::current_state_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::kkanbu_msgs::current_state_<ContainerAllocator> >
{
  static const char* value()
  {
    return "72d431a48e04cf2acb1d72d1db2b23ed";
  }

  static const char* value(const ::kkanbu_msgs::current_state_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x72d431a48e04cf2aULL;
  static const uint64_t static_value2 = 0xcb1d72d1db2b23edULL;
};

template<class ContainerAllocator>
struct DataType< ::kkanbu_msgs::current_state_<ContainerAllocator> >
{
  static const char* value()
  {
    return "kkanbu_msgs/current_state";
  }

  static const char* value(const ::kkanbu_msgs::current_state_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::kkanbu_msgs::current_state_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 x\n"
"float64 y\n"
"float64 velocity\n"
"float64 yaw\n"
"float64 yaw_rate\n"
;
  }

  static const char* value(const ::kkanbu_msgs::current_state_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::kkanbu_msgs::current_state_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.velocity);
      stream.next(m.yaw);
      stream.next(m.yaw_rate);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct current_state_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::kkanbu_msgs::current_state_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::kkanbu_msgs::current_state_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "velocity: ";
    Printer<double>::stream(s, indent + "  ", v.velocity);
    s << indent << "yaw: ";
    Printer<double>::stream(s, indent + "  ", v.yaw);
    s << indent << "yaw_rate: ";
    Printer<double>::stream(s, indent + "  ", v.yaw_rate);
  }
};

} // namespace message_operations
} // namespace ros

#endif // KKANBU_MSGS_MESSAGE_CURRENT_STATE_H
