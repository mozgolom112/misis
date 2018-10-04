#include "dynamicarray.h"
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


	for (int i(0); i < a; i++) {
		cout << b3[i] << " " << endl;
	}
	cout << "-----------" << endl;
	DynamicArray b4(6);
	DynamicArray b5(2);

	b4 = b3;
	int c = b4.size();
	for (int i(0); i < c; i++) {
		cout << b4[i] << " " << endl;
	}
	cout << "-----------" << endl;

	b5 = b2;
	int d = b5.size();
	for (int i(0); i < d; i++) {
		cout << b5[i] << " " << endl;
	}
	cout << "-----------" << endl;






}
