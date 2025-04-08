#include <iostream>
#include <cstdlib>
#include "DynamicArray.h"
using namespace std;

ArrayList::ArrayList(int initialCapacity){
    capacity = initialCapacity;
    size = 0;
    arr = new int[capacity];
}

ArrayList::~ArrayList(){
    delete[] arr;
}

void ArrayList::resize() {
    capacity *= 2;
    int* newArr = new int[capacity];
    for (int i = 0; i < size; i++) newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
}

void ArrayList::addBegin(int val) {
    size++;
    if (size == capacity) resize();
    for (int i = size; i > 0; i--) arr[i] = arr[i - 1];
    arr[0] = val;
   
}

void ArrayList::addEnd(int val) {
    if (size == capacity) resize();
    arr[size++] = val;
}

void ArrayList::addIndex(int val, int index) {
    if (index < 0 || index > size) return;
    if (size == capacity) resize();
        for (int i = size; i > index; i--) arr[i] = arr[i - 1];
        arr[index] = val;
        size++;
}

void ArrayList::removeBegin() {
    for (int i = 0; i < size; i++) arr[i] = arr[i + 1];
    size--;
}

void ArrayList::removeEnd() {
    size--;
}

void ArrayList::removeIndex(int index)  {
    if (index < 0 || index > size) return;
    for (int i = index; i < size; i++) arr[i] = arr[i + 1];
    size--;
}

int ArrayList::find(int val)  {
    for (int i = 0; i < size; i++){
        if (arr[i] == val) return i;
    }
    return -1;
}

void ArrayList::print()  {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " " ;
    }
    cout << endl;
}

void ArrayList::fillRandom(int count, int seed)  {
    srand(seed);
    for (int i = size; i < count; i++) {
        int val = rand() % 10000;
        addEnd(val);
    }
}

int ArrayList::getSize() const {
    return size;
}

void ArrayList::clear() {
    delete[] arr;
    arr = new int[capacity];
    size = 0;
}
