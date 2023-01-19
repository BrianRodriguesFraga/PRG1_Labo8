cmake_minimum_required(VERSION 3.23)
project(TP8)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(TP8 main.cpp display.cpp engagementRules.cpp input.cpp random.cpp snakes.cpp snakes.cpp)

target_link_libraries(
        TP8
        ${SDL2_LIBRARIES}
)