#include <iostream>   
#include "src/DynamicArray.h"
#include "src/SinglyLinkedList.h"
//#include "src/DoublyLinkedList.h"
using namespace std;

/*void test_operations(DoublyLinkedList& list) {
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
}*/

int main() {
    /*DoublyLinkedList list;
    test_operations(list);*/

    SinglyLinkedList list1;
    list1.addBegin(15);
    list1.print();
    /*list1.addBegin(7);
    list1.addBegin(98);
    list1.addBegin(26);
    list1.print();
    list1.addEnd(32);
    list1.print();
    list1.addIndex(3, 17);
    list1.print();
    list1.removeBegin();
    list1.print();
    list1.removeEnd();
    list1.print();
    list1.removeIndex(2);
    list1.print();
    list1.find(55);
    list1.getSize();
    list1.clear();
    list1.print();
    return 0;*/
    list1.fillRandom(10, 6);
    list1.print();
}

/*
int main() {
    ArrayList arr;
    arr.fillRandom(10, 5, 12);
    arr.print();
    return 0;
}
*/