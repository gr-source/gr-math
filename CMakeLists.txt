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
    include/gmath.h
    include/types.h
    include/vector2.h
    include/vector3.h
    include/vector4.h
    include/matrix3x3.h
    include/matrix4x4.h
    include/quaternion.h
)

add_library(gr-math SHARED ${math_src})

if(NOT DISABLE_INSTALL)
    install(TARGETS gr-math
        EXPORT gr-mathTargets
        LIBRARY DESTINATION lib/gr-math
        ARCHIVE DESTINATION lib/gr-math
        RUNTIME DESTINATION bin/gr-math
        INCLUDES DESTINATION include/gr-math
    )

    install(FILES ${math_hdr}
        DESTINATION include/gr-math
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

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
