cmake_minimum_required(VERSION 2.8.9)
project (interview)
add_executable(
    main 
    src/main.cpp 
    src/Task.cpp 
    src/TaskManager.cpp
    src/Config.cpp 
)
include_directories(include)
set (CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
enable_testing()

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 

find_package(Boost 1.76.0 COMPONENTS program_options) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    target_link_libraries(main ${Boost_LIBRARIES})
endif()

target_link_libraries(main stdc++fs)


add_subdirectory(tests)
