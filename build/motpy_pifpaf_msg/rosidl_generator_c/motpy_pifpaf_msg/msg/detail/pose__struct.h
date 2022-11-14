// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from motpy_pifpaf_msg:msg/Pose.idl
// generated code does not contain a copyright notice

#ifndef MOTPY_PIFPAF_MSG__MSG__DETAIL__POSE__STRUCT_H_
#define MOTPY_PIFPAF_MSG__MSG__DETAIL__POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'keypoints'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/Pose in the package motpy_pifpaf_msg.
typedef struct motpy_pifpaf_msg__msg__Pose
{
  rosidl_runtime_c__float__Sequence keypoints;
} motpy_pifpaf_msg__msg__Pose;

// Struct for a sequence of motpy_pifpaf_msg__msg__Pose.
typedef struct motpy_pifpaf_msg__msg__Pose__Sequence
{
  motpy_pifpaf_msg__msg__Pose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motpy_pifpaf_msg__msg__Pose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOTPY_PIFPAF_MSG__MSG__DETAIL__POSE__STRUCT_H_
