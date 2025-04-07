#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

struct Node {
    int data;       // Dane przechowywane w węźle
    Node* next;     // Wskaźnik na następny węzeł
    Node* prev;     // Wskaźnik na poprzedni węzeł

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head; // Wskaźnik na początek listy
    Node* tail; // Wskaźnik na koniec listy

public:
    // Konstruktor i destruktor
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Metody operacji
    void push_front(int value); // Dodanie na początek
    void push_back(int value);  // Dodanie na koniec
    void pop_front();           // Usunięcie z początku
    void pop_back();            // Usunięcie z końca
    void remove(int value);     // Usunięcie konkretnej wartości

    // Dostęp i wyświetlanie
    void display() const;       // Wyświetlanie listy
    void display_reverse() const; // Wyświetlanie od końca

    // Generowanie losowych danych
    void generate_random(int size, int seed);
};

#endif // DOUBLYLINKEDLIST_HPP