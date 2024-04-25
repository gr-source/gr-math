#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gr-math::gr-math" for configuration "Debug"
set_property(TARGET gr-math::gr-math APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(gr-math::gr-math PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/gr-math/libgr-math.so"
  IMPORTED_SONAME_DEBUG "libgr-math.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS gr-math::gr-math )
list(APPEND _IMPORT_CHECK_FILES_FOR_gr-math::gr-math "${_IMPORT_PREFIX}/lib/gr-math/libgr-math.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
