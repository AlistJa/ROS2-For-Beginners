// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_robot_interfaces:msg/TurtleSpawned.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_SPAWNED__TRAITS_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_SPAWNED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_robot_interfaces/msg/detail/turtle_spawned__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TurtleSpawned & msg,
  std::ostream & out)
{
  out << "{";
  // member: turtle
  {
    out << "turtle: ";
    rosidl_generator_traits::value_to_yaml(msg.turtle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TurtleSpawned & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: turtle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "turtle: ";
    rosidl_generator_traits::value_to_yaml(msg.turtle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TurtleSpawned & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::msg::TurtleSpawned & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::msg::TurtleSpawned & msg)
{
  return my_robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::msg::TurtleSpawned>()
{
  return "my_robot_interfaces::msg::TurtleSpawned";
}

template<>
inline const char * name<my_robot_interfaces::msg::TurtleSpawned>()
{
  return "my_robot_interfaces/msg/TurtleSpawned";
}

template<>
struct has_fixed_size<my_robot_interfaces::msg::TurtleSpawned>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_robot_interfaces::msg::TurtleSpawned>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_robot_interfaces::msg::TurtleSpawned>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_SPAWNED__TRAITS_HPP_
