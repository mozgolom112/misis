#pragma once
#ifndef Stack_on_list13122018
#define Stack_on_list13122018

#include <iostream>

template<class T>
class Stack {
public:
    Stack() = default;

    Stack(const Stack &stack);

    ~Stack();

    Stack &operator=(const Stack<T> &rhs);

    T &pop();

    void push(const T &data);

    const T &top() const;

    bool isEmpty() const;

    std::ostream &writeTo(std::ostream &ostrm) const {
        Node <T> *temp = head_;
        while (temp != nullptr) {
            ostrm << temp->data_ << " ";
            temp = temp->next_;
        }
        return ostrm;
    }

private:
    template<typename T>
    struct Node {
        Node() = default;

        Node(const T data, Node<T> *next)
                : data_(data), next_(next) {
        }

        T data_;
        Node<T> *next_;
    };

    Node<T> *head_{nullptr};
};

template<class T>
inline std::ostream &operator<<(std::ostream &ostrm, const Stack<T> &a) {
    return a.writeTo(ostrm);
}

template<class T>
Stack<T>::Stack(const Stack &stack) {
    Stack<T> newStack;
    Node<T> *temp = stack.head_;

    while (temp != nullptr) {
        newStack.push(temp->data_);
        temp = temp->next_;
    }

    temp = newStack.head_;

    while (temp != nullptr) {
        push(temp->data_);
        temp = temp->next_;
    }
}

template<class T>
Stack<T>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

template<class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &rhs) {
    Stack<T> newStack;
    Node<T> *temp = rhs.head_;

    while (temp != nullptr) {
        newStack.push(temp->data_);
        temp = temp->next_;
    }

    temp = newStack.head_;

    while (temp != nullptr) {
        push(temp->data_);
        temp = temp->next_;
    }

    return *this;
}

template<class T>
T &Stack<T>::pop() {
    if (!isEmpty()) {
        Node<T> *oldNode(head_);
        head_ = oldNode->next_;
        delete oldNode;
        return oldNode->data_;
    } else {
        throw std::exception("Stack is empty");
    }
}

template<class T>
void Stack<T>::push(const T &data) {
    head_ = new Node<T>(data, head_);
}

template<class T>
const T &Stack<T>::top() const {
    if (!isEmpty()) {
        return head_->data_;
    } else {
        throw std::exception("Stack is empty");
    }
}

template<class T>
bool Stack<T>::isEmpty() const {
    return (head_ == nullptr);
}


#endif Stack_on_list13122018