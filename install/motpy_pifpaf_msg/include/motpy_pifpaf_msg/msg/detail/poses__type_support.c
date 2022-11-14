// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from motpy_pifpaf_msg:msg/Poses.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "motpy_pifpaf_msg/msg/detail/poses__rosidl_typesupport_introspection_c.h"
#include "motpy_pifpaf_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "motpy_pifpaf_msg/msg/detail/poses__functions.h"
#include "motpy_pifpaf_msg/msg/detail/poses__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `poses`
#include "motpy_pifpaf_msg/msg/pose.h"
// Member `poses`
#include "motpy_pifpaf_msg/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `id`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Poses__rosidl_typesupport_introspection_c__Poses_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  motpy_pifpaf_msg__msg__Poses__init(message_memory);
}

void Poses__rosidl_typesupport_introspection_c__Poses_fini_function(void * message_memory)
{
  motpy_pifpaf_msg__msg__Poses__fini(message_memory);
}

size_t Poses__rosidl_typesupport_introspection_c__size_function__Pose__poses(
  const void * untyped_member)
{
  const motpy_pifpaf_msg__msg__Pose__Sequence * member =
    (const motpy_pifpaf_msg__msg__Pose__Sequence *)(untyped_member);
  return member->size;
}

const void * Poses__rosidl_typesupport_introspection_c__get_const_function__Pose__poses(
  const void * untyped_member, size_t index)
{
  const motpy_pifpaf_msg__msg__Pose__Sequence * member =
    (const motpy_pifpaf_msg__msg__Pose__Sequence *)(untyped_member);
  return &member->data[index];
}

void * Poses__rosidl_typesupport_introspection_c__get_function__Pose__poses(
  void * untyped_member, size_t index)
{
  motpy_pifpaf_msg__msg__Pose__Sequence * member =
    (motpy_pifpaf_msg__msg__Pose__Sequence *)(untyped_member);
  return &member->data[index];
}

bool Poses__rosidl_typesupport_introspection_c__resize_function__Pose__poses(
  void * untyped_member, size_t size)
{
  motpy_pifpaf_msg__msg__Pose__Sequence * member =
    (motpy_pifpaf_msg__msg__Pose__Sequence *)(untyped_member);
  motpy_pifpaf_msg__msg__Pose__Sequence__fini(member);
  return motpy_pifpaf_msg__msg__Pose__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember Poses__rosidl_typesupport_introspection_c__Poses_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motpy_pifpaf_msg__msg__Poses, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "poses",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motpy_pifpaf_msg__msg__Poses, poses),  // bytes offset in struct
    NULL,  // default value
    Poses__rosidl_typesupport_introspection_c__size_function__Pose__poses,  // size() function pointer
    Poses__rosidl_typesupport_introspection_c__get_const_function__Pose__poses,  // get_const(index) function pointer
    Poses__rosidl_typesupport_introspection_c__get_function__Pose__poses,  // get(index) function pointer
    Poses__rosidl_typesupport_introspection_c__resize_function__Pose__poses  // resize(index) function pointer
  },
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motpy_pifpaf_msg__msg__Poses, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Poses__rosidl_typesupport_introspection_c__Poses_message_members = {
  "motpy_pifpaf_msg__msg",  // message namespace
  "Poses",  // message name
  3,  // number of fields
  sizeof(motpy_pifpaf_msg__msg__Poses),
  Poses__rosidl_typesupport_introspection_c__Poses_message_member_array,  // message members
  Poses__rosidl_typesupport_introspection_c__Poses_init_function,  // function to initialize message memory (memory has to be allocated)
  Poses__rosidl_typesupport_introspection_c__Poses_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Poses__rosidl_typesupport_introspection_c__Poses_message_type_support_handle = {
  0,
  &Poses__rosidl_typesupport_introspection_c__Poses_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_motpy_pifpaf_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, motpy_pifpaf_msg, msg, Poses)() {
  Poses__rosidl_typesupport_introspection_c__Poses_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  Poses__rosidl_typesupport_introspection_c__Poses_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, motpy_pifpaf_msg, msg, Pose)();
  if (!Poses__rosidl_typesupport_introspection_c__Poses_message_type_support_handle.typesupport_identifier) {
    Poses__rosidl_typesupport_introspection_c__Poses_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Poses__rosidl_typesupport_introspection_c__Poses_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
