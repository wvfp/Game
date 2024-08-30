cmake_minimum_required(VERSION 3.12)

project(OpenGL)

set(CMAKE_CXX_STANDARD 17)

#list(APPEND compile_flag "-Wall" "-O3")

#target_compile_options(OpenGL PUBLIC "-lglfw3")

file(GLOB RES "./res" )

file(COPY ${RES} DESTINATION ${CMAKE_BINARY_DIR})

#include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/Dependences/include)

#link_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/Dependences/lib)
link_libraries(glfw3)

add_executable(OpenGL "src/main.cpp" "src/glad.c")


