# Add_DSA_Algorithm

A comprehensive collection of Data Structures and Algorithms implementations in C++ and other programming languages.

## 📚 Table of Contents

- [About](#about)
- [Current Implementations](#current-implementations)
- [Setup and Usage](#setup-and-usage)
- [Contributing](#contributing)
- [Issues and Improvements](#issues-and-improvements)
- [License](#license)

## 🎯 About

This repository contains implementations of various data structures and algorithms. The goal is to provide clear, well-documented code that can serve as a learning resource for students and developers.

## 📂 Current Implementations

### Sorting Algorithms
- Binary Search
- Bubble Sort
- Insertion Sort
- Linear Search
- Merge Sort
- Selection Sort

### Bit Manipulation

#### Basic Operations
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

#### Advanced Operations
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

### Tree Data Structures
- Binary Tree implementations
- Binary Search Tree (BST)
- Tree Properties (Height, Diameter, Balance, Symmetry)
- Lowest Common Ancestor problems
- Tree Views (Top, Bottom, Left, Right)
- Path Problems
- Tree Constructions
- AVL Tree
- Heap implementations

## 🛠 Setup and Usage

### Prerequisites
- C++ compiler (GCC recommended)
- Basic understanding of data structures and algorithms

### Compilation
To compile any program:
```bash
g++ filename.cpp -o output
```

Example:
```bash
g++ bubble_sort.cpp -o bubble_sort
./bubble_sort
```

## 🤝 Contributing

We welcome contributions! Please see our [CONTRIBUTING.md](CONTRIBUTING.md) for detailed guidelines on how to contribute to this project.

### Quick Start

1. Fork the repository
2. Create a new branch (`git checkout -b feature/algorithm-name`)
3. Add your algorithm with proper documentation
4. Commit your changes (`git commit -m 'Add: Algorithm Name'`)
5. Push to the branch (`git push origin feature/algorithm-name`)
6. Open a Pull Request

## 🔍 Issues and Improvements

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

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🌟 Contributors

Thanks to all contributors who have helped build this repository!

---

Happy Coding! 💻
