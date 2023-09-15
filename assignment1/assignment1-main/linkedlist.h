//CS311 LinkedList.h
//INSTRUCTION:
//Linkedlist class - header file template 
//You must complete the  parts and then complete LinkedList.cpp. Delete "" after you are done.
//You should always comments to each function to describe its PURPOSE and PARAMETERS 
#pragma once

// =======================================================
// Your name: Caroline Dang
// Compiler:  g++ 
// File type: headher file  linkedlist.h
//=======================================================
#include <string>
using namespace std;

// Datatype T : element type definition
typedef int T;  // int for now but can change later

//a list node is defined here as a struct Node for now
struct Node {
    T val;   // stored value
    Node *next;  // pointer to the next node

    // Constructor
    Node(T val = 0, Node *next = nullptr) {
        this->val = val;
        this->next = next;
    }
};
//---------------------------------------------------------

class LinkedList {
private:
    Node *front;       // pointer to the front node
    Node *rear;        // pointer to the rear node
    int count;        // the number of nodes in the list

public:
    LinkedList() {     // constructor to create an empty list
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    ~LinkedList();     // destructor to destroy all nodes and release memory

    /**
     * @brief Copy Constructor to allow pass by value and return by value of a LinkedList
     * @param other LinkedList to be copied
     */
    LinkedList(const LinkedList &other);

    /**
     * @brief Overloading of = (returns a reference to a LinkedList)
     * @param other LinkedList to be copied
     * @return reference to a LinkedList
     */
    LinkedList &operator=(const LinkedList &other);


    /**
     * @brief Purpose: Checks if the list is empty
     * @return true if the list is empty, false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief  Get the number of nodes in the list
     * @return int The number of nodes in the list
     */
    int length() const;

    /**
     * @brief Convert the contents of the list to a string
     */
    string toString();

    /**
     * @brief  Displays the contents of the list
     *
     */
    void displayAll();

    /**
     * @brief Adds node with value to front of LL.
     *        Handles list with two cases: empty or not empty
     * @param val the value to be added to the list
     *
     */
    void addFront(T val);

    /**
     * @brief Adds node with value to end of LL.
     *        Handles list with two cases: empty or not empty
     * @param val the value to be added to the list
     *
     */
    void addRear(T val);

    /**
     * @brief Deletes node at front of LL.
     *        Handles list with 3 cases: empty, one element or more than one element
     *        Stores the number in deleted node to OldNum and decreases counter
     *        Returns true if delete sucessfully, reutrn false if list empty
     * @param takes variable to store val from deleted node
     * @return true if deleted
     * @return false if list empty and cannot delete
     */
    bool deleteFront(T &val);

    /**
     * @brief Deletes node at end of LL.
     *        Handles list with 3 cases: empty, one element or more than one element
     *        Stores the number in deleted node to OldNum and decreases counter
     * @param takes variable to store val from deleted node
     * @return true if deleted
     * @return false if list empty and cannot delete
     */
    bool deleteRear(T &val);

    /**
     * @brief Delete a node at a given position from the list. The
     * node at position pos is deleted and the value of the deleted node is returned in val.
     * The valid range of pos is 0 to count-1. pos = 0 for the first node, and pos = count-1 for the last node.
     * @param pos: position of the node to be deleted
     * @param val: it is set to the value of the node to be deleted
     * @return true: if the node was deleted successfully
     * @return false: if the node was not deleted successfully because the position was out of range
    */
    bool deleteAt(int pos, T &val);

    /**
     * @brief Insert a value at a specified position in the list. The valid pos is in the range of 0 to count.
     * The value will be inserted before the node at the specified position. if pos = 0, the value will be inserted
     * at the front of the list. if pos = count, the value will be inserted at the rear of the list.
     * @param pos: position to insert the value at.
     * @param val: value to insert.
     * @return true: if the value was inserted.
     * @return false: if the value was not inserted because pos is out of the range.
     */
    bool insertAt(int pos, T val);
};
