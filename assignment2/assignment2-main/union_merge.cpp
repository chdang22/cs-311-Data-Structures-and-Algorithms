/**
 * @brief Implementation of unionLinkedList and mergeLinkedList functions
 */
//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.

#include "linkedlist.h"

/**
    * @brief Assume two linked lists that represent Set A and Set B respectively.
    * Compute the union A U B and return the result as a new linked list.
    *
    * @param LA Input linkedlist A as a set (no duplicated element)
    * @param LB Input linkedlist B as a set (no duplicated element)
    * @return LinkedList return the unioned linkedlist 
    */
LinkedList unionLinkedList(const LinkedList& LA, const LinkedList& LB) {
    //copy LA into new list
    LinkedList L1(LA); // copy first list into new
    Node *temp = LB.front; //assign front of 2nd lsit to temp
    while (temp != nullptr) //loop until null
    {
        if (LA.search(temp->val) == -1)//check if temp val in LA
        {
            L1.addRear(temp->val); //add rear
        }
        temp = temp->next;//move to next node
    }
    return L1; //return list
}

/**
     * @brief Assume two input linked lists, LA and LB, whose elements are both in the non-descending order.
     * This function merges LA and LB into a new linked list (as the return value).
     * The elements in the new list should still be in the non-descending order.
     *
     * @param LA
     * @param LB
     * @return LinkedList
     */
LinkedList mergeLinkedList(const LinkedList& LA, const LinkedList& LB) {
    //self note: three cases: LA reach null, LB reach null, or LA and LB still have elements to iterate thru
    LinkedList LC;
    Node *tempA = LA.front;
    Node* tempB = LB.front;
    while (tempA != nullptr || tempB != nullptr)
    {
        //First list reached nullptr, add elements from the second list
        if (tempA == nullptr)//if first list reach null
        {
            LC.addRear(tempB->val); //add next element of second list to third
            tempB = tempB->next; // move to next node in 2nd list?
        }
        //2nd list has reached nullptr, add element from first list to mergedlist
        else if (tempB == nullptr) // if 2nd list reach null
        {
            LC.addRear(tempA->val); //add element of 1st list to 3rd list
            tempA = tempA->next;
        }
        //asssume LA and LB are sorted, so we only need to chech the front of eahc
        else {

            if (tempA->val <= tempB->val) {
                LC.addRear(tempA->val);
                tempA = tempA->next;
            } else {
                LC.addRear(tempB->val);
                tempB = tempB->next;
            }
        }

    }
    return LC;
}