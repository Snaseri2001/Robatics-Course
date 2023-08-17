# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_yangsim_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED yangsim_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(yangsim_FOUND FALSE)
  elseif(NOT yangsim_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(yangsim_FOUND FALSE)
  endif()
  return()
endif()
set(_yangsim_CONFIG_INCLUDED TRUE)

# output package information
if(NOT yangsim_FIND_QUIETLY)
  message(STATUS "Found yangsim: 0.0.0 (${yangsim_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'yangsim' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${yangsim_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(yangsim_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${yangsim_DIR}/${_extra}")
endforeach()
