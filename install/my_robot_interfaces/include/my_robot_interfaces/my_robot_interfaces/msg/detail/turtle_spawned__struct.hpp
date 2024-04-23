// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_interfaces:msg/TurtleSpawned.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_SPAWNED__STRUCT_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_SPAWNED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__msg__TurtleSpawned __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__msg__TurtleSpawned __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TurtleSpawned_
{
  using Type = TurtleSpawned_<ContainerAllocator>;

  explicit TurtleSpawned_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->turtle = "";
    }
  }

  explicit TurtleSpawned_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : turtle(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->turtle = "";
    }
  }

  // field types and members
  using _turtle_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _turtle_type turtle;

  // setters for named parameter idiom
  Type & set__turtle(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->turtle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::msg::TurtleSpawned_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::msg::TurtleSpawned_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::TurtleSpawned_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::TurtleSpawned_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::TurtleSpawned_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::TurtleSpawned_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::TurtleSpawned_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::TurtleSpawned_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::TurtleSpawned_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::TurtleSpawned_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__msg__TurtleSpawned
    std::shared_ptr<my_robot_interfaces::msg::TurtleSpawned_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__msg__TurtleSpawned
    std::shared_ptr<my_robot_interfaces::msg::TurtleSpawned_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TurtleSpawned_ & other) const
  {
    if (this->turtle != other.turtle) {
      return false;
    }
    return true;
  }
  bool operator!=(const TurtleSpawned_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TurtleSpawned_

// alias to use template instance with default allocator
using TurtleSpawned =
  my_robot_interfaces::msg::TurtleSpawned_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE_SPAWNED__STRUCT_HPP_
