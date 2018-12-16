#include "dynamicarray.h"
#include <iostream>
#include <exception>


DynamicArray::DynamicArray() {
    size_ = 0;
    data_ = new double[size_]; //
}

DynamicArray::DynamicArray(const int size) {
    if (size >= 0) {
        data_ = new double[size]{0.0};
        size_ = size;
    } else {
        throw std::out_of_range("Size can't be nagative");
    }
}

DynamicArray::DynamicArray(const DynamicArray &copy) {
    size_ = copy.size(); // или можем использовать = copy.size_; как лучше?
    data_ = new double[size_]{0.0};
    // так вообще не надо ибо ты копируешь тупо ссылку. data_ = copy.data_; //так можно копировать? “ы отправл€ешь ссылку на адрес! ѕри вызове деструктора b3 уже b2 разрушен и выдает ошибку

    for (int i(0); i < size_; i++) {
        data_[i] = copy.data_[i]; //copy[i] почему не работает?  !!!!!!!!!!!!!! ѕотому что нет оператора [] дл€ константы
    }
}

int DynamicArray::size() const { //
    return size_;
}

DynamicArray::~DynamicArray() {
    delete[] data_;
    data_ = nullptr;
}


DynamicArray &DynamicArray::operator=(const DynamicArray &rhs) {


    if (this != &(rhs)) {

        if (rhs.size_ > size_) {
            delete[] data_; //как сделать это грамотно? сначало очищаем, а потом создаем новый
            data_ = new double[rhs.size_];

        }
        size_ = rhs.size_;
        for (int i(0); i < rhs.size_; i++) {

            data_[i] = rhs.data_[i];
        }
    }
    return *this;
}

double &DynamicArray::operator[](const int index) {


    if (index < 0) {
        throw std::out_of_range("Index can't be negative");
    }
    if (index >= size_) {
        throw std::out_of_range("Index can't be more than size of array");
    }

    return data_[index];
}


void DynamicArray::resize(const int new_size) {
    if (size_ < new_size) {
        double *newdata = new double[new_size]{0.0};
        for (int i(0); i < size_; i++) {
            newdata[i] = data_[i];
        }

        data_ = newdata;


    }

    this->size_ = new_size;
}