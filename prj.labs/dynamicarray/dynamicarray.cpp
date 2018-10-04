#include "dynamicarray.h"
#include <iostream>


DynamicArray::DynamicArray() {
	size_ = 0;
	data_ = new double[size_];
}

DynamicArray::DynamicArray(const int size) {
	if (size >= 0) {
		data_ = new double[size];
		size_ = size;
	}
	else {
		std::cout << "Error" << std::endl;
	} //экземпляр создается в любом случае. Что тут можно придумать?
}

DynamicArray::DynamicArray(const DynamicArray& copy) {
	size_ = copy.size(); // или можем использовать = copy.size_; как лучше?
	data_ = new double[size_];
	// так вообще не надо ибо ты копируешь тупо ссылку. data_ = copy.data_; //так можно копировать? Ты отправляешь ссылку на адрес! При вызове деструктора b3 уже b2 разрушен и выдает ошибку

	for (int i(0); i < size_; i++) {
		data_[i] = copy.data_[i]; //copy[i] почему не работает?  !!!!!!!!!!!!!!
	}
}

int DynamicArray::size() const { //
	return size_;
}

DynamicArray::~DynamicArray() {
	delete[] data_;
}


DynamicArray& DynamicArray::operator=(const DynamicArray& obj) {
	if (obj.size() > size_) {
		delete[] data_;

		data_ = new double[obj.size_];
	}
	size_ = obj.size_;
	for (int i(0); i < obj.size_; i++) {

		data_[i] = obj.data_[i];
	}

	return *this;
}

double& DynamicArray::operator[](const int i) {

	if ((i >= 0) && (i < size_))
		return data_[i];
	else {
		std::cout << "Error" << std::endl;
		double a = 0.0; //костыль. Исправь
		return a;
	}
}
