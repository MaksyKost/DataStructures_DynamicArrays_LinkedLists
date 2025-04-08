#include <iostream>   
#include <chrono>

#include "src/DynamicArray.h"
#include "src/DoublyLinkedList.h"
#include "src/SinglyLinkedList.h"

using namespace std;
using namespace std::chrono;


// Funkcja mierząca czas operacji
template<typename Function>
double measure_time(Function func) {
    auto start = high_resolution_clock::now();
    func();
    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;
    return elapsed.count();
}

void test_operations_on_array(ArrayList& array, int size, int seed) {
    cout << "Tablica dynamiczna:" << endl;

    // Generowanie danych
    array.fillRandom(size, seed);
    array.print();

    // Pomiar dodawania na koniec
    double add_time = measure_time([&]() {
        array.addEnd(9999);
    });
    cout << "Czas dodania elementu na koniec: " << add_time << " s" << endl;

    // Pomiar usuwania z losowego miejsca
    double remove_time = measure_time([&]() {
        array.removeIndex(size / 2);
    });
    cout << "Czas usunięcia elementu z losowego miejsca: " << remove_time << " s" << endl;

    // Pomiar wyszukiwania
    int search_value = rand() % 10000;
    double search_time = measure_time([&]() {
        array.find(search_value);
    });
    cout << "Czas wyszukiwania: " << search_time << " s" << endl;
}

void test_operations_on_list(DoublyLinkedList& list, int size, int seed) {
    cout << "Lista dwukierunkowa:" << endl;

    // Generowanie danych
    list.generate_random(size, seed);
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
    ArrayList array;
    DoublyLinkedList list;
    int choice, size;
    int seed = 250;

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
            test_operations_on_array(array, size, seed);
            break;
        case 2:
            test_operations_on_list(list, size, seed);
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
    const int SIZES[] = {50000, 100000, 150000, 200000, 250000, 300000, 350000, 400000, 450000, 500000}; 
    const int TESTS = 100;
    const int SEED[] = {250}; 
    menu();
    return 0;
}