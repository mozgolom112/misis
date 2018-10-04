#include "matrix.h"


Matrix::Matrix()
{
	size_ = 0;
	arrays_ = nullptr;
}
Matrix::Matrix(const int size) {
	size_ = size;
	arrays_ = new DynamicArray[size_];
}

Matrix::Matrix(const DynamicArray& obj) {
	size_ = 1;
	arrays_ = new DynamicArray[size_];
	arrays_[1] = obj;
}

DynamicArray& Matrix::operator[](const int i) {
	return arrays_[i];
}

Matrix::Matrix(const Matrix& copy) {
	size_ = copy.size_; 
	arrays_ = new DynamicArray[size_];
	

	for (int i(0); i < size_; i++) {
		arrays_[i] = copy.arrays_[i]; 
	}

}

Matrix::~Matrix() {
	delete[] arrays_;
}