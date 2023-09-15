#include "sorting.h"
#include "print_array.h"
#include <chrono>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Function to print the run time for a specific sorting algorithm
    auto printRuntime = [](const string &sortType, double runtime) {
        cout << "Time for " << sortType << ": " << runtime << " seconds" << endl;
    };

    const int numTests = 50;
    const int maxArraySize = 500000;

    for (int testNum = 1; testNum <= numTests; ++testNum) {
        int arraySize = maxArraySize * testNum / numTests;

        cout << "**** Test " << testNum << " ****" << endl;
        cout << "Array size: " << arraySize << endl;

        // Create random arrays with random integers
        int *randomArray1= new int[arraySize];
        int *randomArray2 = new int [arraySize];
        for (int i = 0; i < arraySize; i++) {
            randomArray1[i] = rand() % arraySize;
        }
        // randomArray2 for quicksort
        copy(randomArray1, randomArray1 + arraySize,randomArray2 );

        // Measure the time for insertion sort on the random array
        auto t1 = chrono::high_resolution_clock::now();
        insertionSort(randomArray1, 0, arraySize - 1, false);
        auto t2 = chrono::high_resolution_clock::now();
        chrono::duration<double> runtime = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
        printRuntime("insertion sort (random)", runtime.count());

        // Measure the time for quick sort on the random array
        t1 = chrono::high_resolution_clock::now();
        quickSort(randomArray2, 0, arraySize - 1, false);
        t2 = chrono::high_resolution_clock::now();
        runtime = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
        printRuntime("quick sort (random)", runtime.count());

        // Measure the time for insertion sort on the ascending array (randarr1)
        t1 = chrono::high_resolution_clock::now();
        insertionSort(randomArray1, 0, arraySize - 1, false);
        t2 = chrono::high_resolution_clock::now();
        runtime = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
        printRuntime("insertion sort (ascending)", runtime.count());

        // Measure the time for quick sort on the ascending array (randarr2)
        t1 = chrono::high_resolution_clock::now();
        quickSort(randomArray2, 0, arraySize - 1, false);
        t2 = chrono::high_resolution_clock::now();
        runtime = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
        printRuntime("quick sort (ascending)", runtime.count());

        // Reverse random arrays (ascending) to descending
        reverse(randomArray1, randomArray1 + arraySize);
        reverse(randomArray2, randomArray2 + arraySize);

        // Measure the time for insertion sort on the descending array
        t1 = chrono::high_resolution_clock::now();
        insertionSort(randomArray1, 0, arraySize - 1, false);
        t2 = chrono::high_resolution_clock::now();
        runtime = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
        printRuntime("insertion sort (descending)", runtime.count());

        // Measure the time for quick sort on the descending array
        t1 = chrono::high_resolution_clock::now();
        quickSort(randomArray2, 0, arraySize - 1, false);
        t2 = chrono::high_resolution_clock::now();
        runtime = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
        printRuntime("quick sort (descending)", runtime.count());

        // Delete arrays to free up space
        delete[] randomArray1
        delete[] randomArray2
    }
}