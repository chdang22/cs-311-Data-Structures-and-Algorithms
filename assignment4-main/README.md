<h1 align="center">CS311 Programming Assignment 4 </h1>
<h2 align="center">Total points: 10</h2>

In this assignment, you will implement some sorting algorithms for arrays. You can work in a group of up to two students. You have to maintain same group for assignment5 as well. 

## Insertion Sort and Quicksort of an array
Implement the insertion sort and quicksort for an integer array. The functions are defined in the "sorting.h" header file.
```
/**
 * @brief Insertion sort algorithm
 * @param array Array to be sorted. The array is modified in place.
 * @param lowindex Lowest index of the array
 * @param highindex Highest index of the array
 * @param reversed If reversed = true, the array should be sorted in descending order, otherwise in ascending order
 */
void insertionSort(int array[], int lowindex, int highindex, bool reversed = false);
```
and
```
**
 * @brief Quick sort algorithm
 * 
 * @param array Array to be sorted. The array is modified in place.
 * @param lowindex Lowest index of the array
 * @param highindex Highest index of the array
 * @param reversed If reversed = true, the array should be sorted in descending order, otherwise in ascending order
 */
void quickSort(int array[], int lowindex, int highindex, bool reversed = false);
```
The array should be sorted in place. Compared to the examples in the textbook, those functions have an additional parameter `reversed`. If reversed = true, the array should be sorted in descending order, otherwise in ascending order. You should complete the implementations of those two functions in the "sorting_basic.cpp" file. 

## A better quicksort algorithm
Quicksort is a very fast comparison sorting algorithm, especially wheb the array or list gets large. However, when the arrays/lists are small enough, quicksort may run slower than some of the Θ(n^2) algorithms.  This might not seem important until you note that when sorting a large array with quicksort, many small sublists must be sorted.  While the savings on sorting one small list with a faster algorithm might be negligible, sorting hundreds of small lists with a faster algorithm can make a difference in the overall efficiency of the sort.  For this part of the assignment, you will combine quicksort with another sorting algorithm to build a faster sorting algorithm. One option is to 
<ul>
<li>use quicksort until the array/list gets small enough, and then use insertion sort or another sort to sort the small arrays/lists </li>
</ul>
What does "small enough" mean?  You can try a percentage of the list (say, 5% or 10%), or an absolute number (5 elements, 8 elements, 10 elements, 15 elements, 100 elements, etc), or something else of your choosing. Based on your tests, choose the one that is the most efficient. You should also tests to ensure that your hybrid quicksort has reasonable performance on all lists -- most notably, it should be efficient on sorted and inverse sorted lists as well as random lists.  

The definition of the hybrid quicksort function is as the following:
```
/**
 * @brief A hybrid of insertion sort and quick sort algorithm. The algorithm is based on the idea that if the array is short, it is better to use insertion sort.
 * It uses quicksort until the list gets small enough, and then uses insertion sort or another sort to sort the small lists
 * 
 * @param array The array to be sorted. The array is modified in place.
 * @param lowindex The lowest index of the array
 * @param highindex The highest index of the array
 * @param reversed if reversed = true, the array should be sorted in descending order, otherwise in ascending order
 */
void hybridQuickSort(int array[], int lowindex, int highindex, bool reversed = false);
```
The implementation of the function should be included in the "sorting_hybrid.cpp" file and the array is sorted in place. The program `test3` tests the performance
of insert sort, quicksort, and hybrid quicksort for an array with 100,000 numbers. Try to test and adjust your hybrid quicksort implementation to beat the performance of regular quicksort.


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
You have to upload print_array.h, print_array.cpp, sorting.h, sorting_basic.cpp, and sorting_hybrid.cpp into gradescope for autograding. Each member has to do this part. You don't need to upload anything in canvas. 
