<h1 align="center">CS311 Programming Assignment 1 </h1>
<h2 align="center">Total points: 10</h2>

In this assignment, you will complete the implementation of a class of single linked list. The LinkedList class is defined in the "linkedlist.h" header file.
Don't change the interface in the header except for adding comments, as the test programs use the LinkedList interface. Complete the implementation of the data structrure in the "linkedlist.cpp" file, and add sufficient comments. You must complete the TODOs in "linkedlist.h" and "linkedlist.cpp". Delete "TODO" after you are done.

The LinkedList data structure is also used in the next a few programming assignments. So it's crucial to get it working correctly. Please see the instructor if you need help.

## LinkedList
The LinkedList data structure should implement the following member functions:
- Default constructor: it constructs an empty linked list.
- Destructor: make sure the destructor releases all dynamically allocate memory. We will check for memory leak.
- `LinkedList(const LinkedList &other)`: copy constructor creates a linked list that contain same values as the other list.
- `LinkedList &operator=(const LinkedList &other)`: the assignment statement `L2 = L1` copies the values in `L1` into `L2`. Make sure to delete original nodes in `L2` to avoid memory leak.
- `isEmpty`: returns true if the list has no element.
- `length`: returns the number of elements in the list.
- `addRear`: add an element to the end of the list.
- `addFront`: add an element to the front of the list.
- `deleteFront`: remove an element from the front of the list if the list isn't empty. The deleted value will returned by reference.
- `deleteRear`: similar to `deleteFront`, but remove from the end of the list.
- `insertAt`: insert an element at a particular position in the list. Read code comment for details.
- `deleteAt`: remove an element from a specified position in the list. Read code comment for details.

## Testing

There are three test programs to test the correctness of your 
implementation. To build the executables `test1`, `test 2` and `test 3`, type `make` at the command line.  Then run each of the tests and confirm the outputs match what are in the "test1_out.txt", "test2_out.txt" and "test3_out.txt" files. 
```
$ make
$ ./test1
$ ./test2
$ ./test3
```

Your code should work correctly for all tests and be robust for potential error conditions, and free of dangerous code constructs and memory leaks. 
We will use tools like [cppcheck](https://cppcheck.sourceforge.io/) and [valgrind](https://valgrind.org/) to to grade your code and catch memory leaks.

## Submission
You have to updated your github repository for your assignment and submit files to the gradescope for autograding. You don't need to upload anything in canvas.  
