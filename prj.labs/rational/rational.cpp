#include "Rational.h"
#include <stdexcept>


bool Rational::operator==(const Rational &rhs) {


    if (this != &rhs) {
        //esli delati bez normalizacii construtorov. Inache 1/2 i 2/4 ne budut sovpadati
        Rational temprhs(rhs);
        temprhs.normalize();
        Rational templhs(*this);
        templhs.normalize();

        return (templhs.num == temprhs.num) && (templhs.den == temprhs.den);
        //return (num == rhs.num) && (den == rhs.den);
    } else { return true; }

}

bool Rational::operator!=(const Rational &rhs) {
    return !(operator==(rhs));
}


Rational &Rational::operator+=(const int numerator) { return operator+=(Rational(numerator)); }

Rational &Rational::operator-=(const int numerator) { return operator-=(Rational(numerator)); }

Rational &Rational::operator*=(const int numerator) { return operator*=(Rational(numerator)); }

Rational &Rational::operator/=(const int numerator) { return operator/=(Rational(numerator)); }


Rational &Rational::operator+=(const Rational &rhs) {

    if (this != &rhs) {
        if (rhs.den == den) { num += rhs.num; }
        else {
            int a = 1;
            //int a = GCD(rhs);
            if (rhs.den > den) a = GCD1(rhs.den, den);
            else a = GCD1(den, rhs.den);
            num = (num * rhs.den + rhs.num * den) / a;
            den = den * (rhs.den / a);
        }
    } else {
        num *= 2;
    }
    this->normalize();
    return *this;
}


Rational &Rational::operator-=(const Rational &rhs) {

    if (this != &rhs) {
        if (rhs.den == den) {
            num -= rhs.num;
        } else {
            int a = 1;
            //int a = GCD(rhs);
            if (rhs.den > den) a = GCD1(rhs.den, den);
            else a = GCD1(den, rhs.den);
            num = (num * rhs.den - rhs.num * den) / a;
            den = den * (rhs.den / a);
        }
        this->normalize();
    } else {
        num = 0;
        den = 1;
    }
    return *this;
}

Rational &Rational::operator*=(const Rational &rhs) {
    num *= rhs.num;
    den *= rhs.den;
    this->normalize();
    return *this;
}

Rational &Rational::operator/=(const Rational &rhs) {

    if ((den * rhs.num) == 0) throw std::exception("You can't devide on zero");
    if (this != &rhs) {
        num *= rhs.den;
        den *= rhs.num;
        this->normalize();
    } else {
        num = 1;
        den = 1;
    }
    return *this;
}

int Rational::GCD(const Rational &rhs) {
    int max = rhs.den;
    int min = den;
    if (den > rhs.den) {
        int max = den;
        int min = rhs.den;
    }
    while (max % min != 0) {
        int boofer = max;
        max = min;
        min = boofer % min;
    }

    return min;


}


void Rational::normalize() {
    if (num == 0) den = 1;
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


Rational::Rational(const int numerator) : Rational(numerator, 1) {}

Rational::Rational(const int numarator, const int denumenator)
        : num(numarator) {
    if (denumenator == 0) {
        throw std::exception("Denumenator can't be zero");
    } else den = denumenator;
    //this->normalize(); //budet rabotati esli zakamentiti. No v sravnenii nuzhno budet razcomentit




}


Rational operator+(const Rational &lhs, const Rational &rhs) {
    Rational sum(lhs);
    if (&lhs != &rhs) {
        sum += rhs;
    } else { sum += sum; }
    return sum;
}

Rational operator-(const Rational &lhs, const Rational &rhs) {


    if (&lhs != &rhs) {
        Rational dif(lhs);
        dif -= rhs;
        return dif;
    } else {
        Rational zero(0, 1);
        return zero;
    }

}

Rational operator*(const Rational &lhs, const Rational &rhs) {
    Rational multi(lhs);
    multi *= rhs;
    return multi;
}

Rational operator/(const Rational &lhs, const Rational &rhs) {

    if (rhs.getNumerator() == 0) throw std::exception("You can't devide on zero");
    if (&lhs != &rhs) {
        Rational div(lhs);
        div /= rhs;
        return div;
    } else {
        Rational one(1, 1);
        return one;
    }


}


int GCD1(int max, int min) {
    if (min == 0) return max;
    else return GCD1(min, max % min);

}


std::ostream &Rational::writeTo(std::ostream &ostrm) const {
    ostrm << leftBrace << num << separator << den << rightBrace;
    return ostrm;
}

std::istream &Rational::readFrom(std::istream &istrm) {
    char leftBrace(0);
    int numerator(0);
    char comma(0);
    int denumerator(1);
    char rightBrace(0);
    istrm >> leftBrace >> numerator >> comma >> denumerator >> rightBrace;
    if (istrm.good()) {
        if ((Rational::leftBrace == leftBrace) && (Rational::rightBrace == rightBrace) &&
            (Rational::separator == comma)) {
            num = numerator;
            den = denumerator;
        } else {
            istrm.setstate(std::ios_base::failbit);
        }
    }

    return istrm;
}


int Rational::getNumerator() {
    return num;
}

int Rational::getDenumerator() {
    return den;
}

int Rational::getNumerator() const {
    return num;
}

int Rational::getDenumerator() const {
    return den;
}