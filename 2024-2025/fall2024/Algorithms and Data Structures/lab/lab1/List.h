/*
 * Name: Jonathan Tucker
 * Date Submitted: 09/16/24
 * Lab Section: 001
 * Assignment Name: Lab 1: Linked List Based Stacks and Queues
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List
{
	private:
  		Node<T> * start; //pointer to the first node in this list
  		int mySize;  //size (or length) of this list

 	public:
  		List();
  		~List();
  		int size();
  		bool empty();
  		void insertStart(T);
  		void insertEnd(T);
  		void insertAt(T, int);
  		void removeStart();
  		void removeEnd();
  		void removeAt(int);
  		T getFirst();
  		T getLast();
  		T getAt(int);
  		int find(T);

  	//Print the name and this list's size and values to stdout
  	//This function is already implemented (no need to change it)
  	void print(string name)
	{
    		cout << name << ": ";
    		cout << "size = " << size();
    		cout << ", values = ";
    		Node<T> * iterator = start;
    		while(iterator != nullptr)
		{
      			cout << iterator->value << ' ';
      			iterator = iterator->next;
    		}
    		cout << endl;
  	}
}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List()
{
	start = NULL;
	mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List()
{
	int removed = 0;

	if (mySize == 1)
	{
		delete start;
	}
	else
	{
		for (int i = 0; i < mySize; i++)
		{
			Node<T> * temp = start;
			start = start->next;
			delete temp;
			removed++;
		}
	}
}

//Return the size of this list
template <class T>
int List<T>::size()
{
	return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty()
{
	if (mySize == 0)
	{
		return true;
	}
		
	return false;
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value)
{
	Node<T> * nuNode = new Node<T>(value);
	Node<T> * tempH = start;
	start = nuNode;
	start->next = tempH;
	mySize++;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value)
{
	if (mySize == 0)
	{
		start = new Node<T>(value);
	}
	else
	{
		Node<T> * nuNode = new Node<T>(value);
		Node<T> * tempH = start;
	
		while (tempH->next != nullptr)
		{
			tempH = tempH->next;
		}

		tempH->next = nuNode;
	}

	mySize++;
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j)
{
	Node<T> * nuNode = new Node<T>(value);
	Node<T> * tempH = start;

	if (j == 0)
	{
		insertStart(value);
	}
	else
	{
		for (int i = 0; i < mySize; i++)
		{
			if (i == j - 1)
			{
				Node<T> * tempN = tempH->next;
				tempH->next = nuNode;
				nuNode->next = tempN;
			}

			tempH = tempH->next;
		}
	}

	mySize++;
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart()
{
	if (mySize > 0)
	{
		Node<T> * tempH = start;
		start = start->next;
		delete tempH;
		mySize--;
	}
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd()
{
	Node<T> * tempN = start;

        for (int i = 0; i < mySize - 2; i++)
        {
                tempN = tempN->next;
        }

        if (mySize > 1)
        {
                delete tempN->next;
                tempN->next = nullptr;
                mySize--;
        }

        if (mySize == 1)
        {
                delete tempN;
                start = nullptr;
                mySize--;
        }
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j)
{
	Node<T> * tempH = start;
	Node<T> * nodeDelete;
	Node<T> * nodeAfter;

	if (j == 0 && mySize >= 1)
	{
		removeStart();
		mySize--;
	}

	for (int i = 0; i < mySize; i++)
	{
		if (i == j - 1)
		{
			nodeDelete = tempH->next;
			nodeAfter = tempH->next->next;
			tempH->next = nodeAfter;
			delete nodeDelete;
			mySize--;
		}
		else
		{
			tempH = tempH->next;
		}
	}
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst()
{
	if (mySize == 0)
	{
		T temp = T();
		return temp;
	}

	return start->value;
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast()
{
	Node<T> * tempN = start;

	for (int i = 0; i < mySize - 1; i++)
	{
		tempN = tempN->next;
	}

	if (mySize > 0)
	{
		return tempN->value;
	}

	T temp = T();
	return temp;
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j)
{
	Node<T> * tempN = start;

	for (int i = 0; i < mySize; i++)
	{
		if (i == j)
		{
			return tempN->value;
		}

		tempN = tempN->next;
	}

	T temp = T();
	return temp;
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key)
{
	Node<T> * temp = start;
	int pos = 0;
	
	while (temp->next != nullptr)
	{
		if (temp->value == key)
		{
			return pos;
		}

		temp = temp->next;
		pos++;
	}

	if (start->value == key)
	{
		return 0;
	}

	return -1;
}

