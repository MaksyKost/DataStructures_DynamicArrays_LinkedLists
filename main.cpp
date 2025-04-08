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

int seed = 123;

void fancyMenuTitle() {
    system("color 0C");

    std::string title = R"(
 __  __ _____ _   _ _   _ 
|  \/  | ____| \ | | | | |
| |\/| |  _| |  \| | | | |
| |  | | |___| |\  | \_/ |
|_|  |_|_____|_| \_|\___/
)";

    for (char c : title) {
        std::cout << c;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void menuArray(Structure *structure) {
    int choice, val, index;
    do {
        cout << "\n------- DynamicArray MENU ------\n";
        cout << "| 1. Utwórz losowo             |\n";
        cout << "| 2. Dodaj na początek         |\n";
        cout << "| 3. Dodaj na koniec           |\n";
        cout << "| 4. Dodaj na indeks           |\n";
        cout << "| 5. Usuń z początku           |\n";
        cout << "| 6. Usuń z końca              |\n";
        cout << "| 7. Usuń z indeksu            |\n";
        cout << "| 8. Znajdź wartość            |\n";
        cout << "| 9. Wyświetl                  |\n";
        cout << "| 10. Wyczyść                  |\n";
        cout << "| 0. Wyjdź                     |\n";
        cout << "--------------------------------\n";
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
        cout << "\n------- Single Linked List MENU -------\n";
        cout << "| 1. Utwórz losowo                    |\n";
        cout << "| 2. Dodaj na początek                |\n";
        cout << "| 3. Dodaj na koniec                  |\n";
        cout << "| 4. Dodaj na indeks                  |\n";
        cout << "| 5. Usuń z początku                  |\n";
        cout << "| 6. Usuń z końca                     |\n";
        cout << "| 7. Usuń z indeksu                   |\n";
        cout << "| 8. Znajdź wartość                   |\n";
        cout << "| 9. Wyświetl                         |\n";
        cout << "| 10. Wyczyść                         |\n";
        cout << "| 0. Wyjdź                            |\n";
        cout << "---------------------------------------\n";
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
        cout << "\n------- Doubly Linked List MENU -------\n";
        cout << "| 1. Utwórz losowo                      |\n";
        cout << "| 2. Dodaj na początek                  |\n";
        cout << "| 3. Dodaj na koniec                    |\n";
        cout << "| 4. Dodaj na indeks                    |\n";
        cout << "| 5. Usuń z początku                    |\n";
        cout << "| 6. Usuń z końca                       |\n";
        cout << "| 7. Usuń z indeksu                     |\n";
        cout << "| 8. Znajdź wartość                     |\n";
        cout << "| 9. Wyświetl                           |\n";
        cout << "| 10. Wyczyść                           |\n";
        cout << "| 0. Wyjdź                              |\n";
        cout << "-----------------------------------------\n";
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
                list1.addIndex(index, val);
                break;
            case 5:
                list1.removeBegin();
                break;
            case 6:
                list1.removeEnd();
                break;
            case 7:
                cout << "Podaj indeks: "; cin >> index;
                list1.removeIndex(index);
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
        cout << "--------  Wybierz opcję --------\n";
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