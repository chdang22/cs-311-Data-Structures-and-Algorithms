/**
 * Implemention of selected sorting algorithms
 * @file sorting.cpp
 */

#include "sorting.h"
#include <bits/stdc++.h>

using namespace std;

/**
 * Implement the insertionSort algorithm correctly
 */
void insertionSort(int array[], int lowindex, int highindex, bool reversed) {
    int key,j;
    if (!reversed)
    {
        for (int i = lowindex; i <= highindex; i++) {
            key = array[i];
            j = i - 1; //j is item before key
            while (key < array[j] && j >= lowindex) {
                swap(array[j], array[j+1]); //start with key=j+1, and shift key to the left until it key>arr[j]
                j--;
            }
        }
    }else
    {
        for (int i = lowindex; i <= highindex; i++) {
            key = array[i];
            j = i - 1;
            while (key > array[j] && j >= lowindex) {
                swap(array[j], array[j+1]);
                j--;
            }
        }
    }
}

/**
 * @brief Implementation of the partition function used by quick sort
 * 
 */
int partition(int array[], int lowindex, int highindex, bool reversed) {
    // TODO: Add your code here
    int mid = lowindex + (highindex - lowindex) / 2;

    if ((array[lowindex] > array[mid] && array[lowindex] < array[highindex]) ||
        (array[lowindex] < array[mid] && array[lowindex] > array[highindex])) {
        swap(array[lowindex], array[mid]);
    } else if ((array[mid] > array[lowindex] && array[mid] < array[highindex]) ||
               (array[mid] < array[lowindex] && array[mid] > array[highindex])) {
        swap(array[mid], array[highindex]);
    }

    int pivot = array[highindex];
    int lo = lowindex;                  //lo pt to lowindex
    int hi = highindex-1;               //hi pt to highindex-1(exclude pivot)

    if(!reversed) {
        while (lo <= hi)                      //
        {
            while (array[lo] <= pivot && lo<=hi)       //incr lo until element at lo <=pivot
                lo++;
            while (array[hi] >= pivot && lo<=hi)         //decr hi until arr[hi] >pivot
                hi--;
            if (lo < hi)
                swap(array[lo], array[hi]);

        }
    }else{
        while (lo <= hi)                      //
        {
            while (lo <= hi && array[lo] >= pivot)
                lo++;
            while (lo <= hi && array[hi] < pivot)
                hi--;
            if (lo < hi)
                swap(array[lo], array[hi]);

        }

    }
    swap(array[lo], array[highindex]);
    return lo;//returb pivot index
}

/**
 * Implement the quickSort algorithm correctly
 */
void quickSort(int array[], int lowindex, int highindex, bool reversed) {
    // TODO: Add your code here
    if (lowindex<highindex){
        int pivotIndex = partition(array, lowindex,highindex,reversed);
        //recursive call
        quickSort(array,lowindex,pivotIndex-1,reversed);
        quickSort(array, pivotIndex+1, highindex, reversed);
    }

}


