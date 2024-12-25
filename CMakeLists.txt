cmake_minimum_required(VERSION 3.10)

project(linux-shell-tool C)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/includes")

include_directories(${INCLUDE_DIR} ${GTK3_INCLUDE_DIRS})

file(GLOB SOURCES "${SRC_DIR}/*.c")

add_executable(linux-shell-tool ${SOURCES})

target_link_libraries(linux-shell-tool ${GTK3_LIBRARIES})

target_compile_options(linux-shell-tool PRIVATE ${GTK3_CFLAGS_OTHER})
