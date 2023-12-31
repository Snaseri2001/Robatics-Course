#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ros_gz_sim::ros_gz_sim" for configuration ""
set_property(TARGET ros_gz_sim::ros_gz_sim APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(ros_gz_sim::ros_gz_sim PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libros_gz_sim.so"
  IMPORTED_SONAME_NOCONFIG "libros_gz_sim.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS ros_gz_sim::ros_gz_sim )
list(APPEND _IMPORT_CHECK_FILES_FOR_ros_gz_sim::ros_gz_sim "${_IMPORT_PREFIX}/lib/libros_gz_sim.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
