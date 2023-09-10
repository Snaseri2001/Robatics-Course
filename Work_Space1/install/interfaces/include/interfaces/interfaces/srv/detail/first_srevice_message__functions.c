// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interfaces:srv/FirstSreviceMessage.idl
// generated code does not contain a copyright notice
#include "interfaces/srv/detail/first_srevice_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
interfaces__srv__FirstSreviceMessage_Request__init(interfaces__srv__FirstSreviceMessage_Request * msg)
{
  if (!msg) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    interfaces__srv__FirstSreviceMessage_Request__fini(msg);
    return false;
  }
  // len
  return true;
}

void
interfaces__srv__FirstSreviceMessage_Request__fini(interfaces__srv__FirstSreviceMessage_Request * msg)
{
  if (!msg) {
    return;
  }
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // len
}

bool
interfaces__srv__FirstSreviceMessage_Request__are_equal(const interfaces__srv__FirstSreviceMessage_Request * lhs, const interfaces__srv__FirstSreviceMessage_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  // len
  if (lhs->len != rhs->len) {
    return false;
  }
  return true;
}

bool
interfaces__srv__FirstSreviceMessage_Request__copy(
  const interfaces__srv__FirstSreviceMessage_Request * input,
  interfaces__srv__FirstSreviceMessage_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  // len
  output->len = input->len;
  return true;
}

interfaces__srv__FirstSreviceMessage_Request *
interfaces__srv__FirstSreviceMessage_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__srv__FirstSreviceMessage_Request * msg = (interfaces__srv__FirstSreviceMessage_Request *)allocator.allocate(sizeof(interfaces__srv__FirstSreviceMessage_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__srv__FirstSreviceMessage_Request));
  bool success = interfaces__srv__FirstSreviceMessage_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__srv__FirstSreviceMessage_Request__destroy(interfaces__srv__FirstSreviceMessage_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__srv__FirstSreviceMessage_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__srv__FirstSreviceMessage_Request__Sequence__init(interfaces__srv__FirstSreviceMessage_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__srv__FirstSreviceMessage_Request * data = NULL;

  if (size) {
    data = (interfaces__srv__FirstSreviceMessage_Request *)allocator.zero_allocate(size, sizeof(interfaces__srv__FirstSreviceMessage_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__srv__FirstSreviceMessage_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__srv__FirstSreviceMessage_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
interfaces__srv__FirstSreviceMessage_Request__Sequence__fini(interfaces__srv__FirstSreviceMessage_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__srv__FirstSreviceMessage_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

interfaces__srv__FirstSreviceMessage_Request__Sequence *
interfaces__srv__FirstSreviceMessage_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__srv__FirstSreviceMessage_Request__Sequence * array = (interfaces__srv__FirstSreviceMessage_Request__Sequence *)allocator.allocate(sizeof(interfaces__srv__FirstSreviceMessage_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__srv__FirstSreviceMessage_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__srv__FirstSreviceMessage_Request__Sequence__destroy(interfaces__srv__FirstSreviceMessage_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__srv__FirstSreviceMessage_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__srv__FirstSreviceMessage_Request__Sequence__are_equal(const interfaces__srv__FirstSreviceMessage_Request__Sequence * lhs, const interfaces__srv__FirstSreviceMessage_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__srv__FirstSreviceMessage_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__srv__FirstSreviceMessage_Request__Sequence__copy(
  const interfaces__srv__FirstSreviceMessage_Request__Sequence * input,
  interfaces__srv__FirstSreviceMessage_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__srv__FirstSreviceMessage_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interfaces__srv__FirstSreviceMessage_Request * data =
      (interfaces__srv__FirstSreviceMessage_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__srv__FirstSreviceMessage_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interfaces__srv__FirstSreviceMessage_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__srv__FirstSreviceMessage_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
interfaces__srv__FirstSreviceMessage_Response__init(interfaces__srv__FirstSreviceMessage_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  return true;
}

void
interfaces__srv__FirstSreviceMessage_Response__fini(interfaces__srv__FirstSreviceMessage_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
}

bool
interfaces__srv__FirstSreviceMessage_Response__are_equal(const interfaces__srv__FirstSreviceMessage_Response * lhs, const interfaces__srv__FirstSreviceMessage_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (lhs->result != rhs->result) {
    return false;
  }
  return true;
}

bool
interfaces__srv__FirstSreviceMessage_Response__copy(
  const interfaces__srv__FirstSreviceMessage_Response * input,
  interfaces__srv__FirstSreviceMessage_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  output->result = input->result;
  return true;
}

interfaces__srv__FirstSreviceMessage_Response *
interfaces__srv__FirstSreviceMessage_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__srv__FirstSreviceMessage_Response * msg = (interfaces__srv__FirstSreviceMessage_Response *)allocator.allocate(sizeof(interfaces__srv__FirstSreviceMessage_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__srv__FirstSreviceMessage_Response));
  bool success = interfaces__srv__FirstSreviceMessage_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__srv__FirstSreviceMessage_Response__destroy(interfaces__srv__FirstSreviceMessage_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__srv__FirstSreviceMessage_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__srv__FirstSreviceMessage_Response__Sequence__init(interfaces__srv__FirstSreviceMessage_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__srv__FirstSreviceMessage_Response * data = NULL;

  if (size) {
    data = (interfaces__srv__FirstSreviceMessage_Response *)allocator.zero_allocate(size, sizeof(interfaces__srv__FirstSreviceMessage_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__srv__FirstSreviceMessage_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__srv__FirstSreviceMessage_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
interfaces__srv__FirstSreviceMessage_Response__Sequence__fini(interfaces__srv__FirstSreviceMessage_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__srv__FirstSreviceMessage_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

interfaces__srv__FirstSreviceMessage_Response__Sequence *
interfaces__srv__FirstSreviceMessage_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__srv__FirstSreviceMessage_Response__Sequence * array = (interfaces__srv__FirstSreviceMessage_Response__Sequence *)allocator.allocate(sizeof(interfaces__srv__FirstSreviceMessage_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__srv__FirstSreviceMessage_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__srv__FirstSreviceMessage_Response__Sequence__destroy(interfaces__srv__FirstSreviceMessage_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__srv__FirstSreviceMessage_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__srv__FirstSreviceMessage_Response__Sequence__are_equal(const interfaces__srv__FirstSreviceMessage_Response__Sequence * lhs, const interfaces__srv__FirstSreviceMessage_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__srv__FirstSreviceMessage_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__srv__FirstSreviceMessage_Response__Sequence__copy(
  const interfaces__srv__FirstSreviceMessage_Response__Sequence * input,
  interfaces__srv__FirstSreviceMessage_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__srv__FirstSreviceMessage_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interfaces__srv__FirstSreviceMessage_Response * data =
      (interfaces__srv__FirstSreviceMessage_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__srv__FirstSreviceMessage_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interfaces__srv__FirstSreviceMessage_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__srv__FirstSreviceMessage_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}