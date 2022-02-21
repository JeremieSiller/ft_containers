# ft_containers

1. [About](#about)
2. [vector](#vector)
3. [map and set](#mapandset)
4. [stack](#stack)

## About
ft_containers is a porject of the 42 core curriculum. It's purpose is to learn about different data structures and its advantages and disadvantages.
The task is to rewrite 4 containers of the standard template libray ([STL]), the vector, the map, the set and the stack.

**how to use:**

Clone the repository:
```bash
git clone https://github.com/JeremieSiller/ft_containers/
```
run make to create two files (one inlcuding the real STL and one inlcuding my STL)
```bash
make
```
run the executables
```bash
./real && ./exec
```
include the containers in your project:
```c
#include "map.hpp"
#include "set.hpp"
#include "vector.hpp"
#include "stack.hpp"
```
use the namespace ft
```c
ft::vector<int> v;
ft::map<int, std::string> m;
ft::set<int> s;
ft::stack<int> st;
```

## vector
**Description:**

The vector is a simple dynamic array where each element lies unsorted behind each other in memory.
The biggest aspect of rewriting the vector is the internal memory management. If a vector runs out of storage it has to reallocate and 
therefore copy everything into the newly allocated space.

**advantages:**
- random access (instant access of elements)
- preallocates memory to avoid running out of storage (less copies)

**disadvantags:**
- slow when running out of memory (has to copy everything) leeds to slow insertion
- high memory usage when copying
- preallocates memory to avoid running out of storage (allocates unused memory)

## map and set 

**Description:**

The map and set are sorted containers. While set sorts the elements by using itself as the keyvalue, map takes a second template paramter as the key.
Both containers usually use a binary search tree (BST) internaly to store all elements. In most cases the use tree is a red-black-tree (self-balancing) which I
also chose for this project.
Instead of allocating everything a one block like the vector does, a BST allocates nodes and links them with pointers. To avoid extremly slow insertion and lookup
times the BST is red-black-tree. A red-black-tree follows these 5 rules to avoid unbalancing:
- Every node has a colour either red or black.
- The root of the tree is always black.
- a red node cannot have a red parent or red child
- Every path from a node (including root) to any of its descendants NULL nodes has the same number of black nodes.
- All leaf nodes are black nodes
If the tree does not follow the rules after an insertion or deletion it has to restructure till it follows all the rules

**advantages:**
- sorted
- no preallocated memory, always just allocates a new node
- faster insertion than vector in case vector runs out of storage

**disadvantages:**
- non linear lookuptime (grows with insertion)
- allocates nodes and therefore more memory than an element takes
- slower insertion than vector in case vector still has storage

## stack

The stack is a data-structue that works like a stack of paper. You can only look at the top paper and only put a new paper on top of it. 
The stack uses a protected internal container to store the elements. In my case I use my own vector class, the STL typically uses a deque.

[STL]: https://en.wikipedia.org/wiki/Standard_Template_Library
