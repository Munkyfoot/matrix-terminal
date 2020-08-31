# Matrix Terminal
### A Program for Generating "Matrix Rain" in a Linux Terminal

### Requirements:
- C++ Standard >= 17
- NCURSES >= 6.2
- CMAKE >= 3.16.3

### Folder Structure:
```
matrix-terminal/
    include/
        matrix.h
    src/
        main.cpp
        matrix.cpp
    CMakeLists.txt
    LICENSE
    README.md
```

### Program Structure:
#### matrix.h
Declares and defines the CharSet enum and Drop struct. Declares the Matrix class.
#### matrix.cpp
Defines the Matrix class.
#### main.cpp
Initializes NCURSES and instantiates a Matrix object to manage the output to terminal.

### Build Instructions:
1. Make sure you are in the 'matrix-terminal' parent directory.
2. Use 'mkdir build && cd build' to create and enter the build directory.
3. Use 'cmake ..' to allow CMake to generate the necessary files to compile the project.
4. Use 'make' to compile the project and create an executable.
5. Run the program with './matrix'.

### Operation:
Upon running the program it will begin generating the "Matrix Rain" effect in the terminal where you run the program.
- Press the 'q' key to quit the program at any time.
- Press the 'c' key to toggle the character set between ASCII and binary.

## Udacity Rubric
### Capstone Option 1

### Loops, Functions, I/O
- A variety of control structures are used in the project.
- The project code is clearly organized into functions.
- The project accepts input from a user as part of the necessary operation of the program.

### Object Oriented Programming
- The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.
- All class data members are explicitly specified as public, protected, or private.
- All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.
- Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.

### Memory Management
- At least two variables are defined as references, or two functions use pass-by-reference in the project code.
- The project uses at least one smart pointer: unique_ptr, shared_ptr, or weak_ptr. The project does not use raw pointers.

### Concurrency
- The project uses multiple threads in the execution.
- A mutex or lock (e.g. std::lock_guard or `std::unique_lock) is used to protect data that is shared across multiple threads in the project code.