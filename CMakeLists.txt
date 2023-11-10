cmake_minimum_required(VERSION 3.27)
project(friend_graph)

set(CMAKE_CXX_STANDARD 23)
add_executable(friend_graph main.cpp
        Node.cpp
        Node.h
        Edge.cpp
        Edge.h
)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(friend_graph PRIVATE nlohmann_json::nlohmann_json)