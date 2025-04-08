#include "DoublyLinkedList.h"
#include <cstdlib>

// Konstruktor
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// Destruktor
DoublyLinkedList::~DoublyLinkedList() {
    Node1* current = head;
    while (current) {
        Node1* next = current->next;
        delete current;
        current = next;
    }
}

// Dodanie elementu na początek
void DoublyLinkedList::addBegin(int value) {
    Node1* newNode1 = new Node1(value);
    if (!head) {
        head = tail = newNode1;
    } else {
        newNode1->next = head;
        head->prev = newNode1;
        head = newNode1;
    }
}

// Dodanie elementu na koniec
void DoublyLinkedList::addEnd(int value) {
    Node1* newNode1 = new Node1(value);
    if (!tail) {
        head = tail = newNode1;
    } else {
        newNode1->prev = tail;
        tail->next = newNode1;
        tail = newNode1;
    }
}

// Dodawanie nowego elementa o wartości na wskazaną pozycję
void DoublyLinkedList::insert_at(int position, int value) {
    if (position <= 0) {
        addBegin(value);
        return;
    }

    Node1* current = head;
    int index = 0;

    while (current && index < position - 1) {
        current = current->next;
        index++;
    }

    if (!current || !current->next) {
        addEnd(value);
    } else {
        Node1* newNode1 = new Node1(value);
        newNode1->next = current->next;
        newNode1->prev = current;
        current->next->prev = newNode1;
        current->next = newNode1;
    }
}


// Usunięcie elementu z początku
void DoublyLinkedList::removeBegin() {
    if (!head) return;

    Node1* toDelete = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;

    delete toDelete;
}

// Usunięcie elementu z końca
void DoublyLinkedList::removeEnd() {
    if (!tail) return;

    Node1* toDelete = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;

    delete toDelete;
}

// Usunięcie elementu o konkretnej wartości
void DoublyLinkedList::remove(int value) {
    Node1* current = head;
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

// Usunięcie elementu znajdującego się na wskazanej pozycji w liście
void DoublyLinkedList::remove_at(int position) {
    if (position < 0) return;
    if (position == 0) {
        removeBegin();
        return;
    }

    Node1* current = head;
    int index = 0;

    while (current && index < position) {
        current = current->next;
        index++;
    }

    if (!current) return;

    if (current->prev) current->prev->next = current->next;
    if (current->next) current->next->prev = current->prev;

    if (current == head) head = current->next;
    if (current == tail) tail = current->prev;

    delete current;
}

// Przeszukiwanie listy w poszukiwaniu węzła, który przechowuje wartość równą value
Node1* DoublyLinkedList::find(int value) {
    Node1* current = head;
    while (current) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}


// Wyświetlenie listy
void DoublyLinkedList::print() const {
    Node1* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Wyświetlenie listy od końca
void DoublyLinkedList::display_reverse() const {
    Node1* current = tail;
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

// Wyświetlenie ilości węzłów w liscie
int DoublyLinkedList::getSize() const {
    int size{};
    Node1* current = head;
    while (current) {
        size++;
        current = current->next;
    }
    std::cout << size << std::endl;
    return size;
}

// Generowanie losowych danych
void DoublyLinkedList::fillRandom(int size, int seed) {
    srand(seed);
    for (int i = 0; i < size; ++i) {
        addBegin(rand() % 10000); // Losowa liczba z zakresu 0-9999
    }
}