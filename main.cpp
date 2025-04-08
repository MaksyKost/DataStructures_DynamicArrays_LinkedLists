#include <iostream>   
#include <chrono>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "src/DynamicArray.h"
#include "src/DoublyLinkedList.h"
#include "src/SinglyLinkedList.h"

using namespace std;
using namespace std::chrono;

/*
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
    list.getSize();

    int search_value = 46; //rand() % 10000;
    std::cout << "Szukana liczba: " << search_value << std::endl;

    Node1* result = list.find(search_value);
    if (result) {
        std::cout << "Znaleziono liczbe: " << result->data << std::endl;
    } else {
        std::cout << "Liczba nie zostala znaleziona." << std::endl;
    }
}*/

int seed = 123;

void fancyMenuTitle() {
    system("color 0C");

    std::string title = R"(
 __  __ _____ _   _ _   _ 
|  \/  | ____| \ | | | | |
| |\/| |  _| |  \| | | | |
| |  | | |___| |\  | \_/ |
|_|  |_|_____|_| \_|\___/

            MENU
)";

    for (char c : title) {
        std::cout << c;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void menuArray(Structure *structure) {
    int choice, val, index;
    do {
        cout << "\n--- DynamicArray MENU ---\n";
        cout << "| 1. Utwórz losowo        |\n";
        cout << "| 2. Dodaj na początek    |\n";
        cout << "| 3. Dodaj na koniec      |\n";
        cout << "| 4. Dodaj na indeks      |\n";
        cout << "| 5. Usuń z początku      |\n";
        cout << "| 6. Usuń z końca         |\n";
        cout << "| 7. Usuń z indeksu       |\n";
        cout << "| 8. Znajdź wartość       |\n";
        cout << "| 9. Wyświetl             |\n";
        cout << "| 10. Wyczyść             |\n";
        cout << "| 0. Wyjdź                |\n";
        cout << "---------------------------\n";
        cout << "Twój wybór: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Podaj rozmiar: "; cin >> val;
                structure->fillRandom(val, seed);
                break;
            case 2:
                cout << "Podaj wartość: "; cin >> val;
                structure->addBegin(val);
                break;
            case 3:
                cout << "Podaj wartość: "; cin >> val;
                structure->addEnd(val);
                break;
            case 4:
                cout << "Podaj wartość: "; cin >> val;
                cout << "Podaj indeks: "; cin >> index;
                structure->addIndex(val, index);
                break;
            case 5:
                structure->removeBegin();
                break;
            case 6:
                structure->removeEnd();
                break;
            case 7:
                cout << "Podaj indeks: "; cin >> index;
                structure->removeIndex(index);
                break;
            case 8:
                cout << "Podaj wartość: "; cin >> val;
                index = structure->find(val);
                if (index == -1) cout << "Nie znaleziono.\n";
                else cout << "Znaleziono " << val << " na pozycji: " << index << "\n";
                break;
            case 9:
                structure->print();
                break;
            case 10:
                structure->clear();
                break;
        }

    } while (choice != 0);
}

void menuSLL(SinglyLinkedList& list) {
    int choice, val, index;
    do {
        cout << "\n--- DynamicArray MENU ---\n";
        cout << "| 1. Utwórz losowo        |\n";
        cout << "| 2. Dodaj na początek    |\n";
        cout << "| 3. Dodaj na koniec      |\n";
        cout << "| 4. Dodaj na indeks      |\n";
        cout << "| 5. Usuń z początku      |\n";
        cout << "| 6. Usuń z końca         |\n";
        cout << "| 7. Usuń z indeksu       |\n";
        cout << "| 8. Znajdź wartość       |\n";
        cout << "| 9. Wyświetl             |\n";
        cout << "| 10. Wyczyść             |\n";
        cout << "| 0. Wyjdź                |\n";
        cout << "---------------------------\n";
        cout << "Twój wybór: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Podaj rozmiar: "; cin >> val;
                list.fillRandom(val, seed);
                break;
            case 2:
                cout << "Podaj wartość: "; cin >> val;
                list.addBegin(val);
                break;
            case 3:
                cout << "Podaj wartość: "; cin >> val;
                list.addEnd(val);
                break;
            case 4:
                cout << "Podaj wartość: "; cin >> val;
                cout << "Podaj indeks: "; cin >> index;
                list.addIndex(val, index);
                break;
            case 5:
                list.removeBegin();
                break;
            case 6:
                list.removeEnd();
                break;
            case 7:
                cout << "Podaj indeks: "; cin >> index;
                list.removeIndex(index);
                break;
            case 8:
                cout << "Podaj wartość: "; cin >> val;
                index = list.find(val);
                if (index == -1) cout << "Nie znaleziono.\n";
                else cout << "Znaleziono " << val << " na pozycji: " << index << "\n";
                break;
            case 9:
                list.print();
                break;
            case 10:
                list.clear();
                break;
        }

    } while (choice != 0);
}

