#include <iostream>
#include <exception>
#include "Queue_with_priority.h"

using namespace std;

QueuePriorty::QueuePriorty() : size_of_queue_(10) {
    queue_ = new element[size_of_queue_];
}

QueuePriorty::QueuePriorty(const int &size) : size_of_queue_(size) {
    queue_ = new element[size_of_queue_];
}

QueuePriorty::~QueuePriorty() {
    delete[] queue_;
    queue_ = nullptr;
}

QueuePriorty::QueuePriorty(QueuePriorty &copy) {
    size_of_queue_ = copy.size_of_queue_;
    queue_ = new element[size_of_queue_];
    ilast_ = copy.ilast_;
    ifirst_ = copy.ifirst_;
    for (int i(0); i < size_of_queue_; i++) {
        queue_[i] = copy.queue_[i];
    }
}

void QueuePriorty::push(const int &data, const int key) {
    //��������, ���� ���� � ��� �������������. �� ���������, ������������� ����� ������ � ���������, ������� ���� �������
    if (key < 0) {
        throw ::exception("���� �� ����� ���� �������������");
    }
    //���� � ��� ������ �������
    if (ilast_ >= 0) {
        //�������� �� ���������������
        if (((ilast_ + 1) % size_of_queue_ == ifirst_ % size_of_queue_)) {
            throw ::exception("������� �����������");
        }
    }
    //���� � ��� ������ �������, ����� ���������, ��� � ��� ��������� ������� ����� ����, ������ ������������
    if ((queue_[ilast_].key_ <= key) || (ilast_ < 0)) {
        queue_[(ilast_ + 1) % size_of_queue_] = element(data, key);
    } else {
        int firstpos = ifirst_;
        //���� � ��� �� ���� ������, �� ������ ��� ����, ����� ����� � ����� ���������� 0 �������
        if (ifirst_ == 0) {
            firstpos = size_of_queue_;
        }

        //������ ����� � �����, � ������� ��������, �� ��� ���, ���� � ��� �� �������� ����� �� ����, ��� ������
        for (int i(ilast_); i != (firstpos - 1) % size_of_queue_; i--) {
            if ((queue_[i].key_ <= key)) {
                queue_[(i + 1) % size_of_queue_] = element(data, key);
                break; //���� �������
            } else {
                queue_[(i + 1) % size_of_queue_] = queue_[i]; //������ ��������

            }
            if (i ==
                0) { //���� � ��� ���� �������� � ������ ����� �������, ����� ������ ������������, � ���������� ��� � �����
                i = size_of_queue_;
            }
            if ((i - 1) == (firstpos - 1) % size_of_queue_) { //���� ����������� ������� ������ � �������
                queue_[(i) % size_of_queue_] = element(data, key);
            }
        }
    }
    ilast_ = (ilast_ + 1) % size_of_queue_;

}

void QueuePriorty::pop() {
    if (isEmpty()) {
        cout << "������� �����" << endl;
        //���������� ��������
        ilast_ = -1;
        ifirst_ = 0;
    } else {
        queue_[ifirst_] = element(-1, -1); //��������
        ifirst_ = (ifirst_ + 1) % size_of_queue_;

    }
}


bool QueuePriorty::isEmpty() {
    //�������� �� ��������� ��������� ����� ������. �������� ��������, ����� � ��� ������ ������, ������� ������ �������������� �������, ��� ������� � ������� first ��� ��������
    return ((ilast_ + 1) % size_of_queue_ == ifirst_ % size_of_queue_) && (queue_[ifirst_].key_ < 0);
}

int &QueuePriorty::operator[](const int i) {
    //��� ������
    return queue_[i].data_;
}

QueuePriorty &QueuePriorty::operator=(QueuePriorty &rhs) {
    if (this != &rhs) {
        if (size_of_queue_ < rhs.size_of_queue_) {
            delete[] queue_;
            queue_ = new element[rhs.size_of_queue_];
        }
        size_of_queue_ = rhs.size_of_queue_;
        if (rhs.ilast_ < 0) {
            ilast_ = -1;
        } else {
            queue_[0] = rhs.queue_[rhs.ifirst_];
            ilast_ = 1;
            for (int i(rhs.ifirst_ + 1); ((i) % size_of_queue_) != ((rhs.ilast_ + 1) % size_of_queue_); ++i, ++ilast_) {
                queue_[ilast_] = rhs.queue_[i % size_of_queue_];
            }
            ifirst_ = 0;
        }
        ilast_--;
    }
    return *this;
}
