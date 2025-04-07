#include <iostream>
#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList() : head(nullptr), size(0) {}
SinglyLinkedList::~SinglyLinkedList() {
    clear();
}

void SinglyLinkedList::addBegin(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    size++;
}

void SinglyLinkedList::addEnd(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) head = newNode;
    else {
        Node* current = head;
        while (current->next != nullptr) current = current->next;
        current->next = newNode;
    }
    size++;
}
