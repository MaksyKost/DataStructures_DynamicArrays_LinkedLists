#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;
    int size;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void addBegin(int val);
    void addEnd(int val);
    void addIndex(int index, int val);
    void removeBegin();
    void removeEnd();
    void removeIndex(int index);
    void print() const;
    int  find(int val) const;
    void clear();
    int getSize() const;
    void fillRandom(int count, int seed);
    double timeAddBegin();
    double timeAddEnd();
};

#endif // SINGLYLINKEDLIST_H
