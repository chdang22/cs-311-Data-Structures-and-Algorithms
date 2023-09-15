/**
 * @brief You will implement the "optimized" quick sort algorithms for a linked list in this file
 */
//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.
//You should always comments to each function to describe its PURPOSE and PARAMETERS
#include "sorting.h"

/**
 * Implement a hybrid of insertion sort and quick sort algorithm. The algorithm is based on the idea that if the array is short,
 * it is better to use insertion sort.
 * It uses quicksort until the list gets small enough, and then uses insertion sort or another sort to sort the small lists
 *
 */
void hybridQuickSort(int array[], int lowindex, int highindex, bool reversed) {
    int threshold = 20;

    // Use insertion sort if the sub-array size is smaller than or equal to the threshold
    if (highindex - lowindex + 1 <= threshold) {
        insertionSort(array, lowindex, highindex, reversed);
    } else {
        // Continue with quicksort for larger sub-arrays
        int pivotIndex = partition(array, lowindex, highindex, reversed);
        hybridQuickSort(array, lowindex, pivotIndex - 1, reversed);
        hybridQuickSort(array, pivotIndex + 1, highindex, reversed);
    }
}