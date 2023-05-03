set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/build/CMakeFiles")

cmake_minimum_required(VERSION 3.0.0)
project(BarbarianBlood VERSION 0.1.0)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(BarbarianBlood ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

include(CTest)
enable_testing()

add_executable(BarbarianBlood main.cpp Application.cpp Emboar.cpp)
target_link_libraries(BarbarianBlood ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
