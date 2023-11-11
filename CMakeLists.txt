cmake_minimum_required(VERSION 3.27)
project(friend_graph)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_PREFIX_PATH "/usr/lib64/qt6/bin/qt-cmake")
set(CMAKE_AUTOMOC ON)
add_executable(friend_graph source/main.cpp
        source/Node.cpp
        headers/Node.h
        source/Edge.cpp
        headers/Edge.h
        source/Graph.cpp
        headers/Graph.h
        source/GraphWidget.cpp
        headers/GraphWidget.h
)

find_package(nlohmann_json CONFIG REQUIRED)
find_package(Qt6Widgets REQUIRED)
target_link_libraries(friend_graph PRIVATE Qt6::Widgets nlohmann_json::nlohmann_json)