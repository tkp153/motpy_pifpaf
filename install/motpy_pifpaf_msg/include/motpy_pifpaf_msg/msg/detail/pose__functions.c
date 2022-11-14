// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from motpy_pifpaf_msg:msg/Pose.idl
// generated code does not contain a copyright notice
#include "motpy_pifpaf_msg/msg/detail/pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `keypoints`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
motpy_pifpaf_msg__msg__Pose__init(motpy_pifpaf_msg__msg__Pose * msg)
{
  if (!msg) {
    return false;
  }
  // keypoints
  if (!rosidl_runtime_c__float__Sequence__init(&msg->keypoints, 0)) {
    motpy_pifpaf_msg__msg__Pose__fini(msg);
    return false;
  }
  return true;
}

void
motpy_pifpaf_msg__msg__Pose__fini(motpy_pifpaf_msg__msg__Pose * msg)
{
  if (!msg) {
    return;
  }
  // keypoints
  rosidl_runtime_c__float__Sequence__fini(&msg->keypoints);
}

bool
motpy_pifpaf_msg__msg__Pose__are_equal(const motpy_pifpaf_msg__msg__Pose * lhs, const motpy_pifpaf_msg__msg__Pose * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // keypoints
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->keypoints), &(rhs->keypoints)))
  {
    return false;
  }
  return true;
}

bool
motpy_pifpaf_msg__msg__Pose__copy(
  const motpy_pifpaf_msg__msg__Pose * input,
  motpy_pifpaf_msg__msg__Pose * output)
{
  if (!input || !output) {
    return false;
  }
  // keypoints
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->keypoints), &(output->keypoints)))
  {
    return false;
  }
  return true;
}

motpy_pifpaf_msg__msg__Pose *
motpy_pifpaf_msg__msg__Pose__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motpy_pifpaf_msg__msg__Pose * msg = (motpy_pifpaf_msg__msg__Pose *)allocator.allocate(sizeof(motpy_pifpaf_msg__msg__Pose), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(motpy_pifpaf_msg__msg__Pose));
  bool success = motpy_pifpaf_msg__msg__Pose__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
motpy_pifpaf_msg__msg__Pose__destroy(motpy_pifpaf_msg__msg__Pose * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    motpy_pifpaf_msg__msg__Pose__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
motpy_pifpaf_msg__msg__Pose__Sequence__init(motpy_pifpaf_msg__msg__Pose__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motpy_pifpaf_msg__msg__Pose * data = NULL;

  if (size) {
    data = (motpy_pifpaf_msg__msg__Pose *)allocator.zero_allocate(size, sizeof(motpy_pifpaf_msg__msg__Pose), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = motpy_pifpaf_msg__msg__Pose__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        motpy_pifpaf_msg__msg__Pose__fini(&data[i - 1]);
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
motpy_pifpaf_msg__msg__Pose__Sequence__fini(motpy_pifpaf_msg__msg__Pose__Sequence * array)
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
      motpy_pifpaf_msg__msg__Pose__fini(&array->data[i]);
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

motpy_pifpaf_msg__msg__Pose__Sequence *
motpy_pifpaf_msg__msg__Pose__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motpy_pifpaf_msg__msg__Pose__Sequence * array = (motpy_pifpaf_msg__msg__Pose__Sequence *)allocator.allocate(sizeof(motpy_pifpaf_msg__msg__Pose__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = motpy_pifpaf_msg__msg__Pose__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
motpy_pifpaf_msg__msg__Pose__Sequence__destroy(motpy_pifpaf_msg__msg__Pose__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    motpy_pifpaf_msg__msg__Pose__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
motpy_pifpaf_msg__msg__Pose__Sequence__are_equal(const motpy_pifpaf_msg__msg__Pose__Sequence * lhs, const motpy_pifpaf_msg__msg__Pose__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!motpy_pifpaf_msg__msg__Pose__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
motpy_pifpaf_msg__msg__Pose__Sequence__copy(
  const motpy_pifpaf_msg__msg__Pose__Sequence * input,
  motpy_pifpaf_msg__msg__Pose__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(motpy_pifpaf_msg__msg__Pose);
    motpy_pifpaf_msg__msg__Pose * data =
      (motpy_pifpaf_msg__msg__Pose *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!motpy_pifpaf_msg__msg__Pose__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          motpy_pifpaf_msg__msg__Pose__fini(&data[i]);
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
    if (!motpy_pifpaf_msg__msg__Pose__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
