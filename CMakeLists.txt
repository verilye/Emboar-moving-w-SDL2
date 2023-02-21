cmake_minimum_required(VERSION 3.0.0)
project(BarbarianBlood VERSION 0.1.0)

find_package(SDL2 REQUIRED)
include_directories(BarbarianBlood ${SDL2_INCLUDE_DIRS})

include(CTest)
enable_testing()

add_executable(BarbarianBlood main.cpp)
target_link_libraries(BarbarianBlood ${SDL2_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
