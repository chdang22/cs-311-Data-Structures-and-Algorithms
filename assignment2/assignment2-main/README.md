<h1 align="center">CS311 Programming Assignment 2 </h1>
<h2 align="center">Total points: 10</h2>
This assignment is based on the linked list data structure from assignment 1. You must have a working LinkedList data structure.
We will implement the following two functions on input linked lists:

## Union Linked Lists
Assume two linked lists that represent Set A and Set B respectively. Implement the following function to obtain their union `A U B` and return the result as a new linked list. Note that a Set should not contain duplicate elements (e.g., integers), but its elements are not assumed to be sorted in the list. The definition of the function `unionLinkedList` is as the following:
```
 LinkedList unionLinkedList (const LinkedList& LA, const LinkedList& LB)
```
For example, if 
```
LA = (3, 5, 8, 11)
LB = (2, 6, 8, 9, 22, 24)
```
Then `unionLinkedList(LA, LB) = (3, 5, 8, 11, 2, 6, 9, 22, 24)`. Note the list isn’t sorted.
To compute the union operation, you need to implement the LinkedList `search` function to check whether a value is in the list or not.  
## Merge Linked Lists
Assume two input linked lists, LA and LB, whose elements are both in the non-descending order (duplicates may exist). Implement the following function to merge LA and LB into a new linked list (as the return value). The elements in the new list should still be in the non-descending order. The definition of the function `mergeLinkedList` is as the following:
```
LinkedList mergeLinkedList (const LinkedList& LA, const LinkedList& LB);

```
For example, if
```
LA = (3, 5, 8, 11)
LB = (2, 6, 8, 9, 22, 24)
```
Then `mergeLinkedList (LA, LB) = (2, 3, 5, 6, 8, 8, 9, 11, 22, 24)`. Note same values may repeat

## Testing
To build the test executable `test`, type make at the command line. Then run the test and confirm the outputs match what are in the "test_out.txt" file.
```
$ make
$ ./test
```
Your code should work correctly for all tests and be robust for potential error conditions, and free of dangerous code constructs and memory leaks. We will use tools like cppcheck and valgrind to to grade your code and catch memory leaks.

## Submission
You have to upload linkedlist.cpp, linkedlist.h and union_merge.cpp into gradescope for autograding. You don't need to upload anything in canvas.  
