<h1 align="center">CS 311: Assignment 7</h1>
<h2 align="center">Total points: 10</h2>

In this assignment, you will implement Heap and Heapsort.

in this assignment, you will complete the implementation of single class of Heap. The Heap class is defined in the "heap.h" header file.
Don't change the interface in the header except for adding comments, as the test programs use the Heap interface. Complete the implementation of the data structrure in the "heap.cpp" file, and add sufficient comments. You must complete the TODOs in "heap.h" and "heap.cpp". Delete "TODO" after you are done.

The Heap data structure is also used in the next a few programming assignments. So it's crucial to get it working correctly. Please see the instructor if you need help.

## Heap
The Heap data structure should implement the following member functions:
- Default constructor: It constructs an empty Heap.
- Destructor: Make sure the destructor releases all dynamically allocate memory. We will check for memory leak.
- `buildHeapfromArray`: Builds a heap from an array of length.
- `heapify`: Organizes the values in a heap class.
- `percolateDown`: Percolates down the Heap to move nodes down one level.
- `percolateUp`: Percolates up the Heap to move nodes up one level.
- `insert`: Inserts a value into the Heap.
- `removeMax`: Removes the max values from the Heap.
- `swap`: Swaps two stored values in the Heap.
- `heapSort`: Sorts values in an int array by putting them onto a heap and then removing them from the heap in order.
- `changeKey`: Changes the value of an element in the Heap


## Testing

There is a test program to test the correctness of your 
implementation. To build the executables `test`, type `make` at the command line.  Then run each of the tests and confirm the outputs match what are in the "test_out.txt" file. 
```
$ make
$ ./test
```

Your code should work correctly for all tests and be robust for potential error conditions, and free of dangerous code constructs and memory leaks. 
We will use tools like [cppcheck](https://cppcheck.sourceforge.io/) and [valgrind](https://valgrind.org/) to to grade your code and catch memory leaks. 

## Submission
You have to upload heap.h and heap.cpp into gradescope for autograding. You don't need to upload anything in canvas. 
