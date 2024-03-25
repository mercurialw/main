#pragma once
#include <iostream>

class Queue {
private:
    struct Node {
        int value;
        Node* next;
    };

    Node* _front;
    Node* _back;
    int n;

public:
    Queue();
    ~Queue();

    void push(int);
    void pop();
    int front();
    int back();
    int size();
    void print();
    bool isEmpty();
    void clear();


    int max();
    int min();
};
