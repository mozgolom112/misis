#include "../dynamicarray.h"
#include <iostream>
using namespace std;


void testConstructor(DynamicArray& dynamicarray, int size, double* data) {
	bool result_of_size;
	result_of_size = (dynamicarray.size() == size);
	if (result_of_size) {
		cout << "Size was set right" << endl;
	}
	else
	{
		cout << "Size was set wrong" << endl;
	}

	bool result_of_data = true;

	for (int i(0); i < dynamicarray.size(); i++) {
		if (dynamicarray[i] != data[i]) {
			result_of_data = false;
		}
	}
	for (int i(0); i < size; i++) {
		cout << dynamicarray[i] << " ";
	}
	


	if (result_of_data) {
		cout << "Data was set right" << endl;

	}
	else {
		cout << "Data was set wrong" << endl;
	}

}



void testIndex() {
	double sample = 10;
	DynamicArray dynamicarray(5);
	dynamicarray[0] = sample;

	bool result_of_index;
	result_of_index = (sample == dynamicarray[0]);
	if (result_of_index) {
		cout << "Index work right" << endl;
	}
	else {
		cout << "Index work wrong" << endl;
	}
}

void testOutofRange() {
	DynamicArray dynamicarray(5);
	bool hasException = false;
	try {
		dynamicarray[10] = 10;
	}
	catch(exception){
		hasException = true;
	}
	if (hasException) {
		cout << "Test indexer out of range dynamicArray[10] == 10 passed" << endl;
	}
	else
	{
		cout << "Test indexer out of range dynamicArray[10] == 10 failed" << endl;
	}


}


void testResize()
{
	int oldSize = 5;
	int newSize = 3;
	DynamicArray dynamicarray(oldSize);

	dynamicarray.resize(newSize);

	bool result = (dynamicarray.size() == newSize);
	if (result)
		cout << "Test resize from " << oldSize << " to " << newSize << " passed" << endl;
	else
		cout << "Test resize from " << oldSize << " to " << newSize << " failed" << endl;

	bool result2 = true;
	for (int i(0); i < newSize; i++)
	{
		if (dynamicarray[i] != 0)
		{
			result2 = false;
		}
	}

	if (result2)
		cout << "Test resize data safety passed" << endl;
	else
		cout << "Test resize data safety failed" << endl;

}

int main() {
	
	DynamicArray a1;
	testConstructor(a1, 0, new double[0]);
	cout << "------------------" << endl;
	DynamicArray a2(5);
	testConstructor(a2, 5, new double[5]{0, 0, 0, 0 ,0});
	cout << "------------------" << endl;
	DynamicArray a3(a2);
	testConstructor(a3, 5, new double[5]{ 0, 0, 0, 0 ,0 });
	cout << "------------------" << endl;


	testIndex();
	cout << "------------------" << endl;

	testOutofRange();
	cout << "------------------" << endl;

	testResize();
	cout << "------------------" << endl;


}