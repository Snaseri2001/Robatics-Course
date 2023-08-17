// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:srv/FirstSreviceMessage.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__FIRST_SREVICE_MESSAGE__STRUCT_HPP_
#define INTERFACES__SRV__DETAIL__FIRST_SREVICE_MESSAGE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__srv__FirstSreviceMessage_Request __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__FirstSreviceMessage_Request __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FirstSreviceMessage_Request_
{
  using Type = FirstSreviceMessage_Request_<ContainerAllocator>;

  explicit FirstSreviceMessage_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
      this->len = 0ll;
    }
  }

  explicit FirstSreviceMessage_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
      this->len = 0ll;
    }
  }

  // field types and members
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _len_type =
    int64_t;
  _len_type len;

  // setters for named parameter idiom
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__len(
    const int64_t & _arg)
  {
    this->len = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::srv::FirstSreviceMessage_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::FirstSreviceMessage_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::FirstSreviceMessage_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::FirstSreviceMessage_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::FirstSreviceMessage_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::FirstSreviceMessage_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::FirstSreviceMessage_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::FirstSreviceMessage_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::FirstSreviceMessage_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::FirstSreviceMessage_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__FirstSreviceMessage_Request
    std::shared_ptr<interfaces::srv::FirstSreviceMessage_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__FirstSreviceMessage_Request
    std::shared_ptr<interfaces::srv::FirstSreviceMessage_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FirstSreviceMessage_Request_ & other) const
  {
    if (this->message != other.message) {
      return false;
    }
    if (this->len != other.len) {
      return false;
    }
    return true;
  }
  bool operator!=(const FirstSreviceMessage_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FirstSreviceMessage_Request_

// alias to use template instance with default allocator
using FirstSreviceMessage_Request =
  interfaces::srv::FirstSreviceMessage_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces


#ifndef _WIN32
# define DEPRECATED__interfaces__srv__FirstSreviceMessage_Response __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__FirstSreviceMessage_Response __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FirstSreviceMessage_Response_
{
  using Type = FirstSreviceMessage_Response_<ContainerAllocator>;

  explicit FirstSreviceMessage_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = 0ll;
    }
  }

  explicit FirstSreviceMessage_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = 0ll;
    }
  }

  // field types and members
  using _result_type =
    int64_t;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const int64_t & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::srv::FirstSreviceMessage_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::FirstSreviceMessage_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::FirstSreviceMessage_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::FirstSreviceMessage_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::FirstSreviceMessage_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::FirstSreviceMessage_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::FirstSreviceMessage_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::FirstSreviceMessage_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::FirstSreviceMessage_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::FirstSreviceMessage_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__FirstSreviceMessage_Response
    std::shared_ptr<interfaces::srv::FirstSreviceMessage_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__FirstSreviceMessage_Response
    std::shared_ptr<interfaces::srv::FirstSreviceMessage_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FirstSreviceMessage_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const FirstSreviceMessage_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FirstSreviceMessage_Response_

// alias to use template instance with default allocator
using FirstSreviceMessage_Response =
  interfaces::srv::FirstSreviceMessage_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces

namespace interfaces
{

namespace srv
{

struct FirstSreviceMessage
{
  using Request = interfaces::srv::FirstSreviceMessage_Request;
  using Response = interfaces::srv::FirstSreviceMessage_Response;
};

}  // namespace srv

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__FIRST_SREVICE_MESSAGE__STRUCT_HPP_
