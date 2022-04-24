cmake_minimum_required(VERSION 3.21)
project(vulkanLearn)

set(CMAKE_CXX_STANDARD 20)

find_package(Vulkan REQUIRED)

include_directories(./extern/glfw3/include/)        #GLFW3
link_directories(./extern/glfw3/build/src/)         #GLFW3 library dir

include_directories(./extern/)                      #GLM
include_directories(./include/)                     #{CMAKE_CURRENT_DIR}/include

add_executable(vulkanLearn
        src/main.cpp
        src/instance.cpp
        src/validation.cpp)

target_link_libraries(vulkanLearn
        PRIVATE Vulkan::Vulkan
        -lglfw3)