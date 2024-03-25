#include "Queue.h"

Queue::Queue() : _front(nullptr), _back(nullptr), n(0) {}

Queue::~Queue()
{
    clear();
}

void Queue::push(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (_back == nullptr) {
        _front = _back = newNode;
    }
    else {
        _back->next = newNode;
        _back = newNode;
    }
    ++n;
}

void Queue::pop() {
    if (_front == nullptr) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    std::cout << _front->value << " ";
    Node* temp = _front;
    _front = _front->next;
    
    if (_front == nullptr) {
        _back = nullptr;
    }
    delete temp;
    --n;
}

int Queue::front() {
    if (_front == nullptr) {
        std::cout << "Queue is empty." << std::endl;
        return -1;
    }

    return _front->value;
}

int Queue::back()
{
    if (_back == nullptr) {
        std::cout << "Queue is empty." << std::endl;
        return -1;
    }

    return _back->value;
}

int Queue::size()
{
    return n;
}

void Queue::print()
{
    Node* cur = _front;
    while (cur != nullptr) {
        std::cout << cur->value << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
    delete cur;
}

bool Queue::isEmpty() {
    return _front == nullptr;
}

void Queue::clear()
{
    while (_front != nullptr) {
        pop();
    }
}

int Queue::max()
{
    if (isEmpty()) {
        std::cout << "Queue is empty";
        return INT_MIN;
    }

    Node* cur = _front->next;
    int max = _front->value;
    while (cur != nullptr) {
        if (max < cur->value)
            max = cur->value;
        cur = cur->next;
    }
    delete cur;
    return max;
}

int Queue::min()
{
    if (isEmpty()) {
        std::cout << "Queue is empty";
        return INT_MAX;
    }

    Node* cur = _front->next;
    int min = _front->value;
    while (cur != nullptr) {
        if (min > cur->value)
            min = cur->value;
        cur = cur->next;
    }
    delete cur;
    return min;
}
