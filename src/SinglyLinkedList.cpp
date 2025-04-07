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
    if (head == nullptr) head = newNode; // jeżeli lista pusta to head -> [val | nullptr] 
    else {
        Node* current = head;
        while (current->next != nullptr) current = current->next;
        current->next = newNode;
    }
    size++;
}

void SinglyLinkedList::addIndex(int index, int val) {
    if (index < 0 || index > size) {
        std::cout << "Error\n";
        return;
    }
    if (index == 0) {
        addBegin(val);
        return;
    }
    if (index == size) {
        addEnd(val);
        return;
    }
    
    Node* newNode = new Node(val);
    Node* current = head;
    for (int i = 0; i < index - 1; i++) current = current->next;
    newNode->next = current->next;
    current->next = newNode;
    size++;
}

void SinglyLinkedList::removeBegin() {
    if (head == nullptr) return;
    Node* oldBegin = head;
    head = head->next;
    delete oldBegin;
    size--;
}

void SinglyLinkedList::removeEnd() {
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    }
    else {
        Node* current = head;
        while (current->next->next != nullptr) current = current->next;
        current->next = nullptr;
        delete current->next;
        current->next = nullptr;
    }
    size--;
}