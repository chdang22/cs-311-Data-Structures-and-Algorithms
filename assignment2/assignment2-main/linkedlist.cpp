/**
 * @brief The implementation of the Linked List data structure
 */

//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.

//- Make sure description and PARAMETER comments are given in detail
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//  Add sufficient comments to your code body to describe what it does.
//      - Make sure all if-then-else are commented describing which case it is
//      - Make sure all local variables are described fully with their purposes

// ====================================================
//Your name: Caroline Dang
//Complier:  g++
//File type: linkedList.cpp implementation file
//=====================================================

#include<iostream>
#include"linkedlist.h"

using namespace std;

/**
 * @brief Destructor to destroy all nodes and release memory
 */
LinkedList::~LinkedList() {
    Node *temp1 = front; //temp1 point to head of list
    while (temp1 != nullptr) {
        Node *temp2 = temp1->next; //temp2 point to temp1 next
        delete temp1; // delete temp1
        temp1 = temp2; //now temp1 is pt to where temp2 is
    }
}
/**
 * @brief Purpose: Checks if the list is empty
 * @return true if the list is empty, false otherwise
 */
bool LinkedList::isEmpty() const {
    return count == 0;
}

/**
 * @brief  Get the number of nodes in the list
 * @return int The number of nodes in the list
 */
int LinkedList::length() const{
    return count;
}

/**
 * @brief Convert the list to a string
 *
 */
string LinkedList::toString() {
    string str = "[";
    Node *ptr = front;
    if (ptr != nullptr) {
        // Head node is not preceded by separator
        str += to_string(ptr->val);
        ptr = ptr->next;
    }
    while (ptr != nullptr) {
        str += ", " + to_string(ptr->val);
        ptr = ptr->next;
    }
    str  += "]";
    return str;
}

/**
 * @brief Displays the contents of the list
 */
void LinkedList::displayAll() {
    cout << toString() << endl;
}

/**
 * @brief Adds node with value to end of LL.
 *        Handles list with two cases: empty or not empty
 * @param val the value to be added to the list
 *
 */
void LinkedList::addRear(T val) {
    // consider the two cases of whether the list was empty
    if (isEmpty()){
        front = new Node(val); //create new node and assign to front
        rear= front; //asign front to rear

    }else {
        rear->next = new Node(val); //crate new nodeval and assign to rear next
        rear= rear->next;//move rear to rears next
    }
    count++;
}

/**
 * @brief Adds node with value to front of LL.
 *        Handles list with two cases: empty or not empty
 * @param val the value to be added to the list
 *
 */
void LinkedList::addFront(T val) {
    //when list empty: create new node, assign front to rear, increase count
    if (isEmpty()) {
        front = new Node(val);
        rear = front;

    } else {
        // consider the two cases of whether the list was empty
        //when list not empty: front to temp node, create new node assisgn to front, assign temp as front next, increment counter
        Node *temp = front;
        front = new Node(val);
        front->next = temp;
    }
    count++;
}

/**
 * @brief Deletes node at front of LL.
 *        Handles list with 3 cases: empty, one element or more than one element
 *        Stores the number in deleted node to OldNum and decreases counter
 *        Returns true if delete sucessfully, reutrn false if list empty
 * @param takes variable to store val from deleted node
 * @return true if deleted
 * @return false if list empty and cannot delete
 */
bool LinkedList::deleteFront(T &OldNum) {
    //if list empty return false, cant delete empty list
    if(isEmpty()){
        return false;
    }else if(count == 1){//if list has exactly one element: get front val into oldnum, delete front, set fron rear,count
        OldNum=front->val; // val into oldnum
        delete front; //delete front
        //set front rear count
        front = nullptr;
        rear = nullptr;
        count = 0;
        return true;
    }else {
        //if list has more than one element
        //asssign front ot tmep, move front to front nedxt. get temp val into oldnum
        Node *temp = front;
        front = front->next;
        OldNum = temp->val;
        delete temp;//delete temp
        count--;//decrease couinter
        return true;
    }


    // consider if the list was empty and return false if the list is empty
    // consider the special case of deleting the only node in the list
}

/**
 * @brief Deletes node at end of LL.
 *        Handles list with 3 cases: empty, one element or more than one element
 *        Stores the number in deleted node to OldNum and decreases counter
 * @param takes variable to store val from deleted node
 * @return true if deleted
 * @return false if list empty and cannot delete
 */
