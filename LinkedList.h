#include "Node.h"
template<typename T> class LinkedList {
private:
    Node<T> *head;
    Node<T> *tail;
    int size;
public:
    // Constructor
    LinkedList() {
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    Node<T>* getTail() {
        return this->tail;
    }

    Node<T>* getHead() {
        return this->head;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return this->size;
    }

    void display() {
        Node<T>* current = this->head;
        if (!isEmpty()) {
            while (current != nullptr) {
                std::cout << current->data << " -> ";
                current = current->next;
            }
            std::cout << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }

    void insertRight(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (isEmpty()) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            newNode->prev = this->tail;
            this->tail->next = newNode;
            this->tail = newNode;
        }
        size++;
    }

    void insertLeft(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (isEmpty()) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            newNode->next = this->head;
            this->head = newNode;
            this->head->prev = nullptr;
            this->head->next->prev = newNode;
        }
        size++;
    }

    void eraseRight() {
        if (isEmpty()) {
            std::cout << "Nothing to erase...";
        } else if (size == 1) {
            this->tail = nullptr;
            this->head = nullptr;
            size--;
        } else {
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
            size--;
        }
        
    }
    
    void eraseLeft() {
        if (isEmpty()) {
            std::cout << "Nothing to erase...";
        } else if (size == 1) {
            this->tail = nullptr;
            this->head = nullptr;
            size--;
        } else {
            this->head = this->head->next;
            this->head->prev = nullptr;
            size--;
        }
    }
};
  