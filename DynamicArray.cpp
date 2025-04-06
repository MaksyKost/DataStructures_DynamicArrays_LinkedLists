#include <iostream>
using namespace std;

// klasa bazowa
class Structure {
public:
    virtual void addAtBeginning(int val) = 0;
    virtual void addAtEnd(int val) = 0;
    virtual void addAtIndex(int val, int index) = 0;
    virtual void removeAtIndex(int index) = 0;
    virtual int find(int val) = 0;
    virtual void print() = 0;
    virtual ~Structure() {}
};