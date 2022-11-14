// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from motpy_pifpaf_msg:msg/Poses.idl
// generated code does not contain a copyright notice
#include "motpy_pifpaf_msg/msg/detail/poses__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `poses`
#include "motpy_pifpaf_msg/msg/detail/pose__functions.h"
// Member `id`
#include "rosidl_runtime_c/string_functions.h"

bool
motpy_pifpaf_msg__msg__Poses__init(motpy_pifpaf_msg__msg__Poses * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    motpy_pifpaf_msg__msg__Poses__fini(msg);
    return false;
  }
  // poses
  if (!motpy_pifpaf_msg__msg__Pose__Sequence__init(&msg->poses, 0)) {
    motpy_pifpaf_msg__msg__Poses__fini(msg);
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__Sequence__init(&msg->id, 0)) {
    motpy_pifpaf_msg__msg__Poses__fini(msg);
    return false;
  }
  return true;
}

void
motpy_pifpaf_msg__msg__Poses__fini(motpy_pifpaf_msg__msg__Poses * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // poses
  motpy_pifpaf_msg__msg__Pose__Sequence__fini(&msg->poses);
  // id
  rosidl_runtime_c__String__Sequence__fini(&msg->id);
}

bool
motpy_pifpaf_msg__msg__Poses__are_equal(const motpy_pifpaf_msg__msg__Poses * lhs, const motpy_pifpaf_msg__msg__Poses * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // poses
  if (!motpy_pifpaf_msg__msg__Pose__Sequence__are_equal(
      &(lhs->poses), &(rhs->poses)))
  {
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->id), &(rhs->id)))
  {
    return false;
  }
  return true;
}

bool
motpy_pifpaf_msg__msg__Poses__copy(
  const motpy_pifpaf_msg__msg__Poses * input,
  motpy_pifpaf_msg__msg__Poses * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // poses
  if (!motpy_pifpaf_msg__msg__Pose__Sequence__copy(
      &(input->poses), &(output->poses)))
  {
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->id), &(output->id)))
  {
    return false;
  }
  return true;
}

motpy_pifpaf_msg__msg__Poses *
motpy_pifpaf_msg__msg__Poses__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motpy_pifpaf_msg__msg__Poses * msg = (motpy_pifpaf_msg__msg__Poses *)allocator.allocate(sizeof(motpy_pifpaf_msg__msg__Poses), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(motpy_pifpaf_msg__msg__Poses));
  bool success = motpy_pifpaf_msg__msg__Poses__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
motpy_pifpaf_msg__msg__Poses__destroy(motpy_pifpaf_msg__msg__Poses * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    motpy_pifpaf_msg__msg__Poses__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
motpy_pifpaf_msg__msg__Poses__Sequence__init(motpy_pifpaf_msg__msg__Poses__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motpy_pifpaf_msg__msg__Poses * data = NULL;

  if (size) {
    data = (motpy_pifpaf_msg__msg__Poses *)allocator.zero_allocate(size, sizeof(motpy_pifpaf_msg__msg__Poses), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = motpy_pifpaf_msg__msg__Poses__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        motpy_pifpaf_msg__msg__Poses__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
motpy_pifpaf_msg__msg__Poses__Sequence__fini(motpy_pifpaf_msg__msg__Poses__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      motpy_pifpaf_msg__msg__Poses__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

motpy_pifpaf_msg__msg__Poses__Sequence *
motpy_pifpaf_msg__msg__Poses__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motpy_pifpaf_msg__msg__Poses__Sequence * array = (motpy_pifpaf_msg__msg__Poses__Sequence *)allocator.allocate(sizeof(motpy_pifpaf_msg__msg__Poses__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = motpy_pifpaf_msg__msg__Poses__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
motpy_pifpaf_msg__msg__Poses__Sequence__destroy(motpy_pifpaf_msg__msg__Poses__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    motpy_pifpaf_msg__msg__Poses__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
motpy_pifpaf_msg__msg__Poses__Sequence__are_equal(const motpy_pifpaf_msg__msg__Poses__Sequence * lhs, const motpy_pifpaf_msg__msg__Poses__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!motpy_pifpaf_msg__msg__Poses__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
motpy_pifpaf_msg__msg__Poses__Sequence__copy(
  const motpy_pifpaf_msg__msg__Poses__Sequence * input,
  motpy_pifpaf_msg__msg__Poses__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(motpy_pifpaf_msg__msg__Poses);
    motpy_pifpaf_msg__msg__Poses * data =
      (motpy_pifpaf_msg__msg__Poses *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!motpy_pifpaf_msg__msg__Poses__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          motpy_pifpaf_msg__msg__Poses__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!motpy_pifpaf_msg__msg__Poses__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
