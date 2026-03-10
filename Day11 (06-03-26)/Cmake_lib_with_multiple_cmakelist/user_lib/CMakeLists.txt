
add_library(my_math
    my_math/my_math.cpp
    my_math/my_math.hpp
)
target_include_directories(my_math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/my_math)