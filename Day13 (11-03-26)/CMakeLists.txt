cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(validation_project)

set(CMAKE_PREFIX_PATH "/home/mcw/libtorch")

find_package(Torch REQUIRED)
find_package(GTest REQUIRED)

add_executable(Validation 
    conv.cpp 
    test_script.cpp
)

target_link_libraries(Validation 
    ${TORCH_LIBRARIES} 
    GTest::GTest 
    GTest::Main
)

set_property(TARGET Validation PROPERTY CXX_STANDARD 17)
set_property(TARGET Validation PROPERTY CXX_STANDARD_REQUIRED ON)