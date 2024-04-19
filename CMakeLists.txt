cmake_minimum_required(VERSION 3.0.0)
project(gr-math VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)


set(math_src

    src/math.cpp
    
    src/vector3.cpp
    src/vector2.cpp
    src/vector4.cpp
    
    src/matrix3x3.cpp
    src/matrix4x4.cpp
    
    src/quaternion.cpp
    )
    
set(math_hdr

    src/math.h

    src/vector2.h
    src/vector3.h
    src/vector4.h

    src/matrix3x3.h
    src/matrix4x4.h
    
    src/quaternion.h
)
    
add_library(gr-math SHARED ${math_src})
    
if(NOT DISABLE_INSTALL)
    install(TARGETS gr-math DESTINATION /usr/local/lib/gr-math)

    install(FILES ${math_hdr} DESTINATION /usr/local/include/gr-math)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
    