#pragma once
#include <iostream>

template<typename T>
class Node {
public:
    T value;
    Node<T>* next;

    Node(const T& value, Node<T>* pNext = nullptr) : value(value), next(pNext) {}
};

template<typename T>
class Set {
private:
    Node<T>* head;
public:
    Set() : head(nullptr) {}
    ~Set() { clear(); }
    bool find(const T& element) const {
        Node<T>* curr = head;
        while (curr != nullptr) {
            if (curr->value == element) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
    void add(const T& element) {
        if (find(element)) {
            return;
        }
        head = new Node<T>(element, head);
    }
    void remove(const T& element) {
        if (head == nullptr) {
            return;
        }
        if (head->value == element) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* curr = head;
        while (curr->next != nullptr) {
            if (curr->next->value == element) {
                Node<T>* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }
    
    Node<T>* getHead() { return head; }

    void association(Set<T>& a, Set<T>& b) {
        Node<T>* curr = a.getHead();
        while (curr != nullptr) {
            add(curr->value);
            curr = curr->next;
        }
        curr = b.getHead();
        while (curr != nullptr) {
            add(curr->value);
            curr = curr->next;
        }
    }
    void intersection(Set<T>& a, Set<T>& b) {
        Node<T>* curr = a.getHead();
        while (curr != nullptr) {
            if (b.find(curr->value))
                add(curr->value);
            curr = curr->next;
        }
    }
    bool is_subset(Set<T> const& other) {
        bool result = true;
        Node<T> * curr = this->head;
        while (curr != nullptr) {
            if (!(other.find(curr->value))) {
                result = false;
                break;
            }
            curr = curr->next;
        }
        return result;
    }

    void clear() {
        while (head != nullptr) {
            remove(head->value);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Set<T>& set) {
        Node<T>* curr = set.head;
        while (curr != nullptr) {
            os << curr->value << " ";
            curr = curr->next;
        }
        os << std::endl;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Set<T>& set) {
        int n = 0;
        is >> n;
        T element;
        for (int i = 0; i < n; ++i) {
            is >> element;
            set.add(element);
        }
        return is;
    }
};

