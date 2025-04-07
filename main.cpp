#include <iostream>   
#include "DynamicArray.h"
using namespace std;

int main() {
    ArrayList arr;
    arr.fillRandom(10, 5, 12);
    arr.print();
    return 0;
}