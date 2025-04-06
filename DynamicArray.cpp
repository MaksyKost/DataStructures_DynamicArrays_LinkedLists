#include <iostream>
using namespace std;

// klasa bazowa
class Structure {
public:
    virtual void addBegin(int val) = 0;
    virtual void addEnd(int val) = 0;
    virtual void addIndex(int val, int index) = 0;
    virtual void removeIndex(int index) = 0;
    virtual int find(int val) = 0;
    virtual void print() = 0;
    virtual ~Structure() {}
};

class ArrayList : public Structure {
private:
    int* arr;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }

public:
    ArrayList(int initialCapacity = 10) {
        capacity = initialCapacity;
        size = 0;
        arr = new int[capacity];
    }

    ~ArrayList() {
        delete[] arr;
    }

    void addBegin(int val) override {
        if (size == capacity) resize();
        for (int i = size; i > 0; i--) arr[i] = arr[i - 1];
        arr[0] = val;
        size++;
    }

    void addEnd(int val) override {
        if (size == capacity) resize();
        arr[size++] = val;
    }
};