cmake_minimum_required(VERSION 3.21)
project(RouttProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(RouttProject RouttProject.cpp actressActor.h fileIO.h BST.h Exceptions.h pictures.h AddRecord.h Visitor.h OutputVisitor.h)