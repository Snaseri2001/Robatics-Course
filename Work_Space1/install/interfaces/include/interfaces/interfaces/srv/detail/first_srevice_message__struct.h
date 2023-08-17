// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:srv/FirstSreviceMessage.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__FIRST_SREVICE_MESSAGE__STRUCT_H_
#define INTERFACES__SRV__DETAIL__FIRST_SREVICE_MESSAGE__STRUCT_H_

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

/// Struct defined in srv/FirstSreviceMessage in the package interfaces.
typedef struct interfaces__srv__FirstSreviceMessage_Request
{
  rosidl_runtime_c__String message;
  int64_t len;
} interfaces__srv__FirstSreviceMessage_Request;

// Struct for a sequence of interfaces__srv__FirstSreviceMessage_Request.
typedef struct interfaces__srv__FirstSreviceMessage_Request__Sequence
{
  interfaces__srv__FirstSreviceMessage_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__srv__FirstSreviceMessage_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/FirstSreviceMessage in the package interfaces.
typedef struct interfaces__srv__FirstSreviceMessage_Response
{
  int64_t result;
} interfaces__srv__FirstSreviceMessage_Response;

// Struct for a sequence of interfaces__srv__FirstSreviceMessage_Response.
typedef struct interfaces__srv__FirstSreviceMessage_Response__Sequence
{
  interfaces__srv__FirstSreviceMessage_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__srv__FirstSreviceMessage_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__SRV__DETAIL__FIRST_SREVICE_MESSAGE__STRUCT_H_
