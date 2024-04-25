
set(gr-mathInstall OFF)
#include(${CMAKE_CURRENT_LIST_DIR}/gr-mathDependencies.cmake)

# Our library dependencies (contains definitions for IMPORTED targets)
include(${CMAKE_CURRENT_LIST_DIR}/gr-mathTargets.cmake)


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was Config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

#set_and_check(gr-math_INCLUDE_DIRS "${CMAKE_INSTALL_PREFIX}/include")
#set_and_check(gr-math_LIB_DIR "")
check_required_components(gr-math)

# Set found status
set(gr-math_FOUND TRUE) 
#set(gr-math_INCLUDE_DIRS ${gr-math_INCLUDE_DIRS} ${INCLUDE_DIRS})
#set(gr-math_LIBRARY_DIRS ${gr-math_LIB_DIR} ${LIBRARY_DIRS})
set(GRMATH_LIBRARIES /usr/local/lib/gr-math/libgr-math.so)
