#include <iostream>
using namespace std;

class Structure {
    public:
        virtual void addBegin(int a) = 0;
        virtual void addEnd(int a) = 0;
        virtual void addIndex(int a, int index) = 0;
        virtual void deleteBegin(int a) = 0;
        virtual void deleteEnd(int a) = 0;
        virtual void deleteIndex(int index) = 0;
        virtual void print() = 0;
        virtual ~Structure() {};
};

class Array : public Structure {
    private: 
    
};