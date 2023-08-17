// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/Conversation.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__CONVERSATION__STRUCT_H_
#define INTERFACES__MSG__DETAIL__CONVERSATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Conversation in the package interfaces.
typedef struct interfaces__msg__Conversation
{
  rosidl_runtime_c__String message;
} interfaces__msg__Conversation;

// Struct for a sequence of interfaces__msg__Conversation.
typedef struct interfaces__msg__Conversation__Sequence
{
  interfaces__msg__Conversation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__Conversation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__CONVERSATION__STRUCT_H_
