#pragma once

#ifndef DYNAMICARRAY 05102018
#define DYNAMICARRAY 05102018

class DynamicArray {
public:
    DynamicArray();

    DynamicArray(const int size);

    DynamicArray(const DynamicArray &copy);

    ~DynamicArray(); //об¤зательно объ¤вл¤й дальше, иначе вылезет ошибка линковщика!!!


    DynamicArray &operator=(const DynamicArray &rhs);

    double &operator[](const int i);

    int size() const;

    void resize(const int new_size);

private:
    int size_{};
    double *data_{nullptr}; //не забывай присваивать невалидный адрес
};

#endif
