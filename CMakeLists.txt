cmake_minimum_required(VERSION 3.0.0)
project(gr-math VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

option(GR_COMPILE_LINUX "Compile on Linux" ON)
option(GR_COMPILE_STATIC_LIBRARY "Compile static library" OFF)

set(math_src
    src/gmath.cpp
    src/vector3.cpp
    src/vector2.cpp
    src/vector4.cpp
    src/matrix3x3.cpp
    src/matrix4x4.cpp
    src/quaternion.cpp
)

set(math_hdr
    include/${PROJECT_NAME}/gmath.h
    include/${PROJECT_NAME}/types.h
    include/${PROJECT_NAME}/vector2.h
    include/${PROJECT_NAME}/vector3.h
    include/${PROJECT_NAME}/vector4.h
    include/${PROJECT_NAME}/gVector2.hpp
    include/${PROJECT_NAME}/matrix3x3.h
    include/${PROJECT_NAME}/matrix4x4.h
    include/${PROJECT_NAME}/quaternion.h
)

if(GR_COMPILE_STATIC_LIBRARY)
    add_library(gr-math STATIC ${math_src})
else()
    add_library(gr-math SHARED ${math_src})
endif()
unset(GR_COMPILE_STATIC_LIBRARY CACHE)

target_include_directories(gr-math PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/gr-math>
    $<INSTALL_INTERFACE:include/gr-math>
)

if(GR_COMPILE_LINUX)
    if(NOT DISABLE_INSTALL)
        install(DIRECTORY include/gr-math
            DESTINATION include
        )

        install(TARGETS gr-math
            EXPORT gr-mathTargets
            LIBRARY DESTINATION lib/gr-math
            ARCHIVE DESTINATION lib/gr-math
            RUNTIME DESTINATION bin/gr-math
        )

        install(EXPORT gr-mathTargets
            FILE gr-mathTargets.cmake
            NAMESPACE gr-math::
            DESTINATION lib/gr-math/cmake
        )

        include(CMakePackageConfigHelpers)
        write_basic_package_version_file(
            "${CMAKE_CURRENT_BINARY_DIR}/gr-mathConfigVersion.cmake"
            VERSION ${PROJECT_VERSION}
            COMPATIBILITY SameMajorVersion
        )

        configure_package_config_file(
            "${CMAKE_CURRENT_LIST_DIR}/Config.cmake.in"
            "${CMAKE_CURRENT_BINARY_DIR}/gr-mathConfig.cmake"
            INSTALL_DESTINATION lib/cmake/gr-math
        )

        install(FILES
            "${CMAKE_CURRENT_BINARY_DIR}/gr-mathConfig.cmake"
            "${CMAKE_CURRENT_BINARY_DIR}/gr-mathConfigVersion.cmake" DESTINATION lib/gr-math/cmake
        )
    endif()
endif()
unset(GR_COMPILE_LINUX CACHE)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})


