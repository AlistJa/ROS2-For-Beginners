// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/TurtleSpawned.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_SPAWNED__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_SPAWNED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/turtle_spawned__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_TurtleSpawned_turtle
{
public:
  Init_TurtleSpawned_turtle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::msg::TurtleSpawned turtle(::my_robot_interfaces::msg::TurtleSpawned::_turtle_type arg)
  {
    msg_.turtle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::TurtleSpawned msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::TurtleSpawned>()
{
  return my_robot_interfaces::msg::builder::Init_TurtleSpawned_turtle();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_SPAWNED__BUILDER_HPP_