bool LinkedList::deleteRear(T &OldNum) {
    // consider if the list was empty and return false if the list is empty
    // consider the special case of deleting the only node in the list
    if(isEmpty()){
        return false;
    }else if(count == 1){//if list has exactly one element: get front val into oldnum, delete front, set fron rear,count
        OldNum=front->val; // val into oldnum
        delete front; //delete front
        //set front rear count
        front = nullptr;
        rear = nullptr;
        count = 0;
        return true;
    }else {
        //if list has more than one element
        //asssign front ot tmep, move temp node to just before rear node. get rear val into oldnum
        //delete rear
        //asign temp to rear, assign nullptr to rear next and decrement count
        Node *temp = front;
        while(temp->next != rear){
            temp = temp->next;
        } // now temp points at rear prev
        OldNum = rear->val; // hold old val
        delete rear;
        rear = temp; // new rear bc deleted old rear
        rear->next = nullptr;
        count--;
        return true;
    }
}


/* --- harder ones for test 2 and 3 -- */

/**
 * @brief Delete a node at a given position from the list. The
 * node at position pos is deleted and the value of the deleted node is returned in val.
 * The valid range of pos is 1 to count. pos = 1 is the first node, and pos = count is the last node.
 * @param pos: position of the node to be deleted
 * @param val: it is set to the value of the node to be deleted
 * @return true: if the node was deleted successfully
 * @return false: if the node was not deleted successfully because the position was out of range
*/
bool LinkedList::deleteAt(int pos, T &val) {

    //check pos valid
    if (pos>count-1 || pos <0) {return false;}
    else if (pos ==0) {deleteFront(val);} // if pos 0 add to front
    else if (pos == count-1) {deleteRear(val);}//is pos is count, add to rear
    else {

        Node *temp1 = front;//assign front to temp
        for (int i =0; i<pos-1; i++){//move temp to before at pos
            temp1=temp1->next;
        }
        val = temp1->next->val;
        Node *temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        count--;
        return true;
    }

}

/**
 * @brief Insert a value at a specified position in the list. The valid pos is in the range of 1 to count+1.
 * The value will be inserted before the node at the specified position. if pos = 1, the value will be inserted
 * at the front of the list. if pos = count+1, the value will be inserted at the rear of the list.
 * @param pos: position to insert the value at.
 * @param val: value to insert.
 * @return true: if the value was inserted.
 * @return false: if the value was not inserted because pos is out of the range.
 */
bool LinkedList::insertAt(int pos, T val) {

    //check pos valid
    if (pos>count || pos <0) {return false;}
    else if (pos ==0) {addFront(val);} // if pos 0 add to front
    else if (pos == count) {addRear(val);}//is pos is count, add to rear
    else {

        Node *temp = front;//assign front to temp
        for (int i =0; i<pos-1; i++){//move temp to at pos
            temp=temp->next;
        }
        Node *newNode = new Node(val);//new node
        newNode->next = temp->next;//assign temp next ot newnode next
        temp->next = newNode;
        count++;
        return true;
    }

}

/**
 * @brief Copy Constructor to allow pass by value and return by value of a LinkedList
 * @param other LinkedList to be copied
 */
LinkedList::LinkedList(const LinkedList &other) {
    // Start with an empty list
    front = nullptr;
    rear = nullptr;
    count = 0;
    Node *ptr = other.front;//start with front ptr of other node
    while (ptr != nullptr)
    { //until front ptr to nullptr
        addRear (ptr->val); //call addRear
        ptr = ptr->next; //move ptr to next
    }
    // for each node in the other list. The new node should have the same value as the other node.

}

/**
 * @brief Overloading of = (returns a reference to a LinkedList)
 * @param other LinkedList to be copied
 * @return reference to a LinkedList
 */

/**
 * @brief Overloading of = (returns a reference to a LinkedList)
 * @param other LinkedList to be copied
 * @return reference to a LinkedList
 */
LinkedList &LinkedList::operator=(const LinkedList &other) {
    if(this != &other) { // check if the same object
        // Delete all nodes in this list

        Node *temp1 = front;
        while (temp1 != nullptr) {
            Node *temp2 = temp1->next; //temp2 point to temp1 next
            delete temp1; // delete temp1
            temp1 = temp2; //now temp1 is pt to where temp2 is
        }
        //-----Q: WHY NOT CALL THE DESTRUCTOR???
        // Interate through the other list and add a new node to this list
        // Be sure to set the front and rear pointers to the correct values
        // Be sure to set the count to the correct value

        front = nullptr;
        rear = nullptr;
        count = 0;
        Node *ptr = other.front;
        while (ptr != nullptr){
            addRear(ptr->val);
            ptr = ptr->next;
        }
        return *this;
    }
    return *this;
}

/**
 * Implement the search function.
 * @param int: value to be searched in LL
 * @return int: the position of the value in the list. If the value is not in the list, return -1.
 */
 int LinkedList::search(const T& val) const {
    Node *temp = front;
    int pos = 0;
    while (temp != nullptr)
    {
        if (temp->val == val)
        {
            return pos;
        }
        else
        {
            temp = temp->next;
            pos++;
        }
    }
    return -1;
}

