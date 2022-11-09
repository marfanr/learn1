# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_myrvis_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED myrvis_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(myrvis_FOUND FALSE)
  elseif(NOT myrvis_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(myrvis_FOUND FALSE)
  endif()
  return()
endif()
set(_myrvis_CONFIG_INCLUDED TRUE)

# output package information
if(NOT myrvis_FIND_QUIETLY)
  message(STATUS "Found myrvis: 0.0.0 (${myrvis_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'myrvis' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${myrvis_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(myrvis_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${myrvis_DIR}/${_extra}")
endforeach()
