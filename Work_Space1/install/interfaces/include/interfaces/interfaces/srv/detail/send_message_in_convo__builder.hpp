// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/SendMessageInConvo.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__SEND_MESSAGE_IN_CONVO__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__SEND_MESSAGE_IN_CONVO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/srv/detail/send_message_in_convo__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_SendMessageInConvo_Request_len
{
public:
  explicit Init_SendMessageInConvo_Request_len(::interfaces::srv::SendMessageInConvo_Request & msg)
  : msg_(msg)
  {}
  ::interfaces::srv::SendMessageInConvo_Request len(::interfaces::srv::SendMessageInConvo_Request::_len_type arg)
  {
    msg_.len = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::SendMessageInConvo_Request msg_;
};

class Init_SendMessageInConvo_Request_message
{
public:
  Init_SendMessageInConvo_Request_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SendMessageInConvo_Request_len message(::interfaces::srv::SendMessageInConvo_Request::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_SendMessageInConvo_Request_len(msg_);
  }

private:
  ::interfaces::srv::SendMessageInConvo_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::SendMessageInConvo_Request>()
{
  return interfaces::srv::builder::Init_SendMessageInConvo_Request_message();
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_SendMessageInConvo_Response_result
{
public:
  Init_SendMessageInConvo_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::SendMessageInConvo_Response result(::interfaces::srv::SendMessageInConvo_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::SendMessageInConvo_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::SendMessageInConvo_Response>()
{
  return interfaces::srv::builder::Init_SendMessageInConvo_Response_result();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__SEND_MESSAGE_IN_CONVO__BUILDER_HPP_
