// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:srv/TurtleCoordinates.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__TURTLE_COORDINATES__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__TURTLE_COORDINATES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/srv/detail/turtle_coordinates__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_TurtleCoordinates_Request_name
{
public:
  Init_TurtleCoordinates_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::srv::TurtleCoordinates_Request name(::my_robot_interfaces::srv::TurtleCoordinates_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::srv::TurtleCoordinates_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::srv::TurtleCoordinates_Request>()
{
  return my_robot_interfaces::srv::builder::Init_TurtleCoordinates_Request_name();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_TurtleCoordinates_Response_y
{
public:
  explicit Init_TurtleCoordinates_Response_y(::my_robot_interfaces::srv::TurtleCoordinates_Response & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::srv::TurtleCoordinates_Response y(::my_robot_interfaces::srv::TurtleCoordinates_Response::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::srv::TurtleCoordinates_Response msg_;
};

class Init_TurtleCoordinates_Response_x
{
public:
  Init_TurtleCoordinates_Response_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TurtleCoordinates_Response_y x(::my_robot_interfaces::srv::TurtleCoordinates_Response::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_TurtleCoordinates_Response_y(msg_);
  }

private:
  ::my_robot_interfaces::srv::TurtleCoordinates_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::srv::TurtleCoordinates_Response>()
{
  return my_robot_interfaces::srv::builder::Init_TurtleCoordinates_Response_x();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__TURTLE_COORDINATES__BUILDER_HPP_
