
cmake_minimum_required(VERSION 3.8)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

find_package(SFML COMPONENTS graphics window system)
include_directories(${SFML_INCLUDE_DIR})

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(doodle  ${SOURCES})
target_link_libraries(doodle ${SFML_LIBRARIES})

