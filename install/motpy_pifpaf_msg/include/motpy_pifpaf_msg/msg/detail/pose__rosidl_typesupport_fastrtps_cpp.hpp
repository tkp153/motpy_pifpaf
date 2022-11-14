// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from motpy_pifpaf_msg:msg/Pose.idl
// generated code does not contain a copyright notice

#ifndef MOTPY_PIFPAF_MSG__MSG__DETAIL__POSE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define MOTPY_PIFPAF_MSG__MSG__DETAIL__POSE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "motpy_pifpaf_msg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "motpy_pifpaf_msg/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace motpy_pifpaf_msg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motpy_pifpaf_msg
cdr_serialize(
  const motpy_pifpaf_msg::msg::Pose & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motpy_pifpaf_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  motpy_pifpaf_msg::msg::Pose & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motpy_pifpaf_msg
get_serialized_size(
  const motpy_pifpaf_msg::msg::Pose & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motpy_pifpaf_msg
max_serialized_size_Pose(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace motpy_pifpaf_msg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motpy_pifpaf_msg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, motpy_pifpaf_msg, msg, Pose)();

#ifdef __cplusplus
}
#endif

#endif  // MOTPY_PIFPAF_MSG__MSG__DETAIL__POSE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
