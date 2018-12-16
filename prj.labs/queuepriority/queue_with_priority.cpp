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
    //проверка, если ключ у нас отрицательный. По умолчанию, отрицательные ключи только у элементов, которые были удалены
    if (key < 0) {
        throw ::exception("Ключ не может быть отрицательным");
    }
    //если у нас первый элемент
    if (ilast_ >= 0) {
        //проверка на переполненность
        if (((ilast_ + 1) % size_of_queue_ == ifirst_ % size_of_queue_)) {
            throw ::exception("Очередь переполнена");
        }
    }
    //если у нас первый элемент, сразу вставляем, или у нас последний элемент имеет ключ, меньше вставляемого
    if ((queue_[ilast_].key_ <= key) || (ilast_ < 0)) {
        queue_[(ilast_ + 1) % size_of_queue_] = element(data, key);
    } else {
        int firstpos = ifirst_;
        //если у нас не было сдвига, то меняем для того, чтобы позже в цикле обработать 0 элемент
        if (ifirst_ == 0) {
            firstpos = size_of_queue_;
        }

        //делаем обход с конца, и смещаем элементы, до тех пор, пока у нас не найдется такой же ключ, или больше
        for (int i(ilast_); i != (firstpos - 1) % size_of_queue_; i--) {
            if ((queue_[i].key_ <= key)) {
                queue_[(i + 1) % size_of_queue_] = element(data, key);
                break; //либо брейком
            } else {
                queue_[(i + 1) % size_of_queue_] = queue_[i]; //делаем смещение

            }
            if (i ==
                0) { //если у нас было смещение в начало конца очереди, обход должен продолжиться, и перемещаем его в конец
                i = size_of_queue_;
            }
            if ((i - 1) == (firstpos - 1) % size_of_queue_) { //если вставляемый элемент первый в очереди
                queue_[(i) % size_of_queue_] = element(data, key);
            }
        }
    }
    ilast_ = (ilast_ + 1) % size_of_queue_;

}

void QueuePriorty::pop() {
    if (isEmpty()) {
        cout << "Очередь пуста" << endl;
        //сбрасываем значения
        ilast_ = -1;
        ifirst_ = 0;
    } else {
        queue_[ifirst_] = element(-1, -1); //зануляем
        ifirst_ = (ifirst_ + 1) % size_of_queue_;

    }
}


bool QueuePriorty::isEmpty() {
    //следущий за последним элементом стоит первый. Возможна ситуация, когда у нас массив полный, поэтому вводим дополнительное условие, что элемент в позиции first уже удалялся
    return ((ilast_ + 1) % size_of_queue_ == ifirst_ % size_of_queue_) && (queue_[ifirst_].key_ < 0);
}

int &QueuePriorty::operator[](const int i) {
    //для тестов
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
