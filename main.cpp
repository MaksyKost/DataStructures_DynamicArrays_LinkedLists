#include <iostream>   
#include <chrono>

#include "src/DynamicArray.h"
#include "src/DoublyLinkedList.h"
#include "src/SinglyLinkedList.h"

using namespace std;
using namespace std::chrono;


void test_operations(DoublyLinkedList& list) {
    std::cout << "Test operacji:" << std::endl;

    // Dodawanie na początek, koniec i losowe miejsce
    list.push_front(1);
    list.push_back(99);
    list.push_back(25);
    list.insert_at(1, 50); // Dodanie na losową pozycję

    list.display();

    /*
    // Usuwanie z początku, końca i losowego miejsca
    list.pop_front();
    list.pop_back();
    list.remove_at(0); // Usunięcie z losowej pozycji

    list.display();
    */
    // Wyszukiwanie
    list.generate_random(10, 250);
    list.display();
    list.getSize();

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
    SinglyLinkedList list1;
    int seed = 123;
    srand(seed);
    list1.fillRandom(10000, seed);

    double total = 0;
    for (int i = 0; i < 10; ++i) {
        total += list1.timeAddEnd();
    }

    std::cout << total / 10 <<"ms"<< std::endl;

}

/*
int main() {
    ArrayList arr;
    arr.fillRandom(10, 5, 12);
    arr.print();
    return 0;
}
*/
/*

// Funkcja mierząca czas operacji
template<typename Function>
double measure_time(Function func) {
    auto start = high_resolution_clock::now();
    func();
    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;
    return elapsed.count();
}

void test_operations_on_array(DynamicArray& array, int size, int seed) {
    cout << "Tablica dynamiczna:" << endl;

    // Generowanie danych
    array.generate_random(size, seed);
    array.display();

    // Pomiar dodawania na koniec
    double add_time = measure_time([&]() {
        array.push_back(9999);
    });
    cout << "Czas dodania elementu na koniec: " << add_time << " s" << endl;

    // Pomiar usuwania z losowego miejsca
    double remove_time = measure_time([&]() {
        array.remove_at(size / 2);
    });
    cout << "Czas usunięcia elementu z losowego miejsca: " << remove_time << " s" << endl;

    // Pomiar wyszukiwania
    int search_value = rand() % 10000;
    double search_time = measure_time([&]() {
        array.find(search_value);
    });
    cout << "Czas wyszukiwania: " << search_time << " s" << endl;
}

void test_operations_on_list(DoublyLinkedList& list, int size) {
    cout << "Lista dwukierunkowa:" << endl;

    // Generowanie danych
    list.generate_random(size);
    list.display();

    // Pomiar dodawania na koniec
    double add_time = measure_time([&]() {
        list.push_back(9999);
    });
    cout << "Czas dodania elementu na koniec: " << add_time << " s" << endl;

    // Pomiar usuwania z losowego miejsca
    double remove_time = measure_time([&]() {
        list.remove_at(size / 2);
    });
    cout << "Czas usunięcia elementu z losowego miejsca: " << remove_time << " s" << endl;

    // Pomiar wyszukiwania
    int search_value = rand() % 10000;
    double search_time = measure_time([&]() {
        list.find(search_value);
    });
    cout << "Czas wyszukiwania: " << search_time << " s" << endl;
}

void menu() {
    DynamicArray array;
    DoublyLinkedList list;
    int choice, size;

    cout << "Podaj rozmiar struktury: ";
    cin >> size;

    do {
        cout << "Menu:\n";
        cout << "1. Testuj tablicę dynamiczną\n";
        cout << "2. Testuj listę dwukierunkową\n";
        cout << "0. Wyjście\n";
        cout << "Wybierz opcję: ";
        cin >> choice;

        switch (choice) {
        case 1:
            test_operations_on_array(array, size);
            break;
        case 2:
            test_operations_on_list(list, size);
            break;
        case 0:
            cout << "Do zobaczenia!\n";
            break;
        default:
            cout << "Niepoprawny wybór, spróbuj ponownie.\n";
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
    */