// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:srv/TurtleCatch.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__TURTLE_CATCH__STRUCT_H_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__TURTLE_CATCH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/TurtleCatch in the package my_robot_interfaces.
typedef struct my_robot_interfaces__srv__TurtleCatch_Request
{
  rosidl_runtime_c__String name;
} my_robot_interfaces__srv__TurtleCatch_Request;

// Struct for a sequence of my_robot_interfaces__srv__TurtleCatch_Request.
typedef struct my_robot_interfaces__srv__TurtleCatch_Request__Sequence
{
  my_robot_interfaces__srv__TurtleCatch_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__srv__TurtleCatch_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/TurtleCatch in the package my_robot_interfaces.
typedef struct my_robot_interfaces__srv__TurtleCatch_Response
{
  bool success;
} my_robot_interfaces__srv__TurtleCatch_Response;

// Struct for a sequence of my_robot_interfaces__srv__TurtleCatch_Response.
typedef struct my_robot_interfaces__srv__TurtleCatch_Response__Sequence
{
  my_robot_interfaces__srv__TurtleCatch_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__srv__TurtleCatch_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__TURTLE_CATCH__STRUCT_H_
