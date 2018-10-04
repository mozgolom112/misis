#include "dynamicarray.h"
#include "matrix.h"
#include <iostream>

using namespace std;


int main() {

	DynamicArray b1(2);
	DynamicArray b2(4);
	DynamicArray b3(b2);


	int a(b2.size());
	for (int i(0); i < a; i++) { //b2.size() убери нафиг потом
		b2[i] = i;
	}


	for (int i(0); i < a; i++) {
		cout << b2[i] << " " << endl;
	}
	cout << "-----------" << endl;
	int b = b3.size();
	for (int i(0); i < b; i++) { //b2.size() убери нафиг потом
		b3[i] = i + 6;
	}

	Matrix M;
	Matrix M1(4);
	Matrix M2(b3);

	cout << M2[1][2] << endl;




}