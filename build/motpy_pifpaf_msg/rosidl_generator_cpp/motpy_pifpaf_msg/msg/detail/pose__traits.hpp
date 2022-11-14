// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from motpy_pifpaf_msg:msg/Pose.idl
// generated code does not contain a copyright notice

#ifndef MOTPY_PIFPAF_MSG__MSG__DETAIL__POSE__TRAITS_HPP_
#define MOTPY_PIFPAF_MSG__MSG__DETAIL__POSE__TRAITS_HPP_

#include "motpy_pifpaf_msg/msg/detail/pose__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<motpy_pifpaf_msg::msg::Pose>()
{
  return "motpy_pifpaf_msg::msg::Pose";
}

template<>
inline const char * name<motpy_pifpaf_msg::msg::Pose>()
{
  return "motpy_pifpaf_msg/msg/Pose";
}

template<>
struct has_fixed_size<motpy_pifpaf_msg::msg::Pose>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<motpy_pifpaf_msg::msg::Pose>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<motpy_pifpaf_msg::msg::Pose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOTPY_PIFPAF_MSG__MSG__DETAIL__POSE__TRAITS_HPP_
