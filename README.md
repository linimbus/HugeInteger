# HugeInteger

## Project Description

HugeInteger is a C++ project designed to handle very large integers. These large integers typically exceed the representation range of standard integer types (such as `int` or `long long`), thus requiring a specialized implementation. The project uses strings or arrays to store and manipulate these large integers, supporting basic arithmetic operations (such as addition, subtraction, multiplication, and division) as well as comparison operations.

### Key Features

- **Large Integer Storage**: Uses strings or arrays to represent large integers, ensuring the ability to handle integers of arbitrary length.
- **Arithmetic Operations**: Supports basic operations like addition, subtraction, multiplication, and division.
- **Comparison Operations**: Supports comparisons between large integers (e.g., greater than, less than, equal to).
- **Input/Output**: Provides user-friendly input and output interfaces for easy input and viewing of large integers.

## Compilation Process

### Environment Requirements

- **Compiler**: A compiler that supports C++11 or later (e.g., GCC, Clang, or MSVC).
- **Build Tools**: It is recommended to use CMake or Makefile for project building.

### Compilation Steps

```bash
git clone https://github.com/linimbus/huge-integer-cpp.git
cd huge-integer-cpp
make
./HugeInteger
```


```bash
BEGIN TEST ADDITION AND SUBTRACTION
Test cases in Addition for same size and same sign without borrow or carry success ( +0.5 )
Test cases in Subtraction for same size and same sign without borrow or carry success ( +0.5 )
Test cases in Addition for same size and same sign with borrow or carry success ( +0.5 )
Test cases in Subtraction for same size and same sign with borrow or carry success ( +0.5 )
Test cases in Addition for same size and different sign without borrow or carry success ( +0.5 )
Test cases in Subtraction for same size and different sign without borrow or carry success ( +0.5 )
Test cases in Addition for same size and different sign with borrow or carry success ( +0.5 )
Test cases in Subtraction for same size and different sign with borrow or carry success ( +0.5 )
Test cases in Addition for same size and zero success ( +0.5 )
Test cases in Subtraction for same size and zero success ( +0.5 )
Test cases in Addition for first size larger and same sign without borrow or carry success ( +0.5 )
Test cases in Subtraction for first size larger and same sign without borrow or carry success ( +0.5 )
Test cases in Addition for first size larger and same sign with borrow or carry success ( +0.5 )
Test cases in Subtraction for first size larger and same sign with borrow or carry success ( +0.5 )
Test cases in Addition for first size larger and different sign without borrow or carry success ( +0.5 )
Test cases in Subtraction for first size larger and different sign without borrow or carry success ( +0.5 )
Test cases in Addition for first size larger and different sign with borrow or carry success ( +0.5 )
Test cases in Subtraction for first size larger and different sign with borrow or carry success ( +0.5 )
Test cases in Addition for first size larger and zero success ( +0.5 )
Test cases in Subtraction for first size larger and zero success ( +0.5 )
Test cases in Addition for second size larger and same sign without borrow or carry success ( +0.5 )
Test cases in Subtraction for second size larger and same sign without borrow or carry success ( +0.5 )
Test cases in Addition for second size larger and same sign with borrow or carry success ( +0.5 )
Test cases in Subtraction for second size larger and same sign with borrow or carry success ( +0.5 )
Test cases in Addition for second size larger and different sign without borrow or carry success ( +0.5 )
Test cases in Subtraction for second size larger and different sign without borrow or carry success ( +0.5 )
Test cases in Addition for second size larger and different sign with borrow or carry success ( +0.5 )
Test cases in Subtraction for second size larger and different sign with borrow or carry success ( +0.5 )
Test cases in Addition for second size larger and zero success ( +0.5 )
Test cases in Subtraction for second size larger and zero success ( +0.5 )
Test addition and subtraction PASS: ALL
END TEST ADDITION AND SUBTRACTION, TOTAL MARK IS 15/15
BEGIN TEST COMPARETO
Test cases in Compare for equal and zero = zero success ( +0.5 )
Test cases in Compare for equal and positive/negative = positive/negative success ( +0.5 )
Test cases in Compare for first larger and negative > negative success ( +0.5 )
Test cases in Compare for first larger and positive > positive success ( +0.5 )
Test cases in Compare for first larger and positive > zero success ( +0.5 )
Test cases in Compare for first larger and positive > negative success ( +0.5 )
Test cases in Compare for first smaller and negative < negative success ( +0.5 )
Test cases in Compare for first smaller and positive < positive success ( +0.5 )
Test cases in Compare for first smaller and negative < zero success ( +0.5 )
Test cases in Compare for first smaller and negative < positive success ( +0.5 )
Test compareTo PASS: ALL
END TEST COMPARETO, TOTAL MARK IS 5/5
BEGIN TEST MULTIPLICATION
Test cases in Multiplication for same size and same sign without carry success ( +1 )
Test cases in Multiplication for same size and same sign with carry success ( +1 )
Test cases in Multiplication for same size and different sign without carry success ( +1 )
Test cases in Multiplication for same size and different sign with carry success ( +1 )
Test cases in Multiplication for same size and multiply zero success ( +1 )
Test cases in Multiplication for first size larger and same sign without carry success ( +1 )
Test cases in Multiplication for first size larger and same sign with carry success ( +1 )
Test cases in Multiplication for first size larger and different sign without carry success ( +1 )
Test cases in Multiplication for first size larger and different sign with carry success ( +1 )
Test cases in Multiplication for first size larger and multiply zero success ( +1 )
Test cases in Multiplication for second size larger and same sign without carry success ( +1 )
Test cases in Multiplication for second size larger and same sign with carry success ( +1 )
Test cases in Multiplication for second size larger and different sign without carry success ( +1 )
Test cases in Multiplication for second size larger and different sign with carry success ( +1 )
Test cases in Multiplication for second size larger and multiply zero success ( +1 )
Test multiplication PASS: ALL
END TEST MULTIPLICATION, TOTAL MARK IS 15/15
******************************
*** FINAL TOTAL MARK IS 35 ***
******************************
```
