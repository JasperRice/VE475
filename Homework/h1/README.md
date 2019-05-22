# Overview
This program is implemented in C++ with gcc version 7.4.0 and use GNU Multi Precision Arithmetic Library (GMP). Also, there's *Makefile* for the purpose of compilation. This program first generate two integers with 4096 bits and calculate their greatest common divisor with two ways: directly using gcd function from GMP library and use extended Euclidean algorithm implemented. Then compare the results to see if they are the same.

# Algorithm
The algorithm implemented is based on the Extended Euclidean Algorithm on the lecture slides (P51).

# Installation of GMP
For Ubuntu user, type the following code in Terminal:
```
sudo apt-get install libgmd-dev
```

# Compilation and run
For Linux user, open Terminal in the folder with *main.cpp* and *Makefile* and type the following code to run compile the program:
```
make
```
To run the program after compilation:
```
./main
```
To clean the executable file:
```
make clean
```
