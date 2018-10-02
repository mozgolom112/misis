#include <iostream>
#include <sstream>

class Rational
{
public:
	//Конструкторы
	Rational() = default;
	explicit Rational(const int numerator);
	Rational(const int numarator, const int denominator);

	//булева операторы и просто операторы(без тела) Тупо объявляем, за исключением булев.


	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int numerator); //если решим прибавить просто число

	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const int numerator);

	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const int numerator);
	Rational& operator/=(const Rational& rhs);
	Rational& operator/=(const int numerator);



	std::ostream& writeTo(std::ostream& ostrm) const; //операторы
	std::istream& readFrom(std::istream& istrm); //не const!!! 


	int GCD(const Rational& rhs); //greatest common divisor НОД
	void normalize();
	
	bool operator==(const Rational& rhs);
	bool operator!=(const Rational& rhs);
	
	static const char leftBrace{ '{' };
	static const char separator{ '/' };
	static const char rightBrace{ '}' };

private:
	int num{ 0 };//numerator
	int den{ 1 };//denominator
	
	
	
};




int GCD1(int max, int min);



Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator+(const Rational& lhs, const Rational& rhs);
