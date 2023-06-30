cmake_minimum_required(VERSION 3.25)
project(boost_demo)

set(CMAKE_CXX_STANDARD 17)


set(Boost_ROOT "D:/Program Files/common-cpp/boost")
find_package(Boost 1.82.0 REQUIRED COMPONENTS FileSystem System)
if(Boost_FOUND)
    message(STATUS "boost include path is : ${Boost_INCLUDE_DIRS}")
    message(STATUS "boost library path is : ${Boost_LIBRARY_DIRS}")
    message(STATUS "boost libraries is : ${Boost_LIBRARIES}")
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
else()
    message(WARNING "boost not found.")
endif()
include(CMakePrintHelpers)
cmake_print_variables(Boost_FOUND)

add_executable(boost_demo main.cpp)




#set(Boost_USE_STATIC_LIBS        ON) # only find static libs
#set(Boost_USE_MULTITHREADED      ON)
#set(Boost_USE_STATIC_RUNTIME    OFF)
#find_package(Boost 1.36.0 COMPONENTS date_time filesystem system ...)
#if(Boost_FOUND)
#    include_directories(${Boost_INCLUDE_DIRS})
#    add_executable(foo foo.cc)
#    target_link_libraries(foo ${Boost_LIBRARIES})
#endif()
