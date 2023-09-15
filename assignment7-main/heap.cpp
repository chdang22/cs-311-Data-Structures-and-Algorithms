#include "heap.h"

// @brief gets the maximum value in the heap
// @return the highest value integer in the heap
int Heap::getMax() const {
    if (count == 0)
        return -1;
    return heaparray[0];
}


// @brief default constructor. Construct an empty heap with initial capacity
Heap::Heap(int size) {
    capacity = size;
    heaparray = new int[size];
    count = 0;
}

// @brief destructor
Heap::~Heap() {
    delete[] heaparray;
}

/**
 * @brief constructor to build a heap from an array of values
 * @param values array of values to be added to the heap
 * @param length the size of the array
 */
Heap::Heap(int *values, int length) {
    this->capacity = length;
    this->heaparray = values;
    this->count = length;
}

/**
 * @brief Copy constructor to build a heap from another heap
 * @param the heap to be copied
 */
Heap::Heap(const Heap& heap) {
    capacity = heap.capacity;
    for (int i = 1; i <= heap.count; i++)
    {
        heaparray[i - 1] = heap.heaparray[i - 1];
    }
    count = heap.count;
}

/**
  * @brief assignment operator to set one heap to another
  * @param the heap that you want to set your heap to
  */
Heap& Heap::operator = (const Heap& heap)
{
    if (this != &heap)
    {
        capacity = heap.capacity;
        for (int i = 1; i <= heap.count; i++)
        {
            heaparray[i - 1] = heap.heaparray[i - 1];
        }
        count = heap.count;
    }
    return *this;
}

/**
 * @brief   organizes the values in the heap to satisfy heap property.
 */
void Heap::heapify() {

    //percolate down starting at last parent node and i-- to go to the previous node and perccolate dowm
    //so percolate down as we go up the tree
    //for each parent node, percolatedown to ensure its descendants satisft heap property
    //parent index = (i-1)/2
    //bot most rightmost (last  node) = count-1
    //then last parent node = ((count -1)-1)/2 = count-2/2
    for (int i = (count -2)/2; i >= 0; i-- ){
        percolateDown(i);
    }

}

/**
 * @brief  Runs percolate down on the heap for the node stored in index.
 */
void Heap::percolateDown(int index) {

    // Run recursively until the current node is bigger than its children
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    int largestChildIndex = index;       // holds index of child with largest val
    //compare left child with largest first, leftc greater then set as largest.
    //if condition true then next we compare with right, if right is bgger than leftc then it is bigger than leftC and thus larger than orginal largC (which was oringally at index)
    if (leftChildIndex < count && heaparray[leftChildIndex] > heaparray[index])
        largestChildIndex = leftChildIndex;
    //compare right child with largest (could be orignal index or leftchild = largest
    if (rightChildIndex < count && heaparray[rightChildIndex] > heaparray[largestChildIndex])
        largestChildIndex = rightChildIndex;
    //if current node is smaller than largest, swap
    //termination condition
    if (largestChildIndex != index) {
        swap(index, largestChildIndex);
        percolateDown(largestChildIndex);      //recursive percolate down at largest index
    }
}

/**
 * @brief  Runs percolate up on the heap for the node stored in index.
 */
void Heap::percolateUp( int index) {

    // run recursively until the current node is small than its parent
    if (index == 0)
        return;

    int parentIndex = (index-1)/2;
    int childIndex = index;

    // compare child with parent
    if (heaparray[childIndex] > heaparray[parentIndex]){
        swap(childIndex, parentIndex);
        percolateUp(parentIndex);      //recursive percolate up at parent index
    }

}

/**
 * @brief  inserts a value into the heap
 *
 */
void Heap::insert(int value) {
    //check if heap full
    if (count == capacity) //When inserting a new element, we increment the count, and it should not exceed the capacity
    {
        //resize array: make new array of double the capacity and copy
        int newCapacity = capacity*2;
        int* newHeapArray = new int[newCapacity]; //new array with new capacity
        //copy element one by one
        for (int i = 0; i < count; i++)
        {
            newHeapArray[i]=heaparray[i];
        }
        //delete old arr
        delete[] heaparray;

        //update heaparry with newheaparray
        heaparray = newHeapArray;
        //update capacity
        capacity = newCapacity;
    }

    // now we sure we have space, insert at end, and percolate up to ensure heap property
    heaparray[count] = value;   //insert at count (last element is at count-1 so insert after it at coubt)
    count ++;   //increase count after insert
    percolateUp(count - 1); //perc up from last element


}

/**
 * @brief  Removes the max value from the heap
 * @return the value that was removed
 */
int Heap::removeMax() {
    if (count >0)
    {
        //save maxvalue
        int retVal = heaparray[0];
        //copy last node to root
        heaparray[0] = heaparray[count-1];
        count--; //to "remove" last element and exclude it from future heap operations
        percolateDown(0);
        return retVal;

    }else
        return -1;


}

/**
 * @brief  Prints the values in the heap
 */
void Heap::printHeap() {
    int i;
    cout << "[ ";
    for (i = 0; i < count; i++)
        cout << heaparray[i] << " ";
    cout << "]\n";
}

/**
 * @brief  Prints the values in an array
 */
void printArray(int values[], int length) {
    int i;
    cout << "[ ";
    for (i = 0; i < length; i++) {
        cout << values[i] << " ";
    }
    cout << "]\n";
}

/**
 * @brief  Swaps the values in the heap at index1 and index2
 */
void Heap::swap(int index1, int index2) {
    int temp = heaparray[index1];
    heaparray[index1] = heaparray[index2];
    heaparray[index2] = temp;
}

/**
 * @brief  Sorts the values of an array by using the heap
 */
void Heap::heapSort(int values[], int length) {
    cout << "Array Before Sorting: \n";
    printArray(values, length);

    //1: create heap
    Heap tempHeap;
    //insert elements into temp heap
    for (int i = 0; i < length; i++) {
        tempHeap.insert(values[i]);
    }
    //2: remove max(which also calls perc down) and put extracted value in freed up slot of values array. which results in ascending order sorted array
    for (int i = length-1; i >=0 ; i--) //nth slot, n-1 slot n-2 slot till reach 0 slot
    {
        values[i] = tempHeap.removeMax();
    }
    cout << "Array After Sorting: \n";
    printArray(values, length);
}
/**
     * @brief Change the key of the element at position i to the new value.
     *        It maintains the heap property.
     * @param i the position of the element to be decreased
     * @param value the new value
     */
void Heap::changeKey(int i, int new_val) {
    if (i < capacity) {
        heaparray[i] = new_val;
        percolateDown(0);
    }
}
