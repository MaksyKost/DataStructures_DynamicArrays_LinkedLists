#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <string>

#include "src/DynamicArray.h"
#include "src/DoublyLinkedList.h"
#include "src/SinglyLinkedList.h"

using namespace std;
using namespace std::chrono;

// Funkcja mierząca czas wykonywania operacji
template<typename Function>
double measure_time(Function func) {
    auto start = high_resolution_clock::now();
    func();
    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;
    return elapsed.count();
}

int main() {
    // Definicje rozmiarów tablicy i seedów
    const int SIZES[] = {50000, 100000, 150000, 200000, 250000, 300000, 350000, 400000, 450000, 500000};
    const int SIZES1[] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
    const int TESTS = 100;
    const int SEEDS[] = {250, 300, 350, 400, 450, 500, 550, 600, 650, 700};

    // Otwarcie plików do zapisu wyników
    ofstream daFile("results/DynamicArrayResults.txt");
    ofstream dllFile("results/DoublyLinkedListResults.txt");
    ofstream sllFile("results/SinglyLinkedListResults.txt");

    if (!daFile.is_open() || !dllFile.is_open() || !sllFile.is_open()) {
        cerr << "Nie udało się otworzyć plików do zapisu wyników." << endl;
        return 1;
    }

    // =======================
    // Testy dla tablicy dynamicznej (DynamicArray)
    // =======================
    for (int size : SIZES) {
        cout << "\n\n==== Testowanie tablicy dynamicznej dla rozmiaru: " 
             << size << " elementów ====" << endl;
        daFile << "\n\n==== Testowanie tablicy dynamicznej dla rozmiaru: " 
             << size << " elementów ====" << endl;
        
        double total_da_addBegin    = 0.0;
        double total_da_addEnd      = 0.0;
        double total_da_addIndex    = 0.0;
        double total_da_removeBegin = 0.0;
        double total_da_removeEnd   = 0.0;
        double total_da_removeIndex = 0.0;
        double total_da_find        = 0.0;
        int seedCount = 0;
        
        for (int seed : SEEDS) {
            // Ustawienie globalnego ziarna dla rand()
            srand(seed);
            
            double da_addBegin_sum    = 0.0;
            double da_addEnd_sum      = 0.0;
            double da_addIndex_sum    = 0.0;
            double da_removeBegin_sum = 0.0;
            double da_removeEnd_sum   = 0.0;
            double da_removeIndex_sum = 0.0;
            double da_find_sum        = 0.0;
            
            ArrayList daList;
            
            for (int t = 0; t < TESTS; t++) {
                // Resetujemy tablicę do stanu startowego
                daList.fillRandom(size, seed);
                
                // Pomiar dodania na początek
                int value = rand() % 10000;
                da_addBegin_sum += measure_time([&]() {
                    daList.addBegin(value);
                });
                
                // Pomiar dodania na koniec
                value = rand() % 10000;
                da_addEnd_sum += measure_time([&]() {
                    daList.addEnd(value);
                });
                
                // Pomiar dodania do losowego miejsca
                value = rand() % 10000;
                int index = (daList.getSize() > 0) ? (rand() % daList.getSize()) : 0;
                da_addIndex_sum += measure_time([&]() {
                    daList.addIndex(value, index);
                });
                
                // Reset przed usunięciem z losowego miejsca
                daList.fillRandom(size, seed);
                if (daList.getSize() > 0) {
                    int remove_index = rand() % daList.getSize();
                    da_removeIndex_sum += measure_time([&]() {
                        daList.removeIndex(remove_index);
                    });
                }
                
                // Reset przed usunięciem z początku
                daList.fillRandom(size, seed);
                if (daList.getSize() > 0) {
                    da_removeBegin_sum += measure_time([&]() {
                        daList.removeBegin();
                    });
                }
                
                // Reset przed usunięciem z końca
                daList.fillRandom(size, seed);
                if (daList.getSize() > 0) {
                    da_removeEnd_sum += measure_time([&]() {
                        daList.removeEnd();
                    });
                }
                
                // Pomiar wyszukiwania – przeszukujemy tablicę dla losowo wybranej wartości
                int search_value = rand() % 10000;
                da_find_sum += measure_time([&]() {
                    daList.find(search_value);
                });
            }
            
            // Średnie wyniki dla danego seeda
            total_da_addBegin    += da_addBegin_sum    / TESTS;
            total_da_addEnd      += da_addEnd_sum      / TESTS;
            total_da_addIndex    += da_addIndex_sum    / TESTS;
            total_da_removeIndex += da_removeIndex_sum / TESTS;
            total_da_removeBegin += da_removeBegin_sum / TESTS;
            total_da_removeEnd   += da_removeEnd_sum   / TESTS;
            total_da_find        += da_find_sum        / TESTS;
            seedCount++;
        }
        
        cout << "\n*** Średnie wyniki dla tablicy dynamicznej dla rozmiaru " 
             << size << " (średnia z " << seedCount << " seedów):\n";
        daFile << "\n*** Średnie wyniki dla tablicy dynamicznej dla rozmiaru " 
             << size << " (średnia z " << seedCount << " seedów):\n";
        cout << "  Dodanie na początek:         " << (total_da_addBegin    / seedCount) << " s\n";
        cout << "  Dodanie na koniec:           " << (total_da_addEnd      / seedCount) << " s\n";
        cout << "  Dodanie do losowego miejsca: " << (total_da_addIndex    / seedCount) << " s\n";
        cout << "  Usunięcie z losowego miejsca: " << (total_da_removeIndex / seedCount) << " s\n";
        cout << "  Usunięcie z początku:         " << (total_da_removeBegin / seedCount) << " s\n";
        cout << "  Usunięcie z końca:           " << (total_da_removeEnd   / seedCount) << " s\n";
        cout << "  Wyszukiwanie:                " << (total_da_find        / seedCount) << " s\n";
        
        daFile << "  Dodanie na początek:         " << (total_da_addBegin    / seedCount) << " s\n";
        daFile << "  Dodanie na koniec:           " << (total_da_addEnd      / seedCount) << " s\n";
        daFile << "  Dodanie do losowego miejsca: " << (total_da_addIndex    / seedCount) << " s\n";
        daFile << "  Usunięcie z losowego miejsca: " << (total_da_removeIndex / seedCount) << " s\n";
        daFile << "  Usunięcie z początku:         " << (total_da_removeBegin / seedCount) << " s\n";
        daFile << "  Usunięcie z końca:           " << (total_da_removeEnd   / seedCount) << " s\n";
        daFile << "  Wyszukiwanie:                " << (total_da_find        / seedCount) << " s\n";
    }
    
    // =======================
    // Testy dla listy dwukierunkowej (DoublyLinkedList)
    // =======================
    for (int size : SIZES1) {
        cout << "\n\n==== Testowanie listy dwukierunkowej dla rozmiaru: " 
             << size << " elementów ====" << endl;
        dllFile << "\n\n==== Testowanie listy dwukierunkowej dla rozmiaru: " 
             << size << " elementów ====" << endl;
        
        double total_dll_addBegin    = 0.0;
        double total_dll_addEnd      = 0.0;
        double total_dll_addIndex    = 0.0;
        double total_dll_removeBegin = 0.0;
        double total_dll_removeEnd   = 0.0;
        double total_dll_removeIndex = 0.0;
        double total_dll_find        = 0.0;
        int seedCount = 0;
        
        for (int seed : SEEDS) {
            srand(seed);
            
            double dll_addBegin_sum    = 0.0;
            double dll_addEnd_sum      = 0.0;
            double dll_addIndex_sum    = 0.0;
            double dll_removeBegin_sum = 0.0;
            double dll_removeEnd_sum   = 0.0;
            double dll_removeIndex_sum = 0.0;
            double dll_find_sum        = 0.0;
            
            DoublyLinkedList dllist;
            
            for (int t = 0; t < TESTS; t++) {
                dllist.fillRandom(size, seed);
                int value = rand() % 10000;
                dll_addBegin_sum += measure_time([&]() {
                    dllist.addBegin(value);
                });
                value = rand() % 10000;
                dll_addEnd_sum += measure_time([&]() {
                    dllist.addEnd(value);
                });
                value = rand() % 10000;
                // Jeśli struktura nie jest pusta, wykonujemy operację addIndex
                dll_addIndex_sum += measure_time([&]() {
                    dllist.addIndex(value, rand() % dllist.getSize());
                });
                
                dllist.clear();
                dllist.fillRandom(size, seed);
                dll_removeIndex_sum += measure_time([&]() {
                    dllist.removeIndex(rand() % dllist.getSize());
                });
                
                dllist.clear();
                dllist.fillRandom(size, seed);
                dll_removeBegin_sum += measure_time([&]() {
                    dllist.removeBegin();
                });
                
                dllist.clear();
                dllist.fillRandom(size, seed);
                if (dllist.getSize() > 0) {
                    dll_removeEnd_sum += measure_time([&]() {
                        dllist.removeEnd();
                    });
                }
                
                int search_value = rand() % 10000;
                dll_find_sum += measure_time([&]() {
                    dllist.find(search_value);
                });
            }
            
            total_dll_addBegin    += dll_addBegin_sum    / TESTS;
            total_dll_addEnd      += dll_addEnd_sum      / TESTS;
            total_dll_addIndex    += dll_addIndex_sum    / TESTS;
            total_dll_removeIndex += dll_removeIndex_sum / TESTS;
            total_dll_removeBegin += dll_removeBegin_sum / TESTS;
            total_dll_removeEnd   += dll_removeEnd_sum   / TESTS;
            total_dll_find        += dll_find_sum        / TESTS;
            seedCount++;
        }
        
        cout << "\n*** Średnie wyniki dla listy dwukierunkowej dla rozmiaru " 
             << size << " (średnia z " << seedCount << " seedów):\n";
        dllFile << "\n*** Średnie wyniki dla listy dwukierunkowej dla rozmiaru " 
             << size << " (średnia z " << seedCount << " seedów):\n";
        cout << "  Dodanie na początek:         " << (total_dll_addBegin    / seedCount) << " s\n";
        cout << "  Dodanie na koniec:           " << (total_dll_addEnd      / seedCount) << " s\n";
        cout << "  Dodanie do losowego miejsca: " << (total_dll_addIndex    / seedCount) << " s\n";
        cout << "  Usunięcie z losowego miejsca: " << (total_dll_removeIndex / seedCount) << " s\n";
        cout << "  Usunięcie z początku:         " << (total_dll_removeBegin / seedCount) << " s\n";
        cout << "  Usunięcie z końca:           " << (total_dll_removeEnd   / seedCount) << " s\n";
        cout << "  Wyszukiwanie:                " << (total_dll_find        / seedCount) << " s\n";
        
        dllFile << "  Dodanie na początek:         " << (total_dll_addBegin    / seedCount) << " s\n";
        dllFile << "  Dodanie na koniec:           " << (total_dll_addEnd      / seedCount) << " s\n";
        dllFile << "  Dodanie do losowego miejsca: " << (total_dll_addIndex    / seedCount) << " s\n";
        dllFile << "  Usunięcie z losowego miejsca: " << (total_dll_removeIndex / seedCount) << " s\n";
        dllFile << "  Usunięcie z początku:         " << (total_dll_removeBegin / seedCount) << " s\n";
        dllFile << "  Usunięcie z końca:           " << (total_dll_removeEnd   / seedCount) << " s\n";
        dllFile << "  Wyszukiwanie:                " << (total_dll_find        / seedCount) << " s\n";
    }
    
    // =======================
    // Testy dla listy jednokierunkowej (SinglyLinkedList)
    // =======================
    for (int size : SIZES1) {
        cout << "\n\n==== Testowanie listy jednokierunkowej dla rozmiaru: " 
             << size << " elementów ====" << endl;
        sllFile << "\n\n==== Testowanie listy jednokierunkowej dla rozmiaru: " 
             << size << " elementów ====" << endl;
        
        double total_sll_addBegin    = 0.0;
        double total_sll_addEnd      = 0.0;
        double total_sll_addIndex    = 0.0;
        double total_sll_removeBegin = 0.0;
        double total_sll_removeEnd   = 0.0;
        double total_sll_removeIndex = 0.0;
        double total_sll_find        = 0.0;
        int seedCount = 0;
        
        for (int seed : SEEDS) {
            srand(seed);
            
            double sll_addBegin_sum    = 0.0;
            double sll_addEnd_sum      = 0.0;
            double sll_addIndex_sum    = 0.0;
            double sll_removeBegin_sum = 0.0;
            double sll_removeEnd_sum   = 0.0;
            double sll_removeIndex_sum = 0.0;
            double sll_find_sum        = 0.0;
            
            SinglyLinkedList sllist;
            for (int t = 0; t < TESTS; t++) {
                sllist.fillRandom(size, seed);
                int value = rand() % 10000;
                sll_addBegin_sum += measure_time([&]() {
                    sllist.addBegin(value);
                });
                value = rand() % 10000;
                sll_addEnd_sum += measure_time([&]() {
                    sllist.addEnd(value);
                });
                value = rand() % 10000;
                sll_addIndex_sum += measure_time([&]() {
                    sllist.addIndex(value, rand() % sllist.getSize());
                });
                
                sllist.fillRandom(size, seed);
                sll_removeIndex_sum += measure_time([&]() {
                    sllist.removeIndex(rand() % sllist.getSize());
                });
                
                sllist.fillRandom(size, seed);
                sll_removeBegin_sum += measure_time([&]() {
                    sllist.removeBegin();
                });
                
                sllist.fillRandom(size, seed);
                sll_removeEnd_sum += measure_time([&]() {
                    sllist.removeEnd();
                });
                
                sll_find_sum += measure_time([&]() {
                    sllist.find(rand() % 10000);
                });
            }
            total_sll_addBegin    += sll_addBegin_sum    / TESTS;
            total_sll_addEnd      += sll_addEnd_sum      / TESTS;
            total_sll_addIndex    += sll_addIndex_sum    / TESTS;
            total_sll_removeIndex += sll_removeIndex_sum / TESTS;
            total_sll_removeBegin += sll_removeBegin_sum / TESTS;
            total_sll_removeEnd   += sll_removeEnd_sum   / TESTS;
            total_sll_find        += sll_find_sum        / TESTS;
            seedCount++;
        }
        
        cout << "\n*** Średnie wyniki dla listy jednokierunkowej dla rozmiaru " 
             << size << " (średnia z " << seedCount << " seedów):\n";
        sllFile << "\n*** Średnie wyniki dla listy jednokierunkowej dla rozmiaru " 
             << size << " (średnia z " << seedCount << " seedów):\n";
        cout << "  Dodanie na początek:         " << (total_sll_addBegin    / seedCount) << " s\n";
        cout << "  Dodanie na koniec:           " << (total_sll_addEnd      / seedCount) << " s\n";
        cout << "  Dodanie do losowego miejsca: " << (total_sll_addIndex    / seedCount) << " s\n";
        cout << "  Usunięcie z losowego miejsca: " << (total_sll_removeIndex / seedCount) << " s\n";
        cout << "  Usunięcie z początku:         " << (total_sll_removeBegin / seedCount) << " s\n";
        cout << "  Usunięcie z końca:           " << (total_sll_removeEnd   / seedCount) << " s\n";
        cout << "  Wyszukiwanie:                " << (total_sll_find        / seedCount) << " s\n";
        
        sllFile << "  Dodanie na początek:         " << (total_sll_addBegin    / seedCount) << " s\n";
        sllFile << "  Dodanie na koniec:           " << (total_sll_addEnd      / seedCount) << " s\n";
        sllFile << "  Dodanie do losowego miejsca: " << (total_sll_addIndex    / seedCount) << " s\n";
        sllFile << "  Usunięcie z losowego miejsca: " << (total_sll_removeIndex / seedCount) << " s\n";
        sllFile << "  Usunięcie z początku:         " << (total_sll_removeBegin / seedCount) << " s\n";
        sllFile << "  Usunięcie z końca:           " << (total_sll_removeEnd   / seedCount) << " s\n";
        sllFile << "  Wyszukiwanie:                " << (total_sll_find        / seedCount) << " s\n";
    }
    
    // Zamknięcie plików
    daFile.close();
    dllFile.close();
    sllFile.close();

    return 0;
}