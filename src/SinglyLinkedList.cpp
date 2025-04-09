#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include "SinglyLinkedList.h"
using namespace std::chrono;

SinglyLinkedList::SinglyLinkedList() : head(nullptr), size(0) {} // konstruktor
SinglyLinkedList::~SinglyLinkedList() { // destruktor
    clear();
}

void SinglyLinkedList::addBegin(int val) { // dodaje na początku
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    size++;
}

void SinglyLinkedList::addEnd(int val) { // dodaje na końcu
    Node* newNode = new Node(val);
    if (head == nullptr) head = newNode; // jeżeli lista pusta to head -> [val | nullptr] 
    else {
        Node* current = head;
        while (current->next != nullptr) current = current->next;
        current->next = newNode;
    }
    size++;
}

void SinglyLinkedList::addIndex(int index, int val) { // dodaje na miejsce
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

void SinglyLinkedList::removeBegin() { // usuwa na początku
    if (head == nullptr) return;
    Node* oldBegin = head;
    head = head->next;
    delete oldBegin;
    size--;
}

void SinglyLinkedList::removeEnd() { // usuwa na końcu
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

void SinglyLinkedList::removeIndex(int index) { // usuwa na pozycji
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

int SinglyLinkedList::find(int val) const { // wyszukiwanie
    Node* current = head;
    int index = 0;
    while (current != nullptr) {
        if (current->data == val) return index;
        index++;
        current = current->next;
    }
    return -1;
}

void SinglyLinkedList::print() const { // wyświetlenie
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

int SinglyLinkedList::getSize() const { // zwraca rozmiar
    return size;
}

void SinglyLinkedList::clear() { // czyśczy tablicę
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    size = 0;
}

void SinglyLinkedList::fillRandom(int count, int seed) { // wypełnia tablicę
    srand(seed);
    for (int i = size; i < count; i++) {
        int val = rand() % 10000;
        addEnd(val);
    }
}