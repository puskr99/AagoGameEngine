cmake_minimum_required(VERSION 3.10)
project(AagoGameEngine)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Specify the source files
set(SOURCES
    src/main.cpp
    src/UI/button/button.cpp
)

# Specify the header files
include_directories(src) # Add this line to include the src directory

# Create the executable
add_executable(Aago ${SOURCES})

target_include_directories(Aago PRIVATE ${OPENGL_INCLUDE_DIR} ${GLFW_INCLUDE_DIR})
target_link_libraries(Aago PRIVATE ${OPENGL_LIBRARIES} glfw)
