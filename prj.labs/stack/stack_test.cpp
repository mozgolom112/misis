/*

//автоматическая генерация шабл. класса
template <typename F, typename S>
struct MyStruct
{

};

template <typename F, typename S>
MyStruct<F, S> make_pair(const F& f, const S& s) {
	return MyStruct<F, S>(f, s);
}









//нетипизированный параметр

template <class T, int Size>
class Agr1 {
	Agr1();
private:
	T data_[Size]{ T() };
};



//шаблонный метод

template <class T>
class Agr {
public:
	Agr() = default;
	template<typename U>
	void mult(const U& rhs);
};






// шаблонный тип

template <class T>
class Stack {
public:
	Stack();


	T& getTop() {};

private:
	T* pData_{ nullptr };


};


//шаблонная функция
template <typename T>
const T& min(const T& lhs, const T& rhs)
{
	return (lhs < rhs) ? lhs : rhs;
}








*/

#include <exception>;
#include <iostream>;




template <typename T>

class Stack {
public:
	Stack();
	Stack(const int& maxsize);
	Stack(const Stack<T>& copy);
	
	
	void push(T& new_element);// добавление нового элемента на вершину
	T pop(); //удаление верхнего элемента стека и возвращает 3) нужен ли возврат
	void simplepop();//просто удаление
	const T& peek(int place); //обращение к n-ому элементу стека
	int getSizeofStack() const;
	T* getPtr() const; //return
	int getTop() const; //return top_
	
	~Stack();


	void printStack();

private:
	T* stackPtr_{ nullptr }; //укзатель на стек
	const int size_; //максимальный размер стека
	int top_; //номер текущего(верхнего) элемента стека


};



//constructor with destroctor
template<typename T>
Stack<T>::Stack() {
	size_ = 0;
	stackPtr_ = new T[size_];
	top_ = 0;
}


template<typename T>
Stack<T>::Stack(const int& maxsize) : size_(maxsize) {
	

	if (size_ < 0) {
		throw std::exception ("Invalid argument for stack's size");
	}

	stackPtr_ = new T[size_];
	top_ = 0;
}



template <typename T> //1) как сделать так,чтобы автоматически ставился тот тип, который в copy уже стоит?
Stack<T>::Stack(const Stack<T>& copy) {
	size_ = copy.getSizeofStack();
	stackPtr_ = new T[size_];
	top_ = copy.getTop();

	for (int i(0); i < top_; i++) {
		stackPtr_[i] = copy.getPtr()[i];
	}

}


template <typename T>
Stack<T>::~Stack() {
	delete[] stackPtr_;
	stackPtr_= nullptr ;
}



template<typename T>
void Stack<T>::printStack()
{

	for (int i(top_ - 1); i >= 0; i--) //начинаем печатать сверху стека!
	{
		std::cout << "|     " << stackPtr_[i] << std::endl;
	}
}


template <typename T>
int Stack<T>::getTop() const {
	return top_;
}

template <typename T>
T* Stack<T>::getPtr() const {
	return stackPtr_;
}

template <typename T>

void Stack<T>::push(T& newelement) {
	
	if (top_ >= size_) {
		throw std::exception("Stack is over. You can't add another element");
	}
	else {
		stackPtr_[top_] = newelement;
	}
	top_++;
}

template <typename T>
T Stack<T>::pop() {
	
	if (top_ == 0) {
		throw std::exception("Stack has already been empty");
	}
	else {
		return stackPtr_[top_];
		--top_;
	}


		
}

template <typename T>
void Stack<T>::simplepop() {
	
	if (top_ == 0) {
		throw std::exception("Stack has already been empty");
	}
	else
		//stackPtr_[top_] = default T; //2)надо как-то занулить
		--top_;
}

template<typename T>
const T& Stack<T>::peek(int place)
{
	if ((place < 0) && (place >= size_)) {
		throw std::exception("Out of stack");
	}
	if (place <= top_)
	{
		return stackPtr_[top_ - place];
	}
	else throw std::exception("This element under place doesn't exist");

}


template<typename T>
int Stack<T>::getSizeofStack() const{
	return size_;
}


using namespace std;
int main() {
	
	Stack<int> a(6);
	int b = 1;
	
	a.push(b);
	a.push(++b);
	a.push(++b);
	a.push(++b);
	a.push(++b);
	a.push(++b);

	cout << a.getPtr()[a.getTop()] << endl;
	cout << a.peek(6); 
	cout << a.getPtr()[0] << " " << a.getPtr()[1]<< " " << a.getPtr()[2] << endl;

	a.printStack();

	a.simplepop();
	a.simplepop();
	a.simplepop();


	a.printStack();

	cout << a.getPtr()[5];

}
