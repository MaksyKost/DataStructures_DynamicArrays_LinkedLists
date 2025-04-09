#include <iostream>
#include <cstdlib>
#include "DynamicArray.h"
using namespace std;

ArrayList::ArrayList(int initialCapacity){ // konstruktor
    capacity = initialCapacity;
    size = 0;
    arr = new int[capacity];
}

ArrayList::~ArrayList(){ // destruktor
    delete[] arr;
}

void ArrayList::resize() { // relokacja pamięci
    capacity *= 2;
    int* newArr = new int[capacity];
    for (int i = 0; i < size; i++) newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
}

void ArrayList::addBegin(int val) { // dodaje na początku
    size++;
    if (size == capacity) resize();
    for (int i = size; i > 0; i--) arr[i] = arr[i - 1];
    arr[0] = val;
   
}

void ArrayList::addEnd(int val) { // dodaje na końcu
    if (size == capacity) resize();
    arr[size++] = val;
}

void ArrayList::addIndex(int val, int index) { // dodaje na pozycji
    if (index < 0 || index > size) return;
    if (size == capacity) resize();
        for (int i = size; i > index; i--) arr[i] = arr[i - 1];
        arr[index] = val;
        size++;
}

void ArrayList::removeBegin() { // usuwa na początku 
    for (int i = 0; i < size; i++) arr[i] = arr[i + 1];
    size--;
}

void ArrayList::removeEnd() { // usuwa na końcu
    size--;
}

void ArrayList::removeIndex(int index)  { //usuwa na pozycji
    if (index < 0 || index > size) return;
    for (int i = index; i < size; i++) arr[i] = arr[i + 1];
    size--;
}

int ArrayList::find(int val)  { // wyszukuje
    for (int i = 0; i < size; i++){
        if (arr[i] == val) return i;
    }
    return -1;
}

void ArrayList::print()  { //wyświetla
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " " ;
    }
    cout << endl;
}

void ArrayList::fillRandom(int count, int seed)  { //wypełnia pseudolosowymi liczbami
    srand(seed);
    for (int i = size; i < count; i++) {
        int val = rand() % 10000;
        addEnd(val);
    }
}

int ArrayList::getSize() const { // zwraca rozmiar
    return size;
}

void ArrayList::clear() { // czyśczy listę
    delete[] arr;
    arr = new int[capacity];
    size = 0;
}
