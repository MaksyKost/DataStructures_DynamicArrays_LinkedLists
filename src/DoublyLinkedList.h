#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

struct Node1 {
    int data;       // Dane przechowywane w węźle
    Node1* next;     // Wskaźnik na następny węzeł
    Node1* prev;     // Wskaźnik na poprzedni węzeł

    Node1(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node1* head; // Wskaźnik na początek listy
    Node1* tail; // Wskaźnik na koniec listy

public:
    // Konstruktor i destruktor
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Metody operacji
    void addBegin(int value);     // Dodanie na początek
    void addEnd(int value);      // Dodanie na koniec
    void insert_at(int position, int value);  // Dodawanie nowego elementa o wartości na wskazaną pozycję 
    void removeBegin();               // Usunięcie z początku
    void removeEnd();                // Usunięcie z końca
    void remove(int value);         // Usunięcie konkretnej wartości
    void remove_at(int position);   // Usunięcie elementu znajdującego się na wskazanej pozycji w liście
    Node1* find(int value);          // Przeszukiwanie listy w poszukiwaniu węzła, który przechowuje wartość równą value

    // Dostęp i wyświetlanie
    void print() const;           // Wyświetlanie listy
    void display_reverse() const;   // Wyświetlanie od końca

    int getSize() const;               // Wyświetlenie ilości węzłów w liscie

    // Generowanie losowych danych
    void generate_random(int size, int seed);
};

#endif // DOUBLYLINKEDLIST_HPP