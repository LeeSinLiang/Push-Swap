<h1 align="center">Push Swap: The most efficient yet inefficient algorithm.</h1>
<p align="center" style="margin-bottom: 2px;">
	<img align="center" src="https://github.com/LeeSinLiang/Push-Swap/assets/38833175/1461c864-4565-4f04-a8ff-5dd7be8e444b" width=20% height=20% />
</p>
<p align="center" style="margin-top:0px;">
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/LeeSinLiang/Push-Swap?color=blue&style=flat-square" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/LeeSinLiang/Push-Swap?color=green&style=flat-square" />
	<br/>
  	A journey to sort arrays efficiently.
</p>

**Disclaimer: This implementation is purely for personal entertainment, by no means it's suitable for production use cases.**
## Description
- Push Swap is a sorting algorithm implemented in C. It efficiently sorts a stack of integers using a series of predefined operations.
- The algorithm aims to minimize the number of operations required to sort the stack, achieving an efficient sorting process.

## Implementation
- The push_swap algorithm can be implemented using different data structures such as stacks (Last In First Out) or linked lists. For this project, a doubly linked list data structure is recommended for efficient stack manipulation.

  - Create a doubly linked list structure to represent stack nodes, with each node containing an integer value and pointers to the next and previous nodes.
  - Implement functions for stack initialization, stack operations (push, pop, swap, rotate, and reverse rotate), and stack sorting.
  - For my approach, I implemented a function to calculate the minimum number of moves required to push an element from stack A to stack B. This function will determine the optimal moves to push to stack B during the sorting process before the actual sorting operation begins.

## Sorting Algorithms
- The push_swap algorithm uses different sorting techniques based on the number of elements in the stack:
  - A sorting algorithm based on permutations is used for small stack sizes (typically 3 or less). This involves checking all possible permutations of the stack and determining the minimum number of operations required to sort it.
  - For larger stack sizes, more efficient sorting algorithms such as quicksort or mergesort can be implemented. These algorithms divide the stack into smaller sub-stacks, sort them recursively, and then combine them to achieve the final sorted order.

## Usage
- To compile the push_swap program, run:
  ```
  make
  ```
- To use the push_swap program, provide a series of integers as arguments:
  ```
  ./push_swap <integers>
  ```
  For example:
  ```
  ./push_swap 5 2 7 1 4
  ```
- The program will output a list of operations to sort the input stack. A two/three-letter code represents each operation. The goal is to minimize the number of operations required to sort the stack efficiently.

## Resources
To get started with this project, you can refer to the following resources:
- Doubly Linked List in C: [GeeksforGeeks](https://www.geeksforgeeks.org/doubly-linked-list/)
- Sorting Algorithms: [GeeksforGeeks - Sorting](https://www.geeksforgeeks.org/sorting-algorithms/)
- Quicksort Algorithm: [Wikipedia](https://en.wikipedia.org/wiki/Quicksort)
- Mergesort Algorithm: [Wikipedia](https://en.wikipedia.org/wiki/Merge_sort)

Feel free to explore additional resources and implement further optimizations to enhance the efficiency of your push_swap algorithm.

## Author
Created by Lee Sin Liang

## Acknowledgements
This project was completed as part of the curriculum at 42 School.
