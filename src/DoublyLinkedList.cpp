#include "DoublyLinkedList.h"
#include <cstdlib>
#include <ctime>

// Konstruktor
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// Destruktor
DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Dodanie elementu na początek
void DoublyLinkedList::push_front(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Dodanie elementu na koniec
void DoublyLinkedList::push_back(int value) {
    Node* newNode = new Node(value);
    if (!tail) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

// Usunięcie elementu z początku
void DoublyLinkedList::pop_front() {
    if (!head) return;

    Node* toDelete = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;

    delete toDelete;
}

// Usunięcie elementu z końca
void DoublyLinkedList::pop_back() {
    if (!tail) return;

    Node* toDelete = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;

    delete toDelete;
}

// Usunięcie elementu o konkretnej wartości
void DoublyLinkedList::remove(int value) {
    Node* current = head;
    while (current) {
        if (current->data == value) {
            if (current->prev) current->prev->next = current->next;
            else head = current->next;

            if (current->next) current->next->prev = current->prev;
            else tail = current->prev;

            delete current;
            return;
        }
        current = current->next;
    }
}

// Wyświetlenie listy
void DoublyLinkedList::display() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Wyświetlenie listy od końca
void DoublyLinkedList::display_reverse() const {
    Node* current = tail;
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

// Generowanie losowych danych
void DoublyLinkedList::generate_random(int size, int seed) {
    srand(seed);
    for (int i = 0; i < size; ++i) {
        push_back(rand() % 10000); // Losowa liczba z zakresu 0-9999
    }
}