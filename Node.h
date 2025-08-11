#include <iostream>

template <typename T> class Node {
public: 
    T data;
    Node<T> *next;
    Node<T> *prev;
    Node(T data, Node* next=nullptr, Node* prev=nullptr) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    T getData() {
        return this->data;
    }

    Node<T> *getNext () {
        return this->next;
    }

    Node<T> *getPrev() {
        return this->prev;
    }
};