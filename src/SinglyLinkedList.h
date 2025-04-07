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
    void removeBegin();
    void removeEnd();
    void print() const;
    void clear();
    int getSize() const;
};

#endif // SINGLYLINKEDLIST_H
