# 3150-lab9

instructions for use:

- in order to run, first make sure any necessary c/c++ extensions are installed
- in the terminal, run the line for the demo with weak pointers: 
g++ -std=c++17 -Iinclude -o testlab Node.cpp LinkedList.cpp lab9test.cpp
- this line will compile the tests and put the results in a file called 'testlab'
- in order to read the file, next run the following line in the terminal: 
./testlab
- in the terminal, run the line for the demo WITHOUT weak pointers:
g++ -std=c++17 -Iinclude -o testlab2 Node2.cpp LinkedList2.cpp lab9test2.cpp
- this line will compile the tests and put the results in a file called 'testlab2'
- in order to read the file, next run the following line in the terminal:
./testlab2


notes on files included:

- doctest.h - for testing
- Node.cpp - definition and implementation of Node struct
- LinkedList.cpp - definition and implementation of LinkedList class
- lab9test.cpp - testing and test cases
- Node2.cpp - definition and implementation of Node struct without weak ptr
- LinkedList2.cpp - definition and implementation of LinkedList class without weak ptr
- lab9test2.cpp - testing and test cases for linkedlist2 without weak ptr