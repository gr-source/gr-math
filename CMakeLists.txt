cmake_minimum_required(VERSION 3.0.0)
project(gr-math VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

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
    src/gmath.h
    src/types.h
    src/vector2.h
    src/vector3.h
    src/vector4.h
    src/matrix3x3.h
    src/matrix4x4.h
    src/quaternion.h
)

add_library(gr-math SHARED ${math_src})

if(NOT DISABLE_INSTALL)
    install(TARGETS gr-math
        EXPORT gr-mathTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
    )

    install(FILES ${math_hdr}
        DESTINATION include/gr-math
    )

    install(EXPORT gr-mathTargets
        FILE gr-mathTargets.cmake
        NAMESPACE gr-math::
        DESTINATION lib/cmake/gr-math
    )

    include(CMakePackageConfigHelpers)

    write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/gr-mathConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
    )

    install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/gr-mathConfigVersion.cmake" DESTINATION lib/cmake/gr-math
    )
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
