#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include "SinglyLinkedList.h"
using namespace std::chrono;

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
    }
    size--;
}

void SinglyLinkedList::removeIndex(int index) {
    if (head == nullptr) return;

    if (index < 0 || index >= size) {
        throw std::out_of_range("Invalid index");
    }

    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node* current = head;
        for (int i = 0; i < index - 1; i++) current = current->next;
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
    size--;
}

int SinglyLinkedList::find(int val) const {
    Node* current = head;
    int index = 0;
    while (current != nullptr) {
        if (current->data == val) return index;
        index++;
        current = current->next;
    }
    return -1;
}

void SinglyLinkedList::print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

int SinglyLinkedList::getSize() const {
    return size;
}

void SinglyLinkedList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    size = 0;
}

void SinglyLinkedList::fillRandom(int count, int seed) {
    srand(seed);
    for (int i = size; i < count; i++) {
        int val = rand() % 10000;
        addEnd(val);
    }
}

double SinglyLinkedList::timeAddBegin() {
    auto start = high_resolution_clock::now();
    addBegin(rand() % 10000);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

double SinglyLinkedList::timeAddEnd() {
    auto start = high_resolution_clock::now();
    addEnd(rand() % 10000);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}