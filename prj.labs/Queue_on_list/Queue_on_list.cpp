#include <iostream>

using namespace std;

class Queue_on_list {
public:
    Queue_on_list() = default;

    Queue_on_list(const Queue_on_list &copy);

    Queue_on_list &operator=(const Queue_on_list &rhs);

    ~Queue_on_list(); //Удалять придеться очень внимательно, ибо все ссылки нужно удалить!

    void push(int nw_value);

    void pop();

    int top();

    bool isEmpty() const;


private:
    struct Node_ {
        Node_(int nw_value) : value_(nw_value) {};

        Node_() = default;

        int value_{0};
        Node_ *pNext_{nullptr};                                //указатель на следующий узел
    };

    Node_ *pHead_{nullptr};
};

Queue_on_list::Queue_on_list(const Queue_on_list &copy) {
    if (copy.pHead_ != nullptr) {
        Node_ *pTail = copy.pHead_;
        Node_ *temp_Node = new Node_(copy.pHead_->value_);     //создали первый элемент
        Node_ *prev_temp_Node = temp_Node;                     //сюда будем класть указатель на предыдущий узел
        pHead_ = temp_Node;                                    //присвоили голову

        while (pTail->pNext_ != nullptr) {
            pTail = pTail->pNext_;
            temp_Node = new Node_(pTail->value_);           //создаем новый узел

            prev_temp_Node->pNext_ = temp_Node;            //кладем на него ссылку в предыдущий
            prev_temp_Node = temp_Node;                    //ставим этот указатель, как предыдущий
        }
    }
}

Queue_on_list &Queue_on_list::operator=(const Queue_on_list &rhs) {
    if ((this != &rhs) && ((this->pHead_ == nullptr) && (rhs.pHead_ == nullptr))) {  //второе условие если оба пустые ? можно ли сравнить головы
        Node_ *rhs_tail = rhs.pHead_;                       //хвост правого списка

        Node_ *temp_Node; //для временных узлов

        if ((rhs_tail != nullptr) &&(pHead_ == nullptr)) {        //на случай, если у нас слева пустой список, тогда создаем в ручную первый элемент
            temp_Node = new Node_();
            pHead_ = temp_Node;
        }

        Node_ *this_tail = pHead_;
        Node_ *prev_tail = pHead_;

        while (rhs_tail != nullptr) {
            if (this_tail != nullptr) {                //если узел уже есть, то просто меняем значение
                this_tail->value_ = rhs_tail->value_;

                prev_tail = this_tail;
                this_tail = this_tail->pNext_;
            } else {                                 //если узла нет, то создаем новый
                temp_Node = new Node_(rhs_tail->value_);
                prev_tail->pNext_ = temp_Node;
                prev_tail = temp_Node;
            }
            rhs_tail = rhs_tail->pNext_;
        }

        //удаляем остатки от первого

        if (prev_tail != nullptr) {                    //на случай если у нас пустой список слева

            this_tail = prev_tail->pNext_;            // из последнего указателя сохраняем pNext_
            prev_tail->pNext_ = nullptr;              //обрезаем сразу конец

            while (this_tail != nullptr) {            //удаляем по очереди все узлы друг за другом
                prev_tail = this_tail->pNext_;        //перед удалением сохраним указатель на следующий узел. Здесь prev_tail используеться в качестве буфера
                delete this_tail;                    //уничтожаем узел
                this_tail = prev_tail;
            }
        }
        //если у нас справа был пустой список, то нужно удалить еще и голову
        if (rhs.pHead_ == nullptr) {
            delete pHead_;
            pHead_ = nullptr;
        }


    }
    return *this;
}


Queue_on_list::~Queue_on_list() {
    while (!isEmpty()) {
        pop();
    }
}

void Queue_on_list::push(int nw_value) {
    Node_ *nw_Node = new Node_(nw_value);
    if (isEmpty()) { //был пустой список
        pHead_ = nw_Node;
    } else {
        Node_ *pTail = pHead_;
        while (pTail->pNext_ != nullptr) { //идем в конец
            pTail = pTail->pNext_;
        }
        pTail->pNext_ = nw_Node;
    }
}

void Queue_on_list::pop() {
    if (isEmpty()) {
        std::runtime_error("List is empty");
    } else {
        Node_ *pForDelete = pHead_;
        pHead_ = pHead_->pNext_;
        delete pForDelete;
    }
}

int Queue_on_list::top() {
    if (isEmpty()) {
        std::runtime_error("List is empty");
    } else {
        return pHead_->value_;
    }
}

bool Queue_on_list::isEmpty() const {
    return pHead_ == nullptr;
}


int main() {
    Queue_on_list test;

    test.push(-1);

    test.push(-2);

    test.push(-3);

    test.push(-4);

    Queue_on_list test2;

    Queue_on_list test13_1;
    test13_1.push(1);
    test13_1.push(2);
    test13_1.push(3);

    test13_1 = test;

    test13_1 = test2;

    test13_1 = test2;

}
