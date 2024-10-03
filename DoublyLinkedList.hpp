/**
*
* DoublyLinkedList.hpp : This is the header file for DoublyLinkedList.
*
* 09/23/24 - Created by ChatGPT
* 09/23/24 - Modified by hhui
*/

#ifndef _DOUBLY_LINKED_LIST
#define _DOUBLY_LINKED_LIST
#include <vector> 

using IntVector = std::vector<int>;

// Define a structure for a node in the doubly linked list
struct Node {
	int data;                                                           // Value stored in the node
	Node* prev;                                                         // Pointer to the previous node
	Node* next;                                                         // Pointer to the next node

	// Constructor to initialize a new node with a value
	Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Define a class for the doubly linked list allowing bi-directional traversal
class DoublyLinkedList {
private:
	Node* head;                                                         // Pointer to the head of the list
	Node* tail;                                                         // Pointer to the tail of the list


public:
	// Default constructor
	DoublyLinkedList();

	// insertAtHead
	void insertAtHead(Node* newNode);

	// insertAtTail
	void insertAtTail(Node* newNode);

	// findNode
	Node* findNode(int value);

	// deleteNode
	void deleteNode(Node* existingNode);

	// moveToHead
	void moveToHead(Node* existingNode);

	// moveToTail
	void moveToTail(Node* existingNode);

	// deleteHeadNode
	void deleteHeadNode();

	// deleteTailNode
	void deleteTailNode();

	// printList
	void printList();

	// reversePrintList
	void reversePrintList();

	// deleteList
	void deleteList();

	// toVector
	IntVector* toVector();

	// toReverseVector
	IntVector* toReverseVector();
}; // end DoublyLinkedList
#endif 