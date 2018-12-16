#pragma once

#ifndef STACKONARRAY 25112018
#define STACKONARRAY 25112018

#include <exception>;
#include <iostream>;


template<typename T>

class Stack {
public:
    Stack();

    Stack(const int &maxsize);

    Stack(const Stack<T> &copy);

    Stack &operator=(const Stack &rhs);

    ~Stack();

    void push(T &new_element);// добавление нового элемента на вершину
    void pop(); //удаление верхнего элемента стека и возвращает 3) нужен ли возврат
    int getSizeofStack() const; //возвращает физический размер
    T &getTop() const; //return top_

    bool isEmpty() const;


    void printStack();

private:
    T *stackPtr_{nullptr}; //укзатель на стек
    int size_; //физический размер стека
    int top_; //номер текущего(верхнего) элемента стека


};


//constructor with destroctor
template<typename T>
Stack<T>::Stack() {
    size_ = 0;
    stackPtr_ = new T[size_];
    top_ = 0;
}


template<typename T>
Stack<T>::Stack(const int &maxsize) : size_(maxsize) {


    if (size_ < 0) {
        throw std::exception("Invalid argument for stack's size");
    }

    stackPtr_ = new T[size_];
    top_ = 0;
}


template<typename T>
//1) как сделать так,чтобы автоматически ставился тот тип, который в copy уже стоит?
Stack<T>::Stack(const Stack<T> &copy) {
    size_ = copy.getSizeofStack();
    stackPtr_ = new T[size_];
    top_ = copy.getTop();

    for (int i(0); i < top_; i++) {
        stackPtr_[i] = copy.getPtr()[i];
    }

}


template<typename T>
Stack<T>::~Stack() {
    delete[] stackPtr_;
    stackPtr_ = nullptr;
}


template<typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &rhs) {
    if (this != &rhs) {
        if (size_ < rhs.size_) {
            delete[] stackPtr_;
            stackPtr_ = new T[rhs.size_];
        }
        size_ = rhs.size_;
        top_ = rhs.top_;
        for (int i(0); i < top_; i++) {
            stackPtr_[i] = rhs.stackPtr_[i];
        }
    }
    return *this;
}


template<typename T>
void Stack<T>::printStack() {
    if (isEmpty()) {
        std::cout << "Стек пуст" << std::endl;
    } else {
        for (int i(top_ - 1); i >= 0; i--) //начинаем печатать сверху стека!
        {
            std::cout << "|     " << stackPtr_[i] << std::endl;
        }
    }
}


template<typename T>
T &Stack<T>::getTop() const {
    if (isEmpty()) {
        throw ::exception("Массив пустой");
    } else {
        return stackPtr_[top_ - 1];
    }
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return (top_ == 0);
}

template<typename T>
void Stack<T>::push(T &newelement) {

    if (top_ >= size_) {
        throw std::exception("Stack is over. You can't add another element");
    } else {
        stackPtr_[top_] = newelement;
    }
    top_++;
}

template<typename T>
void Stack<T>::pop() {

    if (top_ == 0) {
        throw std::exception("Stack has already been empty");
    } else {
        --top_;
    }


}


template<typename T>
int Stack<T>::getSizeofStack() const {
    return size_;
}

#endif //!STACKONARRAY 25112018