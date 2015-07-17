cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project("To Do List")

enable_testing()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(warnings "-Wall -Wextra -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set(warnings "/W4 /WX /EHsc")
endif()

if (NOT CONFIGURED_ONCE)
  set(CMAKE_CXX_FLAGS "${warnings}"
    CACHE STRING
    "C++ flags used by the compiler during all build types."
    FORCE)
  set(CMAKE_C_FLAGS "${warnings}"
    CACHE STRING
    "C flags used by the compiler during all build types."
    FORCE)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(libToDo)

add_executable(
  toDo
  src/main.cpp
  ) # headers doesn't need to be cared (automatic)
target_link_libraries(
  toDo
  libToDo
  )

add_test(toDoTest toDo)

set(CONFIGURED_ONCE TRUE
  CACHE INTERNAL
  "A flag showing that CMake has configured at least once")