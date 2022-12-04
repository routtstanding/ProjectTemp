//
// Created by Henok on 10/12/2022.
// 
// Michelle Routt c/p for use in final project
//
#pragma once

#include <exception>

class UnderflowException:std::exception { };
class IllegalArgumentException:std::exception { };
class ArrayIndexOutOfBoundsException:std::exception { };
class IteratorOutOfBoundsException:std::exception { };
class IteratorMismatchException:std::exception { };
class IteratorUninitializedException:std::exception { };


