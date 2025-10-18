# Data Structures and Algorithms - Bit Manipulation

This repository contains a collection of Data Structures and Algorithms implementations with a focus on Bit Manipulation techniques in C++.

## Table of Contents

- [Overview](#overview)
- [Bit Manipulation Algorithms](#bit-manipulation-algorithms)
- [Setup and Usage](#setup-and-usage)
- [Contributing](#contributing)
- [Issues and Improvements](#issues-and-improvements)

## Overview

This repository focuses on implementing various bit manipulation algorithms and techniques in C++. Each file contains specific implementations that demonstrate different bit manipulation concepts.

## Bit Manipulation Algorithms

### Basic Operations
1. **Check Odd/Even** (`check_odd_even.cpp`)
   - Determines if a number is odd or even using bitwise operations

2. **Power of 2** (`Power_of_2.cpp`)
   - Contains two implementations to check if a number is a power of 2:
     - Brute force approach using binary conversion
     - Optimal solution using bitwise AND operation

3. **Bit Setting Operations**
   - Set ith bit (`set_ith_bit.cpp`)
   - Clear ith bit (`clear_ith_bit.cpp`)
   - Toggle ith bit (`toogle_ith_bit.cpp`)
   - Set rightmost unset bit (`set_rightMost_bit_unset.cpp`)

### Advanced Operations
1. **Counting Operations**
   - Count set bits (`count_set_bit.cpp`)
   - Find numbers with odd occurrences (`odd_occurence_of_two_num.cpp`)

2. **Binary Operations**
   - XOR operations from left to right (`XOR_left_to_right.cpp`)
   - Division operations using bits (`divided_divisor.cpp`, `divisor_divided.cpp`)

3. **Special Problems**
   - Find single occurrence in thrice occurring numbers (`imp_thrice_occur_find_once_occurence.cpp`)
   - Generate power set (`power_set.cpp`)
   - Flip bits (`flip_bits.cpp`)

## Setup and Usage

### Prerequisites
- C++ compiler (GCC recommended)
- Basic understanding of bit manipulation concepts

### Compilation
To compile any program:
```bash
g++ filename.cpp -o output
```

Example:
```bash
g++ Power_of_2.cpp -o power2
./power2
```

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes:

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## Issues and Improvements

Current issues that need to be addressed:

1. **Code Structure**
   - Need to add proper header files
   - Implement proper error handling
   - Add input validation

2. **Documentation**
   - Add detailed comments in each file
   - Include time and space complexity analysis
   - Add example usage for each algorithm

3. **Testing**
   - Add unit tests
   - Include edge cases
   - Test with larger inputs

4. **Build System**
   - Add CMake configuration
   - Create proper build structure
   - Add .gitignore for build artifacts

5. **Code Quality**
   - Fix operator precedence issues
   - Implement consistent coding style
   - Add error handling for edge cases

## License

This project is open source and available under the [MIT License](LICENSE).

---
Note: Some implementations might need optimization or improvements. Contributions and suggestions are welcome!