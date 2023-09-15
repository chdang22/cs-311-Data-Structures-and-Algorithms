//CS311 stack.h
//INSTRUCTION:
//Stack class - header file template
//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.
//You should always comments to each function to describe its PURPOSE and PARAMETERS

// =======================================================
// Your name: Caroline Dang
// Compiler:  g++
// File type: headher file stack.h
// @brief This file defines a Stack class that is implemented using an array
//=======================================================

#pragma once
#include <iostream>
using namespace std;

/**
 *A template Stack class
 */
template < typename T>
	class Stack
	{
		private:
			// data array
			T * array;
		// Number of elements in use
		int count;
		// allocation size of the array, in number of elements
		int allocation_size;

		/**
		 *@brief Resize the data array to double its allocation size
		 *Make sure to release memory allocation correctly.
		 */
		void resizeArray();
		public:
			// Constructor
			Stack(int capacity = 4);

		// Destructor
		~Stack();

		// Copy constructor
		Stack(const Stack<T> &stk);

		// Assignment operator
		Stack<T> &operator=(const Stack<T> &stk);

		/**
		 *@brief Push a value to the stack.
		 *The array will be resized if it reaches its capcity
		 *@param val Value to be pushed onto the stack
		 */
		void push(const T &val);

		/**
		 *@brief If not empty, removes and gives back the top element;
		 *@param val variable to receive the popped element (by ref)
		 */
		void pop(T & val);

		/**
		 *@brief Returns a reference to the top most element of the stack
		 *@return reference to top element of the stack
		 */
		T &top();

		/**
		 *@brief Check if the stack is empty
		 *@return true if stack is empty
		 */
		bool isEmpty();

		/**
		 *@brief Returns the number of elements in the stack
		 *@return int the number of elements in the stack
		 */
		int size();

		/**
		 *@brief Display the content of the stack
		 */
		void displayAll();

		/**
		 *@brief Clear the stack to make it empty
		 */
		void clearAll();
	};

template < typename T>
	Stack<T>::Stack(int capacity)
	{
        count = 0;
        allocation_size = capacity;
        array = new T[allocation_size];
	}

template < typename T>
	Stack<T>::~Stack()
	{
		delete[] array;
	}



// For a template class, the implementation should be included in the header file.

//@brief Resize the data array to double its allocation size
template < typename T>
	void Stack<T>::resizeArray()
	{
		T *new_array = new T[allocation_size *2];
		for (int i = 0; i < count; i++)
		{
			new_array[i] = array[i];
		}

		allocation_size *= 2;
		delete[] array;
		array = new_array;
	}

// @brief Push a value to the stack.
template < typename T>
	void Stack<T>::push(const T &val)
	{
		if (count == allocation_size){
            resizeArray();
        }
        array[count]=val;
        count++;
	}

// @brief If not empty, removes and gives back the top element;
template < typename T>
	void Stack<T>::pop(T & val)
	{
		if (count == 0)
        {
            cout << "Stack is empty!" << endl;
        }
        else
        {
            val = array[count-1];
            count--;
        }
	}

// @brief Returns a reference to the top most element of the stack
template < typename T>
	T &Stack<T>::top()
	{
		if (count == 0)
        {
            cout << "Stack is empty!" << endl;
            return array[0];
        }
        else
        {
            return array[count-1];
        }
	}

// @brief Check if the stack is empty
template < typename T>
	bool Stack<T>::isEmpty()
	{
        return count == 0;
	}

// @brief Returns the number of elements in the stack
template < typename T>
	int Stack<T>::size()
	{
        return count;
	}

// @brief Display the content of the stack
template < typename T>
	void Stack<T>::displayAll()
	{
		if (count == 0)
		{
			cout << "Stack is empty" << endl;
		}
		else
		{
			for (int i = 0; i < count; i++)
			{
				cout << array[i] << " ";
			}

			cout << endl;
		}
	}

// @brief Clear the stack to make it empty
template < typename T>
	void Stack<T>::clearAll()
	{
        count=0;
	}
// @brief Copy constructor
template < typename T>
	Stack<T>::Stack(const Stack<T> &stk)
	{
		allocation_size = stk.allocation_size;
        count = stk.count;
        array = new T[stk.allocation_size];
        for (int i = 0; i < count; i++)
        {
            array[i] = stk.array[i];
        }
	}

template < typename T>
	Stack<T> &Stack<T>::operator=(const Stack<T> &stk)
	{
		if (this != &stk)
        {
            delete[] array;
            allocation_size = stk.allocation_size;
            count = stk.count;
            array = new T[stk.allocation_size];
            for (int i = 0; i < count; i++)
            {
                array[i]=stk.array[i];
            }
        }
		return * this;
	}
