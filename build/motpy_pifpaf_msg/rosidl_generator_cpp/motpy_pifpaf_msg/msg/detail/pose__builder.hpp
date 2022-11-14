// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from motpy_pifpaf_msg:msg/Pose.idl
// generated code does not contain a copyright notice

#ifndef MOTPY_PIFPAF_MSG__MSG__DETAIL__POSE__BUILDER_HPP_
#define MOTPY_PIFPAF_MSG__MSG__DETAIL__POSE__BUILDER_HPP_

#include "motpy_pifpaf_msg/msg/detail/pose__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace motpy_pifpaf_msg
{

namespace msg
{

namespace builder
{

class Init_Pose_keypoints
{
public:
  Init_Pose_keypoints()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::motpy_pifpaf_msg::msg::Pose keypoints(::motpy_pifpaf_msg::msg::Pose::_keypoints_type arg)
  {
    msg_.keypoints = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motpy_pifpaf_msg::msg::Pose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::motpy_pifpaf_msg::msg::Pose>()
{
  return motpy_pifpaf_msg::msg::builder::Init_Pose_keypoints();
}

}  // namespace motpy_pifpaf_msg

#endif  // MOTPY_PIFPAF_MSG__MSG__DETAIL__POSE__BUILDER_HPP_
