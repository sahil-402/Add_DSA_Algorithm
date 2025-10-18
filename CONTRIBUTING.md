# Contributing to Add_DSA_Algorithm

Thank you for your interest in contributing to Add_DSA_Algorithm! We welcome contributions from everyone and are grateful for even the smallest of improvements.

## Table of Contents

- [Code of Conduct](#code-of-conduct)
- [Getting Started](#getting-started)
- [How to Contribute](#how-to-contribute)
- [Contribution Guidelines](#contribution-guidelines)
- [Submitting a Pull Request](#submitting-a-pull-request)
- [Style Guidelines](#style-guidelines)

## Code of Conduct

By participating in this project, you agree to maintain a respectful and inclusive environment for all contributors.

## Getting Started

If you're new to contributing to open source projects, here are some helpful resources:

- [Git and GitHub Fundamentals](https://towardsdatascience.com/getting-started-with-git-and-github-6fcd0f2d4ac6)
- [Introduction to GitHub](https://github.com/skills/introduction-to-github)
- [How to Contribute to Open Source](https://opensource.guide/how-to-contribute/)

## How to Contribute

### 1. Find or Create an Issue

- Browse the existing issues or create a new one to discuss what you'd like to add
- Wait for a maintainer to assign the issue to you before starting work
- Make sure the algorithm or data structure you want to add isn't already in the repository

### 2. Fork the Repository

Fork this repository by clicking the "Fork" button at the top right of the repository page. This creates a copy of the repository in your GitHub account.

### 3. Clone Your Fork

Clone your forked repository to your local machine:

```bash
git clone https://github.com/YOUR-USERNAME/Add_DSA_Algorithm.git
cd Add_DSA_Algorithm
```

### 4. Create a Branch

Create a new branch for your contribution:

```bash
git checkout -b feature/algorithm-name
```

Use a descriptive branch name like:
- `feature/merge-sort`
- `feature/binary-search-tree`
- `fix/typo-in-readme`

### 5. Make Your Changes

Add your algorithm or data structure implementation following the guidelines below.

### 6. Commit Your Changes

```bash
git add .
git commit -m "Add [Algorithm/Data Structure Name]: Brief description"
```

Example commit messages:
- `Add Merge Sort: Efficient sorting algorithm with O(n log n) time complexity`
- `Add Binary Search Tree: Implementation with insert, delete, and search operations`

### 7. Push to Your Fork

```bash
git push origin feature/algorithm-name
```

### 8. Create a Pull Request

Go to your forked repository on GitHub and click "New Pull Request". Provide a clear description of your changes.

## Contribution Guidelines

### What to Contribute

We accept contributions of:

- **Data Structures**: Arrays, Linked Lists, Stacks, Queues, Trees, Graphs, Heaps, etc.
- **Algorithms**: Sorting, Searching, Dynamic Programming, Greedy, Divide and Conquer, etc.
- **Problem Solutions**: LeetCode, HackerRank, Codeforces problems with clear explanations
- **Documentation**: Improvements to README, comments, or explanations

### File Organization

Please organize your contribution as follows:

```
Category/
  ├── algorithm_name.cpp
  ├── algorithm_name.py
  └── README.md (if needed for complex algorithms)
```

Examples:
- `Sorting/merge_sort.cpp`
- `Dynamic Programming/longest_common_subsequence.cpp`
- `Graphs/dijkstra_algorithm.cpp`

### Code Requirements

1. **File Naming**: Use lowercase with underscores (snake_case)
   - ✅ `bubble_sort.cpp`
   - ❌ `BubbleSort.cpp`

2. **Comments**: Include clear comments explaining:
   - Algorithm logic
   - Time complexity
   - Space complexity
   - Example usage

3. **Header Template**: Start your file with:

```cpp
/*
 * Algorithm: [Algorithm Name]
 * Description: [Brief description]
 * Time Complexity: O(?)
 * Space Complexity: O(?)
 * Author: [Your Name]
 */
```

4. **Include Examples**: Add example usage in comments or a main function

5. **Test Your Code**: Ensure your code compiles and runs correctly

## Style Guidelines

### C++ Style Guide

```cpp
#include <iostream>
#include <vector>
using namespace std;

/*
 * Algorithm: Binary Search
 * Description: Searches for a target value in a sorted array
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1; // Not found
}

// Example usage
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int target = 7;
    
    int result = binarySearch(arr, target);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}
```

### Python Style Guide (if applicable)

```python
"""
Algorithm: Binary Search
Description: Searches for a target value in a sorted array
Time Complexity: O(log n)
Space Complexity: O(1)
"""

def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1  # Not found

# Example usage
if __name__ == "__main__":
    arr = [1, 3, 5, 7, 9, 11]
    target = 7
    
    result = binary_search(arr, target)
    
    if result != -1:
        print(f"Element found at index: {result}")
    else:
        print("Element not found")
```

## Submitting a Pull Request

When submitting a PR, please:

1. **Title**: Use a clear, descriptive title
   - ✅ `Add Quick Sort algorithm with detailed explanation`
   - ❌ `Update`

2. **Description**: Include:
   - What algorithm/data structure you added
   - Brief explanation of how it works
   - Time and space complexity
   - Any relevant resources or references

3. **Link Issues**: Reference any related issues using `Closes #issue_number`

4. **Be Patient**: Wait for maintainers to review your PR. Be open to feedback and make requested changes promptly.

## Questions?

If you have any questions or need help, feel free to:
- Open an issue
- Comment on an existing issue
- Reach out to the maintainers

## Thank You!

Your contributions make this project better for everyone. We appreciate your time and effort! 🎉

---

Happy Coding! 💻
