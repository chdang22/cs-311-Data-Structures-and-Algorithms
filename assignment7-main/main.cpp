#include <iostream>
#include "heap.h"

using namespace std;

// Menu to try your Heap functions
int menu();

int main() {

    int ans, i, val;
    Heap* heapPtr = new Heap;
    int arr[] = { 10, 3, 1, 2, 8, 13, 4, 7, 20, 19, 16 };
    int n = sizeof(arr) / sizeof(arr[0]);
    heapPtr->insert(3);
    heapPtr->insert(2);
    heapPtr->insert(1);
    heapPtr->insert(15);
    heapPtr->insert(5);
    heapPtr->insert(4);
    heapPtr->insert(45);

    do
    {
        ans = menu();
        switch (ans)
        {
        case 1:
            // Get value to insert.
            cout << "Enter a value to insert.\n";
            cin >> val;
            heapPtr->insert(val);
            break;

        case 2:
            cout << "The maximum value removed is: " << heapPtr->removeMax() << "\n";
            heapPtr->printHeap();
            break;

        case 3:
            cout << "The maximum value is: " << heapPtr->getMax() << "\n";
            heapPtr->printHeap();
            break;

        case 4:
            cout << "Enter the index and new value for that index.\n";
            cin >> i >> val;
            heapPtr->changeKey(i, val);
            break;

        case 5:
            // Heap sort
            heapPtr->heapSort(arr, n);
            break;

        case 6:
            // Print all values
            heapPtr->printHeap();
            break;

        case 7:
            // Clean up.
            delete heapPtr;
            return 0;
        }
    } while (1);
    return 0;
}

int menu()
{
    int ans;
    cout << "Here are your choices.\n";
    cout << "1. Insert an item into your heap.\n";
    cout << "2. Remove/delete the maximum item from your heap.\n";
    cout << "3. Get the maximum item in your heap.\n";
    cout << "4. Decrease an item key/value in your heap.\n";
    cout << "5. Run Heap Sort.\n";
    cout << "6. Print heap.\n";
    cout << "7. Quit.\n";
    cin >> ans;
    return ans;
}

