#include "LinkedList.h"

template<typename T> class Stack {
public:
    LinkedList<T> stack;
    
    void push(T data) {
        stack.insertRight(data);
    }

    T pop() {
        if (!stack.isEmpty()) {
            T value = stack.getTail()->data;
            stack.eraseRight();
            return value;
        } else {
            throw std::runtime_error("Stack underflow");
        }
    }

    T top() {
        if (stack.isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        return stack.getTail()->data;
    }


    bool isEmpty() {
        if (stack.getSize() == 0) return true;
        else return false;
    }

    void display() {
        Node<T>* current = stack.getHead();
        if (!stack.isEmpty()) {
            while (current != nullptr) {
                std::cout << current->data << " -> ";
                current = current->next;
            }
            std::cout << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }
};