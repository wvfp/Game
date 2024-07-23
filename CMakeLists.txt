cmake_minimum_required(VERSION 3.12)

project(SDL_Project)

set(CMAKE_CXX_STANDARD 17)

file(GLOB RES "./res" )

file(COPY ${RES} DESTINATION ${CMAKE_BINARY_DIR})

include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/Dependences/include)


include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/Application)

link_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/Dependences/lib)
add_subdirectory(Application)

add_executable(SDL_Project "./src/mainApplication.cpp")

target_link_libraries(SDL_Project SDL2main SDL2 SDL2_test app SDL2_image SDL2_ttf  )
