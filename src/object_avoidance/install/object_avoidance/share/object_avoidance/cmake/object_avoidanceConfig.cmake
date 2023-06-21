# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_object_avoidance_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED object_avoidance_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(object_avoidance_FOUND FALSE)
  elseif(NOT object_avoidance_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(object_avoidance_FOUND FALSE)
  endif()
  return()
endif()
set(_object_avoidance_CONFIG_INCLUDED TRUE)

# output package information
if(NOT object_avoidance_FIND_QUIETLY)
  message(STATUS "Found object_avoidance: 0.0.0 (${object_avoidance_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'object_avoidance' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${object_avoidance_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(object_avoidance_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${object_avoidance_DIR}/${_extra}")
endforeach()
