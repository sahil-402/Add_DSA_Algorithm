#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() : head(nullptr) {}

    void insertEnd(int val);
    void insertBegin(int val);
    void deleteValue(int val);
    bool search(int val);
    void reverse();
    void display();
};

// Implementations...
