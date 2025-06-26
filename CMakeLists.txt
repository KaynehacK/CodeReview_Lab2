cmake_minimum_required(VERSION 3.30)
project(Lab2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab2
        1/Task01.cpp
        1/Task01Fixed.cpp
        1/Task01Stack.cpp
        1/Task01Stack.h
        2/Task02.cpp
        2/Task02Fixed.cpp
        2/Task02Queue.h
        2/Task02Queue.cpp
        3/Task03.cpp
        3/Task03Fixed.cpp
        3/Task03LinkedList.cpp
        3/Task03LinkedList.h
        4/Task04.cpp
        4/Task04Fixed.cpp
        4/Task04DoubleLinkedList.cpp
        4/Task04DoubleLinkedList.h
        5/Task05.cpp
        5/Task05DequeOperations.cpp
        5/Task05DequeOperations.h
        5/Task05Fixed.cpp
)
