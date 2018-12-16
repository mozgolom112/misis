#include <iostream>
#include <exception>
#include "../Queue.h"

int main() {

    Queue<int> q1;
    for (int i(0); i < 10; i++) {
        q1.push(i + 1);
    }
    Queue<int> newQ;
    newQ = q1;
    std::cout << "------------------------" << std::endl;

    for (int i(0); i < 50; i++) { //раскрутка очереди
        try {
            std::cout << newQ.top() << std::endl;
        }
        catch (std::exception) {

        }

        newQ.pop();
    }

    std::cout << "------------------------" << std::endl;
    for (int i(0); i < 6; i++) {
        //std::cout << q1.top() << std::endl;
        q1.pop();
    }

    for (int i(0); i < 23; i++) {
        q1.push(i + 1);
    }
    std::cout << "------------------------" << std::endl;
    newQ = q1;
    for (int i(0); i < 50; i++) { //раскрутка очереди
        try { std::cout << q1.top() << std::endl; }
        catch (std::exception) {

        }

        q1.pop();
    }
    std::cout << "------------------------" << std::endl;

    for (int i(0); i < 50; i++) { //раскрутка очереди
        try {
            std::cout << newQ.top() << std::endl;
        }
        catch (std::exception) {

        }

        newQ.pop();
    }



    //q1.pop();

    //std::cout << q1.top() << std::endl;

}