void menuDLL(DoublyLinkedList& list1) {
    int choice, val, index;
    do {
        cout << "\n--- DynamicArray MENU ---\n";
        cout << "| 1. Utwórz losowo        |\n";
        cout << "| 2. Dodaj na początek    |\n";
        cout << "| 3. Dodaj na koniec      |\n";
        cout << "| 4. Dodaj na indeks      |\n";
        cout << "| 5. Usuń z początku      |\n";
        cout << "| 6. Usuń z końca         |\n";
        cout << "| 7. Usuń z indeksu       |\n";
        cout << "| 8. Znajdź wartość       |\n";
        cout << "| 9. Wyświetl             |\n";
        cout << "| 10. Wyczyść             |\n";
        cout << "| 0. Wyjdź                |\n";
        cout << "---------------------------\n";
        cout << "Twój wybór: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Podaj rozmiar: "; cin >> val;
                list1.fillRandom(val, seed);
                break;
            case 2:
                cout << "Podaj wartość: "; cin >> val;
                list1.addBegin(val);
                break;
            case 3:
                cout << "Podaj wartość: "; cin >> val;
                list1.addEnd(val);
                break;
            case 4:
                cout << "Podaj wartość: "; cin >> val;
                cout << "Podaj indeks: "; cin >> index;
                list1.insert_at(index, val);
                break;
            case 5:
                list1.removeBegin();
                break;
            case 6:
                list1.removeEnd();
                break;
            case 7:
                cout << "Podaj indeks: "; cin >> index;
                list1.remove_at(index);
                break;
            case 8: {
                    cout << "Podaj wartość: "; cin >> val;
                    Node1* result = list1.find(val);
                    if (result == nullptr) cout << "Nie znaleziono.\n";
                    else cout << "Znaleziono " << val << " na pozycji: " << index << "\n";
                    break;
                }
            case 9:
                list1.print();
                break;
            case 10:
                list1.clear();
                break;
        }

    } while (choice != 0);
}

int main() {
    system("chcp 65001 > nul");
    ArrayList* arr = nullptr;
    SinglyLinkedList* list = nullptr;
    DoublyLinkedList* list1 = nullptr;
    int choice;
    do {
        fancyMenuTitle();
        cout << "|-------- Wybierz opcję --------\n";
        cout << "| 1. Tablica dynamiczna        |\n";
        cout << "| 2. Lista jednokierunkowa     |\n";
        cout << "| 3. Lista jednokierunkowa     |\n";
        cout << "| 0. Wyjdź                     |\n";
        cout << "Twój wybór: ";
        cin >> choice;

        switch (choice) {
            case 1:
                arr = new ArrayList();
                menuArray(arr);
                delete arr;
                arr = nullptr;
                break;
            case 2:
                list = new SinglyLinkedList;
                menuSLL(*list);
                delete list;
                list = nullptr;
                break;
            case 3:
                list1 = new DoublyLinkedList;
                menuDLL(*list1);
                delete list1;
                list1 = nullptr;
                break;
        }

    } while (choice != 0);
    
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