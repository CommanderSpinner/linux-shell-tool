cmake_minimum_required(VERSION 3.10)

project(linux-shell-tool C)

# Set the path for source files
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

# Find GTK3 package using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

# Set the include directory for your own header files
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/includes")

# Include GTK3 headers and your own include directory
include_directories(${INCLUDE_DIR} ${GTK3_INCLUDE_DIRS})

# Add your source files (all C files in the src directory)
file(GLOB SOURCES "${SRC_DIR}/*.c")

# Create an executable
add_executable(my_project ${SOURCES})

# Link the GTK3 libraries to your executable
target_link_libraries(my_project ${GTK3_LIBRARIES})

# Optionally, set additional compiler flags for GTK3
target_compile_options(my_project PRIVATE ${GTK3_CFLAGS_OTHER})
