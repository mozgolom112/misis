#include "../Queue_with_priority.h"
#include <iostream>

using namespace std;

int main() {

    QueuePriorty test;
    test.push(11, 1);
    test.push(13, 1);
    test.push(17, 1);
    test.push(12, 1);
    test.push(21, 2);
    test.push(31, 3);
    test.push(51, 5);

    test.push(41, 4);
    //test.pop();
    test.push(01, 0);
    for (int i(0); i < 10; i++) {
        cout << test[i] << endl;
    }
    cout << "-------------" << endl;
    test.push(02, 0);
    //test.push(29, 2);
    for (int i(0); i < 10; i++) {
        cout << test[i] << endl;
    }
    cout << "-------------" << endl;
    //	test.push(03, 0);
    test.pop();
    test.pop();

    test.pop();
    test.pop();
    test.pop();
    test.pop();
    test.pop();
    test.pop();
    test.pop();
    for (int i(0); i < 10; i++) {
        cout << test[i] << endl;
    }
    cout << "-------------" << endl;
    test.push(12, 1);
    test.push(21, 2);
    test.push(31, 3);
    test.push(51, 5);


    for (int i(0); i < 10; i++) {
        cout << test[i] << endl;
    }
    cout << "-------------" << endl;
    test.pop();
    test.pop();

    test.pop();
    test.pop();
    QueuePriorty testcopy;
    testcopy = test;
    test.pop();
    test.pop();

    test.pop();
    test.pop();
    test.pop();
    test.pop();
    test.pop();
    test.pop();


    for (int i(0); i < 10; i++) {
        cout << test[i] << endl;
    }

    cout << "-------------" << endl;

    test.push(21, 2);
    test.push(31, 3);
    test.push(31, 3);
    //test.push(61, 6);

    for (int i(0); i < 10; i++) {
        cout << test[i] << endl;
    }

    cout << "-------------" << endl;

    for (int i(0); i < 10; i++) {
        cout << testcopy[i] << endl;
    }

}