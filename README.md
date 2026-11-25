# Data Structures in C

A personal study repository where classic data structures are implemented from scratch in C. The goal is to build a solid foundation in manual memory management, pointers, recursion, and algorithmic thinking by writing every structure by hand and testing it through interactive CLI menus.

---

## Requirements

- **GCC** (or any compatible C compiler)
- **Make**
- Standard C Library (`stdio.h`, `stdlib.h`)

---

## How to Build and Run

Each data structure lives in its own folder with a `Makefile` and an interactive `main.c`.

To compile and run any of them:

```bash
cd <folder-name>
make && ./programa
```

For example, to run the Binary Search Tree:

```bash
cd BinaryTree
make && ./programa
```

To remove the compiled binary:

```bash
make clean
```

---

## Repository Structure

### 1. `Sequential-Dynamic-List/`
A dynamically resizing sequential list (array-backed).
- **Files**: `sequentialDynamicList.c/.h`, `utils.c/.h`, `main.c`, `Makefile`
- **Features**:
  - Append elements to the end of the list
  - Insert and remove elements at specific positions
  - Remove the last element
  - Automatic memory reallocation when capacity changes
  - Print all elements and free allocated memory

### 2. `Stack/`
A LIFO (Last-In, First-Out) stack backed by a dynamic array.
- **Files**: `stack.c/.h`, `utils.c/.h`, `main.c`, `Makefile`
- **Features**:
  - `push`, `pop`, and `peek` operations
  - Capacity checking and dynamic resizing
  - Clear stack (resetting to initial capacity) and print elements
  - Full memory cleanup on exit

### 3. `LinkedList/`
A singly linked list implemented with heap-allocated `Node` structs.
- **Files**: `linkedList.c/.h`, `utils.c/.h`, `main.c`, `Makefile`
- **Features**:
  - Append and insert nodes at 0-indexed positions
  - Remove nodes by position
  - Display list size and print linked nodes
  - Clear all nodes and free the list safely

### 4. `BinaryTree/`
A Binary Search Tree (BST) with modularized recursive helpers.
- **Files**: `binarySearchTree.c/.h`, `recursion.c/.h`, `properties.c/.h`, `main.c`, `Makefile`
- **Features**:
  - Initialize root, insert values (rejecting duplicates), and search values with depth tracking
  - Remove any node (handling 0, 1, and 2 children cases)
  - Find and remove minimum and maximum values
  - Tree traversals: `Pre-Order`, `In-Order`, and `Post-Order`
  - Calculate tree height (`getTreeHeight`)
  - Visual tree rendering in the terminal (`printBinarySearchTree`)
  - Clear nodes and delete the tree safely
