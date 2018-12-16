#pragma once

#ifndef COMPLEX 20102018
#define COMPLEX 20102018

#include <iostream>
#include <sstream>


struct Complex {
    Complex() = default; // �� ������� ������
    explicit Complex(const double real);

    Complex(const double real, const double imaginary);

    bool operator==(
            const Complex &rhs) const; //��, ��� � ������� (Complex& rhs), ��� rhs - �� ��������� ���� Complex. ����������� ���������� ����� ��.���������. �.�. �������� ������, �� ���������� �� ������. ���� ���
    bool operator!=(
            const Complex &rhs) const; //const { return (re != rhs.re) || (im != rhs.im); } �� ��� ����� ���� � �� ��� ����� ��� ������. �� ��� ������!!!
    Complex &operator+=(const Complex &rhs);

    Complex &operator+=(const double rhs) { return operator+=(Complex(rhs)); }

    Complex &operator-=(const Complex &rhs);

    Complex &operator-=(const double rhs) { return operator-=(Complex(rhs)); }

    Complex &operator*=(const Complex &rhs);

    Complex &operator*=(const double rhs) { return operator*=(Complex(rhs)); }


    std::ostream &writeTo(std::ostream &ostrm) const;  //std::ostream - ���, ostrm
    std::istream &readFrom(std::istream &istrm);


    double re{0.0};
    double im{0.0}; //syn. double example = 0.0; �� ������� ��������


    static const char leftBrace{'{'};
    static const char separator{','};
    static const char rightBrace{'}'};
};

Complex operator+(const Complex &lhs, const Complex &rhs);

Complex operator-(const Complex &lhs, const Complex &rhs);

#endif //COMPLEX 20102018