#include <iostream>
#include "..\stack_on_list.h"


using namespace std;

int main() {
    Stack<double> stack1;
    stack1.push(0.0);
    stack1.push(8.1);
    stack1.push(3.0);
    stack1.push(0.4);
    stack1.push(1.3);
    stack1.push(7.7);
    stack1.push(6.5);
    cout << "stack1 = " << stack1 << endl;
    double k = stack1.top();
    cout << "stack1.top() = " << k << endl;
    stack1.push(2.1);
    cout << "stack1.push(2.1) = " << stack1 << endl;
    stack1.pop();
    cout << "stack1.pop() = " << stack1 << endl;
    Stack<double> stack2(stack1);
    cout << "stack2 = " << stack2 << endl;
}