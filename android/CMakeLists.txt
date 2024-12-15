cmake_minimum_required(VERSION 3.4.1)
project(Turbofs)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 14)

add_library(react-native-turbofs            SHARED
            ../cpp/react-native-turbofs.cpp
            cpp-adapter.cpp
)

# Specifies a path to native header files.
include_directories(
            ../cpp
)

# Link the React Native JSI and other necessary libraries
find_library(log-lib log)
target_link_libraries(react-native-turbofs ${log-lib})
