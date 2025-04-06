#include <iostream>
#include "DynamicArray.h"
using namespace std;

int main() {
    ArrayList arr;
    arr.addBegin(10);
    arr.addBegin(67);
    arr.addBegin(14);
    arr.print();
    return 0;
}