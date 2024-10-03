/**
*
* DoublyLinkedList.cpp : This is the file with DoublyLinkedList class, and also the methods like: insert at head, insert at tail,
* findNode, deleteNode, moveToHead, moveToTail, deleteHeadNode, deleteTailNode, PrintList, reversePrintList, deleteList, toVector, and toReverseVector.
*
* 01/01/24 - Created by Chirayu Jain
* 01/01/24 - Modified by Chirayu Jain
*/

#include "DoublyLinkedList.hpp"
#include <iostream> // Required for std::cout and std::endl
#include <vector>   // Required for std::vector


// Default constructor initializes an empty list
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// Insert a new node at the head of the list
void DoublyLinkedList::insertAtHead(Node* newNode) {
    if (newNode == nullptr) return;

    if (head == nullptr) { // If the list is empty
        head = tail = newNode;
    } else {
        newNode->next = head;  // Point new node's next to current head
        head->prev = newNode;  // Set current head's prev to new node
        head = newNode;        // Move head pointer to new node
    }
}

// Insert a new node at the tail of the list
void DoublyLinkedList::insertAtTail(Node* newNode) {
    if (newNode == nullptr) return;

    if (tail == nullptr) { // If the list is empty
        head = tail = newNode;
    } else {
        newNode->prev = tail;  // Point new node's prev to current tail
        tail->next = newNode;   // Set current tail's next to new node
        tail = newNode;        // Move tail pointer to new node
    }
}

// Find a node by its value
Node* DoublyLinkedList::findNode(int value) {
    Node* current = head; // Start from head
    while (current != nullptr) {
        if (current->data == value) {
            return current; // Return the node if found
        }
        current = current->next; // Move to next node
    }
    return nullptr; // Node not found
}

// Delete a specific node from the list
void DoublyLinkedList::deleteNode(Node* existingNode) {
    if (existingNode == nullptr) return;

    if (existingNode == head) {
        deleteHeadNode(); // If the node is head, delete head node
    } else if (existingNode == tail) {
        deleteTailNode(); // If the node is tail, delete tail node
    } else {
        existingNode->prev->next = existingNode->next; // Bypass existingNode
        existingNode->next->prev = existingNode->prev; // Bypass existingNode
        delete existingNode; // Delete the node
    }
}

// Move a node to the head of the list
void DoublyLinkedList::moveToHead(Node* existingNode) {
    if (existingNode == nullptr || existingNode == head) return;

    // Disconnect existingNode from its current position
    if (existingNode == tail) {
        tail = tail->prev; // Move tail pointer if it's the tail
        tail->next = nullptr;
    } else {
        existingNode->prev->next = existingNode->next;
        existingNode->next->prev = existingNode->prev;
    }

    // Insert existingNode at the head
    existingNode->next = head;
    existingNode->prev = nullptr;
    head->prev = existingNode;
    head = existingNode;
}

// Move a node to the tail of the list
void DoublyLinkedList::moveToTail(Node* existingNode) {
    if (existingNode == nullptr || existingNode == tail) return;

    // Disconnect existingNode from its current position
    if (existingNode == head) {
        head = head->next; // Move head pointer if it's the head
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // List is now empty
        }
    } else {
        existingNode->prev->next = existingNode->next;
        existingNode->next->prev = existingNode->prev;
    }

    // Insert existingNode at the tail
    existingNode->prev = tail;
    existingNode->next = nullptr;
    if (tail != nullptr) {
        tail->next = existingNode;
    }
    tail = existingNode;

    // Update head if it was empty
    if (head == nullptr) {
        head = tail;
    }
}

// Delete the head node
void DoublyLinkedList::deleteHeadNode() {
    if (head == nullptr) return; // Empty list

    Node* temp = head; // Store current head
    head = head->next; // Move head pointer to next node
    if (head != nullptr) {
        head->prev = nullptr; // Update new head's prev pointer
    } else {
        tail = nullptr; // List is now empty
    }
    delete temp; // Delete the old head node
}

// Delete the tail node
void DoublyLinkedList::deleteTailNode() {
    if (tail == nullptr) return; // Empty list

    Node* temp = tail; // Store current tail
    tail = tail->prev; // Move tail pointer to previous node
    if (tail != nullptr) {
        tail->next = nullptr; // Update new tail's next pointer
    } else {
        head = nullptr; // List is now empty
    }
    delete temp; // Delete the old tail node
}

// Print the list from head to tail
void DoublyLinkedList::printList() {
    Node* current = head; // Start from head
    while (current != nullptr) {
        std::cout << current->data << " "; // Print current node's data
        current = current->next; // Move to next node
    }
    std::cout << std::endl; // New line after printing
}

// Print the list from tail to head
void DoublyLinkedList::reversePrintList() {
    Node* current = tail; // Start from tail
    while (current != nullptr) {
        std::cout << current->data << " "; // Print current node's data
        current = current->prev; // Move to previous node
    }
    std::cout << std::endl; // New line after printing
}

// Delete all nodes in the list
void DoublyLinkedList::deleteList() {
    Node* current = head; // Start from head
    while (current != nullptr) {
        Node* temp = current; // Store current node
        current = current->next; // Move to next node
        delete temp; // Delete the stored node
    }
    head = tail = nullptr; // Reset head and tail
}

// Convert list to a vector (head to tail)
IntVector* DoublyLinkedList::toVector() {
    IntVector* vec = new IntVector(); // Create a new vector
    Node* current = head; // Start from head
    while (current != nullptr) {
        vec->push_back(current->data); // Add current node's data to vector
        current = current->next; // Move to next node
    }
    return vec; // Return the populated vector
}

// Convert list to a vector (tail to head)
IntVector* DoublyLinkedList::toReverseVector() {
    IntVector* vec = new IntVector(); // Create a new vector
    Node* current = tail; // Start from tail
    while (current != nullptr) {
        vec->push_back(current->data); // Add current node's data to vector
        current = current->prev; // Move to previous node
    }
    return vec; // Return the populated vector
}