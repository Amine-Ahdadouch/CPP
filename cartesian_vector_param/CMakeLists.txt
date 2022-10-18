cmake_minimum_required(VERSION 3.0)

# set the project name
project(cartesian_vector_param_2)

# add the lib
add_library(mysource SHARED vector.cpp)

# add the executable
add_executable(main main.cpp)

# do not forget to link
target_link_libraries(main mysource)