// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from motpy_pifpaf_msg:msg/Poses.idl
// generated code does not contain a copyright notice

#ifndef MOTPY_PIFPAF_MSG__MSG__DETAIL__POSES__TRAITS_HPP_
#define MOTPY_PIFPAF_MSG__MSG__DETAIL__POSES__TRAITS_HPP_

#include "motpy_pifpaf_msg/msg/detail/poses__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<motpy_pifpaf_msg::msg::Poses>()
{
  return "motpy_pifpaf_msg::msg::Poses";
}

template<>
inline const char * name<motpy_pifpaf_msg::msg::Poses>()
{
  return "motpy_pifpaf_msg/msg/Poses";
}

template<>
struct has_fixed_size<motpy_pifpaf_msg::msg::Poses>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<motpy_pifpaf_msg::msg::Poses>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<motpy_pifpaf_msg::msg::Poses>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOTPY_PIFPAF_MSG__MSG__DETAIL__POSES__TRAITS_HPP_
