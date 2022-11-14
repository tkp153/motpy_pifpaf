// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from motpy_pifpaf_msg:msg/Pose.idl
// generated code does not contain a copyright notice

#ifndef MOTPY_PIFPAF_MSG__MSG__DETAIL__POSE__STRUCT_HPP_
#define MOTPY_PIFPAF_MSG__MSG__DETAIL__POSE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__motpy_pifpaf_msg__msg__Pose __attribute__((deprecated))
#else
# define DEPRECATED__motpy_pifpaf_msg__msg__Pose __declspec(deprecated)
#endif

namespace motpy_pifpaf_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Pose_
{
  using Type = Pose_<ContainerAllocator>;

  explicit Pose_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Pose_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _keypoints_type =
    std::vector<float, typename ContainerAllocator::template rebind<float>::other>;
  _keypoints_type keypoints;

  // setters for named parameter idiom
  Type & set__keypoints(
    const std::vector<float, typename ContainerAllocator::template rebind<float>::other> & _arg)
  {
    this->keypoints = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    motpy_pifpaf_msg::msg::Pose_<ContainerAllocator> *;
  using ConstRawPtr =
    const motpy_pifpaf_msg::msg::Pose_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<motpy_pifpaf_msg::msg::Pose_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<motpy_pifpaf_msg::msg::Pose_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      motpy_pifpaf_msg::msg::Pose_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<motpy_pifpaf_msg::msg::Pose_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      motpy_pifpaf_msg::msg::Pose_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<motpy_pifpaf_msg::msg::Pose_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<motpy_pifpaf_msg::msg::Pose_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<motpy_pifpaf_msg::msg::Pose_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__motpy_pifpaf_msg__msg__Pose
    std::shared_ptr<motpy_pifpaf_msg::msg::Pose_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__motpy_pifpaf_msg__msg__Pose
    std::shared_ptr<motpy_pifpaf_msg::msg::Pose_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Pose_ & other) const
  {
    if (this->keypoints != other.keypoints) {
      return false;
    }
    return true;
  }
  bool operator!=(const Pose_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Pose_

// alias to use template instance with default allocator
using Pose =
  motpy_pifpaf_msg::msg::Pose_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace motpy_pifpaf_msg

#endif  // MOTPY_PIFPAF_MSG__MSG__DETAIL__POSE__STRUCT_HPP_
