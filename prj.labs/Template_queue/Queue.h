#ifndef QUEUE 11112018
#define QUEUE 11112018

#include <exception>


template<typename T>
class Queue {
public:
    Queue();

    Queue(const int size);

    Queue(const Queue &copy); //�����������
    Queue &operator=(const Queue &rhs);

    ~Queue();

    void push(const T &element); //����������
    void pop();// ��������
    T &top();// ����� ������� ��������
    bool IsEmpty();//�������� �� �������

    void Resize();

private:
    T *quene_{nullptr};
    int first_{0}; //����� �������
    int last_{-1}; //����� ����������
    int size_of_massive{0}; //������ �������, � �� �������!!!
};


template<typename T>
Queue<T>::Queue() {
    quene_ = new T[10];
    size_of_massive = 10;
}

template<typename T>
Queue<T>::Queue(const int size) :size_of_massive(size) {
    if (size_of_massive < 0) {
        throw ::std::exception("������ ������� �� ����� ���� �������������!");
    }

    quene_ = new T[size_of_massive];
}

template<typename T>
Queue<T>::Queue(const Queue &copy) {
    quene_ = new T[copy.size_of_massive];
    size_of_massive = copy.size_of_massive;
    last_ = copy.last_;
    first_ = copy.first_;
    for (int i(0); i < size_of_massive; i++) {
        quene_[i] = copy.quene_[i];
    }
}

template<typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &rhs) {
    if (this != &rhs) {
        if (size_of_massive < rhs.size_of_massive) {
            delete[] quene_;
            quene_ = new T[rhs.size_of_massive];
        }
        size_of_massive = rhs.size_of_massive;
        if (rhs.last_ < 0) {
            last_ = -1;
        } else {
            quene_[0] = rhs.quene_[rhs.first_];
            last_ = 1;
            for (int i(rhs.first_ + 1); ((i) % size_of_massive) != ((rhs.last_ + 1) % size_of_massive); ++i, ++last_) {
                quene_[last_] = rhs.quene_[i % size_of_massive];
            }
            first_ = 0;
        }
        last_--;
    }
    return *this;
}

template<typename T>
Queue<T>::~Queue() {
    delete[] quene_;
    quene_ = nullptr;
}

template<typename T>
void Queue<T>::push(const T &element) {
    bool start = true; //���� �� ������. ����� � ��� �� ���� resize ��� ������� ������� ��������
    if (last_ < 0) { start = false; } //������ ������ ������� ��� �� �����������
    last_++;
    if (last_ == size_of_massive) //����� �� ������� ������� � ������������ � ������
        last_ = 0;
    if (((last_ + 1) % size_of_massive == first_ % size_of_massive) &&
        start) //���������� ��������� ������, ���� � ��� ��������� ����� ��������� � ������� �������, ��� ���� ����� isEmpty ������� ���������
        Resize(); //����� � ��� ���� �������, ����������� ����
    quene_[last_] = element;

}

template<typename T>
void Queue<T>::pop() {
    if (!IsEmpty()) {// ������� ���������, �� ����� �� � ���
        first_++;
        if (first_ == size_of_massive) //���� ����� �� ������� �������
            first_ = 0;
        if (IsEmpty()) { //���� ��� ��� ��������� �������, ���������� ������ � �����
            last_ = -1;
            first_ = 0;
        }

    }
}

template<typename T>
T &Queue<T>::top() {
    if (IsEmpty() && (last_ != (size_of_massive - 1))) {
        throw std::exception("Error. Quene is empty");
    }
    return quene_[first_];
}

template<typename T>
bool Queue<T>::IsEmpty() {


    return ((last_ + 1) % size_of_massive == first_ % size_of_massive);
}

template<typename T>
void Queue<T>::Resize() //���� ������ � ��� ������������
{

    T *temp = new T[2 * size_of_massive];

    temp[0] = quene_[first_];
    for (int i(first_ + 1), q(1); ((i) % size_of_massive) != (first_ % size_of_massive); ++i, ++q) {
        temp[q] = quene_[i % size_of_massive];
    }


    delete[] quene_;
    quene_ = temp; //��������� �� ����� ������
    first_ = 0;//������ �� ����
    last_ = size_of_massive - 1; //������ ����������� ������� - 1, ������ ��� � ��� ������ ������ ��������� ���� �����
    size_of_massive = 2 * size_of_massive;


}


#endif //QUEUE 11112018