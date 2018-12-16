#ifndef QUEUE 11112018
#define QUEUE 11112018

#include <exception>


template<typename T>
class Queue {
public:
    Queue();

    Queue(const int size);

    Queue(const Queue &copy); //конструктор
    Queue &operator=(const Queue &rhs);

    ~Queue();

    void push(const T &element); //добавление
    void pop();// удаление
    T &top();// вывод первого элемента
    bool IsEmpty();//проверка на пустоту

    void Resize();

private:
    T *quene_{nullptr};
    int first_{0}; //место первого
    int last_{-1}; //место последнего
    int size_of_massive{0}; //размер массива, а не очереди!!!
};


template<typename T>
Queue<T>::Queue() {
    quene_ = new T[10];
    size_of_massive = 10;
}

template<typename T>
Queue<T>::Queue(const int size) :size_of_massive(size) {
    if (size_of_massive < 0) {
        throw ::std::exception("Размер массива не может быть отрецательным!");
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
    bool start = true; //флаг на начало. Чтобы у нас не было resize при вставки первого элемента
    if (last_ < 0) { start = false; } //значит первой вставки еще не происходило
    last_++;
    if (last_ == size_of_massive) //вышли за пределы массива и перемещаемся в начало
        last_ = 0;
    if (((last_ + 1) % size_of_massive == first_ % size_of_massive) &&
        start) //необходимо увеличить массив, если у нас следующий будет последним в текущем массиве, для того чтобы isEmpty работал корректно
        Resize(); //когда у нас один элемент, выскакивает тоже
    quene_[last_] = element;

}

template<typename T>
void Queue<T>::pop() {
    if (!IsEmpty()) {// сначало проверяем, не пусто ли у нас
        first_++;
        if (first_ == size_of_massive) //если вышли за пределы массива
            first_ = 0;
        if (IsEmpty()) { //если это был последний элемент, сбрасываем начало и конец
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
void Queue<T>::Resize() //если массив у нас переполнился
{

    T *temp = new T[2 * size_of_massive];

    temp[0] = quene_[first_];
    for (int i(first_ + 1), q(1); ((i) % size_of_massive) != (first_ % size_of_massive); ++i, ++q) {
        temp[q] = quene_[i % size_of_massive];
    }


    delete[] quene_;
    quene_ = temp; //ссылаемся на новый массив
    first_ = 0;//ставим на ноль
    last_ = size_of_massive - 1; //размер предыдущего массива - 1, потому что у нас теперь всегда пропадает одно место
    size_of_massive = 2 * size_of_massive;


}


#endif //QUEUE 11112018