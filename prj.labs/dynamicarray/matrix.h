#ifndef MATRIX 05102018
#define MATRIX 05102018
#include "dynamicarray.h"

class Matrix {
public:
	Matrix();
	Matrix(const int size);
	Matrix(const DynamicArray& obj);
	Matrix(const Matrix& copy);

	DynamicArray& operator[](const int i);

	~Matrix();
	
private:
	DynamicArray* arrays_{ nullptr };
	int size_;

};

#endif //MATRIX 05102018

