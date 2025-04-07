#include <iostream>   
#include "src/DynamicArray.h"
#include "src/DoublyLinkedList.h"
using namespace std;

void test_operations(DoublyLinkedList& list) {
    std::cout << "Test operacji:" << std::endl;

    // Dodawanie na początek, koniec i losowe miejsce
    list.push_front(1);
    list.push_back(99);
    list.push_back(25);
    list.insert_at(1, 50); // Dodanie na losową pozycję

    list.display();

    // Usuwanie z początku, końca i losowego miejsca
    list.pop_front();
    list.pop_back();
    list.remove_at(0); // Usunięcie z losowej pozycji

    list.display();

    // Wyszukiwanie
    list.generate_random(10, 250);
    list.display();

    int search_value = 46; //rand() % 10000;
    std::cout << "Szukana liczba: " << search_value << std::endl;

    Node* result = list.find(search_value);
    if (result) {
        std::cout << "Znaleziono liczbe: " << result->data << std::endl;
    } else {
        std::cout << "Liczba nie zostala znaleziona." << std::endl;
    }
}

int main() {
    DoublyLinkedList list;
    test_operations(list);
    return 0;
}

/*
int main() {
    ArrayList arr;
    arr.fillRandom(10, 5, 12);
    arr.print();
    return 0;
}
*/