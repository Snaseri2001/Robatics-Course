// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/FirstMsgMessage.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__FIRST_MSG_MESSAGE__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__FIRST_MSG_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/first_msg_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_FirstMsgMessage_message
{
public:
  Init_FirstMsgMessage_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::msg::FirstMsgMessage message(::interfaces::msg::FirstMsgMessage::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::FirstMsgMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::FirstMsgMessage>()
{
  return interfaces::msg::builder::Init_FirstMsgMessage_message();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__FIRST_MSG_MESSAGE__BUILDER_HPP_
