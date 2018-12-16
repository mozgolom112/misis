#pragma once

#ifndef RATIONAL 21102018
#define RATIONAL 21102018


#include <iostream>
#include <sstream>

class Rational {
public:
    //������������
    Rational() = default;

    explicit Rational(const int numerator);

    Rational(const int numarator, const int denominator);

    //������ ��������� � ������ ���������(��� ����) ���� ���������, �� ����������� �����.


    Rational &operator+=(const Rational &rhs);

    Rational &operator+=(const int numerator); //���� ����� ��������� ������ �����

    Rational &operator-=(const Rational &rhs);

    Rational &operator-=(const int numerator);

    Rational &operator*=(const Rational &rhs);

    Rational &operator*=(const int numerator);

    Rational &operator/=(const Rational &rhs);

    Rational &operator/=(const int numerator);


    std::ostream &writeTo(std::ostream &ostrm) const; //���������
    std::istream &readFrom(std::istream &istrm); //�� const!!!


    int GCD(const Rational &rhs); //greatest common divisor ���
    void normalize();

    bool operator==(const Rational &rhs);

    bool operator!=(const Rational &rhs);

    static const char leftBrace{'{'};
    static const char separator{'/'};
    static const char rightBrace{'}'};

    int getNumerator();

    int getDenumerator();

    int getNumerator() const;

    int getDenumerator() const;

private:
    int num{0};//numerator
    int den{1};//denominator



};


int GCD1(int max, int min);


Rational operator-(const Rational &lhs, const Rational &rhs);

Rational operator*(const Rational &lhs, const Rational &rhs);

Rational operator/(const Rational &lhs, const Rational &rhs);

Rational operator+(const Rational &lhs, const Rational &rhs);

#endif //RATIONAL 21102018