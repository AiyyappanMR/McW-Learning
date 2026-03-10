cmake_minimum_required(VERSION 3.10)

project(app)

add_library(
    my_math
    user_lib/my_math/my_math.hpp
    user_lib/my_math/my_math.cpp
)

target_include_directories(
    my_math
    PUBLIC user_lib/my_math
)

add_executable(
    app
    src/main.cpp
)

target_link_libraries(
    app
    PRIVATE my_math
)