#include <iostream>   
#include <chrono>
#include <algorithm>
#include <fstream>
#include <string>

#include "src/DynamicArray.h"
#include "src/DoublyLinkedList.h"
#include "src/SinglyLinkedList.h"

using namespace std;


// Funkcja mierząca czas operacji
template<typename Function>
double measure_time(Function func) {
    auto start = chrono::high_resolution_clock::now();
    func();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
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
    const int SEED[] = {250, 300, 350, 400, 450, 500, 550, 600, 650, 700}; 
    
    double q_Test_1{}, h_Test_1{}, t_Test_1{}, q_Test_2{}, h_Test_2{}, t_Test_2{}, q_Test_3{}, h_Test_3{}, t_Test_3{};
    double da_addBegin, da_addEnd, da_addIndex, da_removeBegin, da_removeEnd, da_removeIndex, da_find;
    double sll_addBegin, sll_addEnd, sll_addIndex, sll_removeBegin, sll_removeEnd, dsll_removeIndex, sll_find;
    double dll_addBegin, dll_addEnd, dll_addIndex, dll_removeBegin, dll_removeEnd, dll_removeIndex, dll_find;


    for (int size : SIZES) {
        ArrayList daList;
        SinglyLinkedList slList;
        DoublyLinkedList dlList;

        for (int seed : SEED) {

            cout << "Testing size: " << "\t" <<  size << " elements" << endl;
            
    
            for (int t = 0; t < TESTS; t++) {
                

                fillArrayRandom(arr, size, SEED);
                clock_t start = clock();
                dualPivotQuickSort(arr, 0, size - 1);
                clock_t end = clock();
                q_Test_1 += double(end - start) / CLOCKS_PER_SEC;
                
                
                fillArrayRandom(arr, size, SEED);
                start = clock();
                heapSort(arr, size);
                end = clock();
                h_Test_1 += double(end - start) / CLOCKS_PER_SEC;

                fillArrayRandom(arr, size, SEED);
                start = clock();
                timSort(arr, size);
                end = clock();
                t_Test_1 += double(end - start) / CLOCKS_PER_SEC;

                
                    
                std::sort(arr, arr + size, [](int a, int b){return a > b; 
                });
                clock_t start_1 = clock();
                dualPivotQuickSort(arr, 0, size - 1);
                clock_t end_1 = clock();
                q_Test_3 += double(end_1 - start_1) / CLOCKS_PER_SEC;

                std::sort(arr, arr + size, [](int a, int b){return a > b;  
                });
                clock_t start_1 = clock();
                heapSort(arr, size);
                clock_t end_1 = clock();
                h_Test_3 += double(end_1 - start_1) / CLOCKS_PER_SEC;

                std::sort(arr, arr + size, [](int a, int b){return a > b; 
                });
                start_1 = clock();
                timSort(arr, size);
                end_1 = clock();
                t_Test_3 += double(end_1 - start_1) / CLOCKS_PER_SEC;
            }
            


            results(q_Test_1, h_Test_1, t_Test_1, TESTS);

            ofstream file("Wyniki/q_Test_1.txt", ios::app); 
            file << size << " " << q_Test_1 / TESTS << std::endl;
            file.close(); 

            ofstream file1("Wyniki/h_Test_1.txt", ios::app); 
            file1 << size << " " <<h_Test_1 / TESTS << std::endl;
            file1.close(); 

            ofstream file2("Wyniki/t_Test_1.txt", ios::app); 
            file2 << size << " " << t_Test_1 / TESTS << std::endl;
            file2.close(); 
            



            cout << "Reversed sorted: \n";

            results(q_Test_3, h_Test_3, t_Test_3, TESTS);

            ofstream file("Wyniki/q_Test_3.txt", ios::app); 
            file << size << " " << q_Test_3 / TESTS << std::endl;
            file.close(); 

            ofstream file1("Wyniki/h_Test_3.txt", ios::app); 
            file1 << size << " " <<h_Test_3 / TESTS << std::endl;
            file1.close(); 

            ofstream file2("Wyniki/t_Test_3.txt", ios::app); 
            file2 << size << " " << t_Test_3 / TESTS << std::endl;
            file2.close(); 
            
            


            for (double percentage : SORTED_PERCENTAGES) 
            {
                cout << "Sorted: " << "\t" << percentage * 100 << "% " << endl;
                for(int t = 0; t < TESTS; t++)
                {    
                    fillArrayRandom(arr, size, SEED);
                    int sorted_size = size * percentage;
                    sort(arr, arr + sorted_size);
                    clock_t start = clock();
                    dualPivotQuickSort(arr, 0, size - 1);
                    clock_t end = clock();
                    q_Test_2 += double(end - start) / CLOCKS_PER_SEC;
                    
                    fillArrayRandom(arr, size, SEED);
                    sort(arr, arr + sorted_size);
                    start = clock();
                    heapSort(arr, size);
                    end = clock();
                    h_Test_2 += double(end - start) / CLOCKS_PER_SEC;

                    fillArrayRandom(arr, size, SEED);
                    sort(arr, arr + sorted_size);
                    start = clock();
                    timSort(arr, size);
                    end = clock();
                    t_Test_2 += double(end - start) / CLOCKS_PER_SEC;
                }
                string filePath_q = "Wyniki/" + to_string(int(percentage*1000)) + "/q_Test_2.txt";
                string filePath_h = "Wyniki/" + to_string(int(percentage*1000)) + "/h_Test_2.txt";
                string filePath_t = "Wyniki/" + to_string(int(percentage*1000)) + "/t_Test_2.txt";

                ofstream file_q(filePath_q, ios::app); 
                file_q << size << " " << q_Test_2 << std::endl;
                file_q.close();

                ofstream file_h(filePath_h, ios::app); 
                file_h << size << " " << h_Test_2 << std::endl;
                file_h.close();

                ofstream file_t(filePath_t, ios::app); 
                file_t << size << " " << t_Test_2 << std::endl;
                file_t.close();

                results(q_Test_2, h_Test_2, t_Test_2, TESTS);
            }
        }
    }





    return 0;
}