cmake_minimum_required(VERSION 3.10)
project(cpp_server)

set(CMAKE_CXX_STANDARD 11)
find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

include_directories(src/protobuf)
include_directories(src/server)

add_executable(cpp_server
        src/protobuf/event.pb.cc
        src/protobuf/event.pb.h
        src/server/socket_server.cpp
        src/server/socket_server.h
        src/main.cpp)

target_link_libraries(cpp_server ${Protobuf_LIBRARIES})