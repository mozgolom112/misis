#pragma once

#ifndef QUEUEWITHPRIORITY 17122018
#define QUEUEWITHPRIORITY 17122018

class QueuePriorty {
public:
    QueuePriorty();

    QueuePriorty(const int &size);

    QueuePriorty(QueuePriorty &copy);

    ~QueuePriorty();

    QueuePriorty &operator=(QueuePriorty &rhs);

    int &operator[](const int i); //для теста

    void push(const int &key, const int data); // добавление
    void pop(); //удаление
    bool isEmpty();

private:
    struct element {
        element() = default;

        element(const int &data, const int &key) {
            data_ = data;
            key_ = key;
        };

        int data_{0};
        int key_{0};
    };

    element *queue_{nullptr};
    int size_of_queue_{0};
    int ifirst_{0};
    int ilast_{-1};
};
#endif // !QUEUEWITHPRIORITY 17122018
