// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/TurtleKilled.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_KILLED__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_KILLED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/turtle_killed__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_TurtleKilled_name
{
public:
  Init_TurtleKilled_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::msg::TurtleKilled name(::my_robot_interfaces::msg::TurtleKilled::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::TurtleKilled msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::TurtleKilled>()
{
  return my_robot_interfaces::msg::builder::Init_TurtleKilled_name();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_KILLED__BUILDER_HPP_
