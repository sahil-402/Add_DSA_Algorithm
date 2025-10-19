# Tree Algorithms 🌳

A curated collection of essential tree data structures and algorithms for practical use, technical interviews, and competitive programming.

## 📚 Table of Contents

- [Overview](#overview)
- [Folder Structure](#folder-structure)
- [Topics Covered](#topics-covered)
- [How to Use](#how-to-use)
- [Complexity Analysis](#complexity-analysis)
- [Resources](#resources)

## 🎯 Overview

This repository contains implementations of the most commonly used tree data structures and algorithms. Rather than being exhaustive, we focus on practical topics that appear frequently in:
- Technical interviews (FAANG and other companies)
- Real-world applications (databases, file systems, networking)
- Competitive programming
- Daily software development

Each implementation includes:
- Clean, well-commented code
- Time and space complexity analysis
- Example usage with test cases
- Practical applications

## 📁 Folder Structure

```
tree-algorithms/
│
├── README.md
│
├── 01-binary-tree/
│   ├── binary_tree
│   ├── inorder_traversal
│   ├── preorder_traversal
│   ├── postorder_traversal
│   └── level_order_traversal
│
├── 02-binary-search-tree/
│   ├── bst_implementation
│   ├── bst_operations
│   └── validate_bst
│
├── 03-tree-properties/
│   ├── height_of_tree
│   ├── diameter_of_tree
│   ├── balanced_tree
│   └── symmetric_tree
│
├── 04-lowest-common-ancestor/
│   ├── lca_binary_tree
│   └── lca_bst
│
├── 05-tree-views/
│   ├── left_view
│   ├── right_view
│   ├── top_view
│   └── bottom_view
│
├── 06-path-problems/
│   ├── root_to_leaf_paths
│   ├── path_sum
│   └── maximum_path_sum
│
├── 07-tree-construction/
│   ├── inorder_preorder_construction
│   └── sorted_array_to_bst
│
├── 08-special-traversals/
│   ├── zigzag_traversal
│   ├── vertical_order_traversal
│   └── boundary_traversal
│
├── 09-avl-tree/
│   ├── avl_implementation
│   └── avl_rotations
│
└── 10-heap/
    ├── min_heap
    ├── max_heap
    └── heap_operations
```

## 🌲 Topics Covered

### 1. Binary Tree Basics
Foundation of all tree concepts with essential traversal methods.
- **Basic Structure**: Node definition and tree construction
- **Inorder Traversal**: Left → Root → Right (Recursive & Iterative)
- **Preorder Traversal**: Root → Left → Right (Recursive & Iterative)
- **Postorder Traversal**: Left → Right → Root (Recursive & Iterative)
- **Level Order Traversal**: Breadth-first traversal using queue

**Real-world use**: File system traversal, expression evaluation, DOM manipulation

---

### 2. Binary Search Tree (BST)
Ordered tree structure for efficient searching and sorting.
- **BST Implementation**: Basic structure with BST property
- **Insert Operation**: Add elements maintaining BST property
- **Search Operation**: Find elements in O(log n) average time
- **Delete Operation**: Remove nodes with three cases
- **Find Min/Max**: Leftmost and rightmost nodes
- **Validate BST**: Check if a tree satisfies BST properties

**Real-world use**: Database indexing, symbol tables, priority scheduling

---

### 3. Tree Properties & Measurements
Essential algorithms to analyze tree characteristics.
- **Height of Tree**: Maximum depth from root to leaf
- **Diameter of Tree**: Longest path between any two nodes
- **Balanced Tree Check**: Verify if tree is height-balanced
- **Symmetric Tree Check**: Mirror image validation
- **Count Nodes**: Total and leaf node counting

**Real-world use**: Performance optimization, tree visualization, balance maintenance

---

### 4. Lowest Common Ancestor (LCA)
Find the common ancestor of two nodes efficiently.
- **LCA in Binary Tree**: General approach for any binary tree
- **LCA in BST**: Optimized approach using BST properties

**Real-world use**: Version control systems, hierarchical data queries, network routing

---

### 5. Tree Views
Different perspectives of tree visualization.
- **Left View**: Leftmost node at each level
- **Right View**: Rightmost node at each level
- **Top View**: Nodes visible from top
- **Bottom View**: Nodes visible from bottom

**Real-world use**: UI rendering, tree visualization tools, reporting systems

---

### 6. Path Problems
Algorithms involving paths from root to leaves.
- **Root to Leaf Paths**: All paths from root to leaves
- **Path Sum**: Check if path with given sum exists
- **Maximum Path Sum**: Find path with maximum sum

**Real-world use**: Decision trees, game AI, cost optimization

---

### 7. Tree Construction
Build trees from different representations.
- **From Inorder & Preorder**: Reconstruct original tree
- **From Inorder & Postorder**: Alternative reconstruction method
- **Sorted Array to BST**: Build balanced BST from sorted data

**Real-world use**: Serialization/deserialization, data recovery, tree transmission

---

### 8. Special Traversals
Advanced traversal patterns for specific use cases.
- **Zigzag Traversal**: Alternate left-right level order
- **Vertical Order Traversal**: Nodes at same vertical distance
- **Boundary Traversal**: Perimeter of the tree

**Real-world use**: Tree printing, visualization, specific data extraction

---

### 9. AVL Tree
Self-balancing BST for guaranteed O(log n) operations.
- **AVL Implementation**: Height-balanced tree structure
- **Insertion with Rotations**: Maintain balance after insert
- **Left & Right Rotations**: Basic rotation operations
- **Balance Factor**: Height difference calculation

**Real-world use**: Databases requiring frequent insertions/deletions, in-memory indexes

---

### 10. Heap (Priority Queue)
Complete binary tree for priority-based operations.
- **Min Heap**: Parent smaller than children
- **Max Heap**: Parent larger than children
- **Heapify**: Convert array to heap
- **Insert & Extract**: Add/remove elements maintaining heap property

**Real-world use**: Task scheduling, Dijkstra's algorithm, median finding, event simulation

---

## 🚀 How to Use

1. **Browse by Topic**: Navigate to the folder of your interest
2. **Read the Code**: Each file contains well-commented implementation
3. **Understand Complexity**: Check time and space complexity comments
4. **Run Examples**: Use provided test cases to see the algorithm in action
5. **Practice**: Try modifying or extending the implementations

### Example Usage Flow
```
1. Start with 01-binary-tree/ if you're new to trees
2. Move to 02-binary-search-tree/ for ordered structures
3. Learn 03-tree-properties/ and 04-lowest-common-ancestor/
4. Practice interview problems in 05-tree-views/ and 06-path-problems/
5. Explore advanced topics: AVL, Segment Tree, Trie, Heap
```

## ⚡ Complexity Analysis

Each implementation includes complexity analysis:

### Common Tree Operations

| Operation | BST (Average) | BST (Worst) | AVL Tree | Heap |
|-----------|---------------|-------------|----------|------|
| Search    | O(log n)      | O(n)        | O(log n) | -    |
| Insert    | O(log n)      | O(n)        | O(log n) | O(log n) |
| Delete    | O(log n)      | O(n)        | O(log n) | O(log n) |
| Find Min/Max | O(log n)   | O(n)        | O(log n) | O(1) |
| Traversal | O(n)          | O(n)        | O(n)     | O(n) |

### Segment Tree & Trie

| Operation | Segment Tree | Trie |
|-----------|--------------|------|
| Build     | O(n)         | O(m*k)* |
| Query     | O(log n)     | O(k)* |
| Update    | O(log n)     | O(k)* |

*where k = length of string, m = number of strings

## 📖 Resources

### Learn Trees from Scratch
- [VisuAlgo - Interactive Visualizations](https://visualgo.net/en/bst) - Visual learning tool
- [GeeksforGeeks - Trees](https://www.geeksforgeeks.org/tree-data-structure/) - Comprehensive tutorials
- [CS50 - Trees](https://cs50.harvard.edu/x/) - Harvard's free course

### Practice Problems
- [LeetCode - Tree Tag](https://leetcode.com/tag/tree/) - 500+ tree problems
- [HackerRank - Tree Challenges](https://www.hackerrank.com/domains/data-structures/trees)
- [Codeforces - Tree Problems](https://codeforces.com/problemset?tags=trees)

### Books
- **Introduction to Algorithms** (CLRS) - Chapters 10, 12, 13
- **Cracking the Coding Interview** - Tree chapters
- **Algorithm Design Manual** by Steven Skiena

### Video Tutorials
- [Abdul Bari - Tree Algorithms](https://www.youtube.com/c/AbdulBari)
- [MIT OpenCourseWare - Binary Search Trees](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/)

## 🎯 Why These Topics?

This repository focuses on **essential, frequently-used** tree concepts:

- ✅ **High Interview Frequency**: These topics appear in 90% of tree-related interviews
- ✅ **Practical Applications**: Used in real-world software systems
- ✅ **Foundation Building**: Core concepts that help understand advanced topics
- ✅ **Manageable Size**: ~40-50 focused implementations vs 100+ scattered files
- ✅ **Quality Focus**: Better to master these well than superficially cover everything

## 📝 License

This project is open source and available under the [MIT License](LICENSE).


---