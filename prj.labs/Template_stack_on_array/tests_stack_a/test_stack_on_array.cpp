#include "..\stack_on_array.h"

using namespace std;

int main() {

    Stack<int> a(6);
    int b = 1;

    a.push(b);
    a.push(++b);
    a.push(++b);
    a.push(++b);
    a.push(++b);


    a.printStack();
    cout << "--------------------" << endl;
    a.pop();
    a.pop();
    a.pop();
    Stack<int> c(2);
    c = a;
    c = c = c;
    //a.pop();
    a.pop();
    a.printStack();
    cout << "--------------------" << endl;
    c.printStack();
    cout << "--------------------" << endl;


}
