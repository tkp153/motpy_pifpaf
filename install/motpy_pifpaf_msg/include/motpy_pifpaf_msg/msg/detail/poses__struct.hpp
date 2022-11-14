// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from motpy_pifpaf_msg:msg/Poses.idl
// generated code does not contain a copyright notice

#ifndef MOTPY_PIFPAF_MSG__MSG__DETAIL__POSES__STRUCT_HPP_
#define MOTPY_PIFPAF_MSG__MSG__DETAIL__POSES__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'poses'
#include "motpy_pifpaf_msg/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__motpy_pifpaf_msg__msg__Poses __attribute__((deprecated))
#else
# define DEPRECATED__motpy_pifpaf_msg__msg__Poses __declspec(deprecated)
#endif

namespace motpy_pifpaf_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Poses_
{
  using Type = Poses_<ContainerAllocator>;

  explicit Poses_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = "";
    }
  }

  explicit Poses_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _poses_type =
    std::vector<motpy_pifpaf_msg::msg::Pose_<ContainerAllocator>, typename ContainerAllocator::template rebind<motpy_pifpaf_msg::msg::Pose_<ContainerAllocator>>::other>;
  _poses_type poses;
  using _id_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _id_type id;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__poses(
    const std::vector<motpy_pifpaf_msg::msg::Pose_<ContainerAllocator>, typename ContainerAllocator::template rebind<motpy_pifpaf_msg::msg::Pose_<ContainerAllocator>>::other> & _arg)
  {
    this->poses = _arg;
    return *this;
  }
  Type & set__id(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    motpy_pifpaf_msg::msg::Poses_<ContainerAllocator> *;
  using ConstRawPtr =
    const motpy_pifpaf_msg::msg::Poses_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<motpy_pifpaf_msg::msg::Poses_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<motpy_pifpaf_msg::msg::Poses_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      motpy_pifpaf_msg::msg::Poses_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<motpy_pifpaf_msg::msg::Poses_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      motpy_pifpaf_msg::msg::Poses_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<motpy_pifpaf_msg::msg::Poses_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<motpy_pifpaf_msg::msg::Poses_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<motpy_pifpaf_msg::msg::Poses_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__motpy_pifpaf_msg__msg__Poses
    std::shared_ptr<motpy_pifpaf_msg::msg::Poses_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__motpy_pifpaf_msg__msg__Poses
    std::shared_ptr<motpy_pifpaf_msg::msg::Poses_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Poses_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->poses != other.poses) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    return true;
  }
  bool operator!=(const Poses_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Poses_

// alias to use template instance with default allocator
using Poses =
  motpy_pifpaf_msg::msg::Poses_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace motpy_pifpaf_msg

#endif  // MOTPY_PIFPAF_MSG__MSG__DETAIL__POSES__STRUCT_HPP_
