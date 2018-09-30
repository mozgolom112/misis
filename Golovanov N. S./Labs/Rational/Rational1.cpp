#include "Rational.h"




																									//описание bool класса Rational

bool Rational::operator==(const Rational& rhs) {
	return (num == rhs.num) && (den == rhs.den); //в упрощенном варианте. Ибо дроби 1/2 = 2/4 и т.п.
}

bool Rational::operator!=(const Rational& rhs) {
	return !(operator==(rhs));
}


																									//описание операций и функций класса Rational
Rational& Rational::operator+=(const int numerator) { return operator+=(Rational(numerator)); }

Rational& Rational::operator-=(const int numerator) { return operator-=(Rational(numerator)); }

Rational& Rational::operator*=(const int numerator) { return operator*=(Rational(numerator)); }

Rational& Rational::operator/=(const int numerator) { return operator/=(Rational(numerator)); }


Rational& Rational::operator+=(const Rational& rhs) {

	if (rhs.den == den) { num += rhs.num; }
	else
	{
		int a = 1;
		//int a = GCD(rhs); 
		if (rhs.den > den) a = GCD1(rhs.den, den);
		else a = GCD1(den, rhs.den);
		num = (num * rhs.den + rhs.num*den) / a;
		den = den * (rhs.den / a);
	}

	return *this;
}


Rational& Rational::operator-=(const Rational& rhs) {
	if (rhs.den == den) {
		num -= rhs.num;
	}
	else
	{
		int a = 1;
		//int a = GCD(rhs); 
		if (rhs.den > den) a = GCD1(rhs.den, den);
		else a = GCD1(den, rhs.den);
		num = (num * rhs.den - rhs.num*den) / a;
		den = den * (rhs.den / a);
	}

	return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
	num *= rhs.num;
	den *= rhs.den;
	return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
	num *= rhs.den;
	den *= rhs.num;
	return *this;
}

int Rational::GCD(const Rational& rhs)
{
	int max = rhs.den;
	int min = den;
	if (den > rhs.den)
	{
		int max = den; int min = rhs.den;
	}
	while (max%min != 0)
	{
		int boofer = max;
		max = min;
		min = boofer % min;
	}

	return min;


}


void Rational::normalize() {
	if (num != 0 && den != 0) {
		int comma = 1;
		if (num >= den) comma = GCD1(num, den);
		else comma = GCD1(den, num);
		num /= comma;
		den /= comma;
	}
	if (den < 0) {
		num *= -1;
		den *= -1;
	}
}

																									//описание конструкторов класса Rational
Rational::Rational(const int numerator) :Rational(numerator, 1) {}

Rational::Rational(const int numarator, const int denumenator)
	: num(numarator)
	, den(denumenator) {

}




																								//начальное объявление переменных класса Rational
/*
int num(0);//numerator
int den(1);//denominator

static const char leftBrace{ '{' };
static const char separator{ '/' };
static const char rightBrace{ '}' };
*/




 																									//описание операций с типом Rational
Rational operator+(const Rational& lhs, const Rational& rhs) {
	Rational sum(lhs);
	sum += rhs;
	return sum;
}
Rational operator-(const Rational& lhs, const Rational& rhs) {
	Rational dif(lhs);
	dif -= rhs;
	return dif;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
	Rational multi(lhs);
	multi *= rhs;
	return multi;
}
Rational operator/(const Rational& lhs, const Rational& rhs) {
	Rational div(lhs);
	div /= rhs;
	return div;
}


//описание функций и inline


int GCD1(int max, int min) {
	if (min == 0) return max;
	else return GCD1(min, max%min);

}



std::ostream& Rational::writeTo(std::ostream& ostrm) const {
	ostrm << leftBrace << num << separator << den << rightBrace;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) {
	char leftBrace(0);
	int numerator(0);
	char comma(0);
	int denumerator(1);
	char rightBrace(0);
	istrm >> leftBrace >> numerator >> comma >> denumerator >> rightBrace;
	if (istrm.good()) {
		if ((Rational::leftBrace == leftBrace) && (Rational::rightBrace == rightBrace) && (Rational::separator == comma)) {
			num = numerator;
			den = denumerator;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}

	return istrm;
}


