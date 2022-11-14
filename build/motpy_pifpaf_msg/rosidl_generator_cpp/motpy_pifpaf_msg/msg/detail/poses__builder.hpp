// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from motpy_pifpaf_msg:msg/Poses.idl
// generated code does not contain a copyright notice

#ifndef MOTPY_PIFPAF_MSG__MSG__DETAIL__POSES__BUILDER_HPP_
#define MOTPY_PIFPAF_MSG__MSG__DETAIL__POSES__BUILDER_HPP_

#include "motpy_pifpaf_msg/msg/detail/poses__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace motpy_pifpaf_msg
{

namespace msg
{

namespace builder
{

class Init_Poses_id
{
public:
  explicit Init_Poses_id(::motpy_pifpaf_msg::msg::Poses & msg)
  : msg_(msg)
  {}
  ::motpy_pifpaf_msg::msg::Poses id(::motpy_pifpaf_msg::msg::Poses::_id_type arg)
  {
    msg_.id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motpy_pifpaf_msg::msg::Poses msg_;
};

class Init_Poses_poses
{
public:
  explicit Init_Poses_poses(::motpy_pifpaf_msg::msg::Poses & msg)
  : msg_(msg)
  {}
  Init_Poses_id poses(::motpy_pifpaf_msg::msg::Poses::_poses_type arg)
  {
    msg_.poses = std::move(arg);
    return Init_Poses_id(msg_);
  }

private:
  ::motpy_pifpaf_msg::msg::Poses msg_;
};

class Init_Poses_header
{
public:
  Init_Poses_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Poses_poses header(::motpy_pifpaf_msg::msg::Poses::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Poses_poses(msg_);
  }

private:
  ::motpy_pifpaf_msg::msg::Poses msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::motpy_pifpaf_msg::msg::Poses>()
{
  return motpy_pifpaf_msg::msg::builder::Init_Poses_header();
}

}  // namespace motpy_pifpaf_msg

#endif  // MOTPY_PIFPAF_MSG__MSG__DETAIL__POSES__BUILDER_HPP_
