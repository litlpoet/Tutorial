cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project("To Do List")

enable_testing()

add_executable(
  toDo
  main.cpp
  todo.cpp
  ) # headers doesn't need to be cared (automatic)

add_test(toDoTest toDo)

