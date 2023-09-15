/**
 * Implementation of BST class.
 */
//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.
//You should always comments to each function to describe its PURPOSE and PARAMETERS

// =======================================================
// Your name: ??? Caroline Dang
// Compiler:  g++
// File type: cpp file BST.cpp
// @brief This class implements a BST search tree
//=======================================================

#include "BST.h"
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;
/**
 * Implement the BST constructor
 */
BST::BST() {
    root = nullptr;
    numElements = 0;
}

/**
 * Implement the BST destructor
 */
BST::~BST() {
    // Must release memory correctly to avoid memory leaks
    clear();
}

/**
 * Implement size() correctly
 */
unsigned int BST::size() const {
     return numElements;
}

/**
 * Implement clear() correctly without memory leaks
 */
void BST::clear() {
    release(root);
    numElements = 0;
    root = nullptr;
}

void BST::release(Node *node) {
    if(node == nullptr)
        return;

    //recursively release l and r subtrees
    release(node->leftChild);
    release(node->rightChild);

    delete node; //delete curr

}

/**
 * Implement insert() correctly
 */
bool BST::insert(T element) {
    if (root == nullptr){
        root = new Node(element);
        numElements++;
        return true;
    }


    Node* current = root;
    while (current != nullptr){
        if (element == current->data)
            return false; //bst has no dupes
        else if (element < current->data) {
            if (current->leftChild == nullptr) {
                current->leftChild = new Node(element);
                current->leftChild->parent = current;
                numElements++;
                return true;
            } else {
                current = current->leftChild;
            }
        }
        else if (element > current->data) {
            if (current->rightChild == nullptr) {
                current->rightChild = new Node(element);
                current->rightChild->parent = current;
                numElements++;
                return true;
            } else {
                current = current->rightChild;
            }
        }
    }
    return false;
}

/**
 * Implement find() correctly
 */
bool BST::find(const T &query) const {
    Node* current = root;
    while (current != nullptr){
        if (query == current->data)    //if query is equal to curr node val, found match!
            return true;
        if (query < current->data)
            current = current->leftChild;   //if query is less than root, go left or less than current go left
        else
            current = current->rightChild;   //if q > root or curr then go right
    }
    return false; //if reach this pt, element not in tree
}

/**
 * Implement the height() function correctly
 */
int BST::height() const {
    return height(root);
}

int BST::height(Node *node) const {
    if( node == nullptr) //if empty return -1
        return -1;
    else
       return 1 + max(height(node->leftChild), height(node->rightChild));
}

/**
 * Implement the getRoot() function correctly
 */
BST::Node* BST::getRoot() {
    return root;
}

/**
 * @brief Print the subtree at node using inorder traversal
 * @param node a pointer to node in BST
 */
void BST::printInorder(Node* node) {

    if (node == nullptr)   //if empty return
        return;
    printInorder(node->leftChild);  //process nodes in left subtree
    cout<< node->data <<" ";      //process the current node
    printInorder(node->rightChild); //process nodes in right

}

/**
* @brief Print the subtree at node using preorder traversal
* @param node a pointer to node in BST
*/
void BST::printPreorder(Node* node) {
    //root is visited before left and right subtree
    //steps: 1. current node, nodes in left subtree, nodes in right subtree
    if (node == nullptr)
        return;
    cout<< node->data <<" ";
    printPreorder(node->leftChild);
    printPreorder(node->rightChild);

}

/**
* @brief Print the subtree at node using postorder traversal
* @param node a pointer to node in BST
*/
void BST::printPostorder(Node* node) {
    if (node == nullptr)
        return;
    printPostorder(node->leftChild);
    printPostorder(node->rightChild);
    cout << node->data<<" ";
}

/**
 * Implement the getLeftMostNode() function correctly
 */
BST::Node *BST::getLeftMostNode() {
    
    return getLeftMostNode(root);
}

BST::Node *BST::getLeftMostNode(BST::Node *node) {
    if (node == nullptr) {
        return nullptr;
    }

    while (node->leftChild != nullptr) {
        node = node->leftChild;
    }

    return node;
}


/**
 * Implement the BST successor function correctly
 */
BST::Node *BST::successor(Node *node) {


    if (node->rightChild != nullptr) {
        node = node->rightChild;
        while (node->leftChild != nullptr) {
            node = node->leftChild;
        }
        return node;
    } else {
        Node* parent = node->parent;
        while (parent != nullptr && node == parent->rightChild) {
            node = parent;
            parent = parent->parent;
        }
        return parent;
    }
}

