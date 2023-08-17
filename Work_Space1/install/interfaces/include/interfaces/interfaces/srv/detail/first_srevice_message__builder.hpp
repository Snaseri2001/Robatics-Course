// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/FirstSreviceMessage.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__FIRST_SREVICE_MESSAGE__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__FIRST_SREVICE_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/srv/detail/first_srevice_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_FirstSreviceMessage_Request_len
{
public:
  explicit Init_FirstSreviceMessage_Request_len(::interfaces::srv::FirstSreviceMessage_Request & msg)
  : msg_(msg)
  {}
  ::interfaces::srv::FirstSreviceMessage_Request len(::interfaces::srv::FirstSreviceMessage_Request::_len_type arg)
  {
    msg_.len = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::FirstSreviceMessage_Request msg_;
};

class Init_FirstSreviceMessage_Request_message
{
public:
  Init_FirstSreviceMessage_Request_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FirstSreviceMessage_Request_len message(::interfaces::srv::FirstSreviceMessage_Request::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_FirstSreviceMessage_Request_len(msg_);
  }

private:
  ::interfaces::srv::FirstSreviceMessage_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::FirstSreviceMessage_Request>()
{
  return interfaces::srv::builder::Init_FirstSreviceMessage_Request_message();
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_FirstSreviceMessage_Response_result
{
public:
  Init_FirstSreviceMessage_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::FirstSreviceMessage_Response result(::interfaces::srv::FirstSreviceMessage_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::FirstSreviceMessage_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::FirstSreviceMessage_Response>()
{
  return interfaces::srv::builder::Init_FirstSreviceMessage_Response_result();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__FIRST_SREVICE_MESSAGE__BUILDER_HPP_
