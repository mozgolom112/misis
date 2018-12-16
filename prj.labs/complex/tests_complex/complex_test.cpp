#include "../complex.h"
#include <iostream>
#include <exception>

using namespace std;

inline std::ostream &
operator<<(std::ostream &ostrm, const Complex &rhs) //������ �������, �������� ��������� � �����������  �� ��������
{
    return rhs.writeTo(ostrm);
}

inline std::istream &operator>>(std::istream &istrm, Complex &rhs) {
    return rhs.readFrom(istrm);
}


bool testParse(const std::string &str) {
    using namespace std;
    istringstream istrm(str);
    Complex z;
    istrm >> z;
    if (istrm.good()) {
        cout << "Read success: " << str << " -> " << z << endl;
    } else {
        cout << "Read error : " << str << " -> " << z << endl;
    }
    return istrm.good();
}
//Tests

bool TestMulti(Complex &left, Complex &right, Complex &right_answer) {

    /*Complex z(-5.0, 3.0);
    Complex y(4.0, 7.0);
    Complex answer(-41, -23);*/
    Complex z(left);
    Complex y(right);
    Complex answer(right_answer);
    z *= y;
    return (z == answer);
}

bool TestEq(Complex &left, Complex &right) {
    Complex n1(left);
    Complex n2(right);
    return (n1 == n2);
}

bool Testdiffer(Complex &left, Complex &right) {
    Complex n1(left);
    Complex n2(right);
    return !(n1 == n2);
}

bool TestSum(Complex &left, Complex &right, Complex &right_answer) {
    Complex n1(left);
    Complex n2(right);
    Complex answer(right_answer);
    Complex result = n1 + n2;
    return (result == answer);
}

bool TestSub(Complex &left, Complex &right, Complex &right_answer) {
    Complex n1(left);
    Complex n2(right);
    Complex answer(right_answer);
    n1 -= n2;
    return (n1 == answer);
}


int main() {

    Complex C1(0, 0);
    Complex C2(3, 5);
    Complex C3(-3, 5);
    Complex C4(3, -5);
    Complex C5(-3, -5);
    Complex C6(0, -5);
    Complex C7(-3, 0);

    Complex C8(3.5, 5.3);
    Complex C9(-3.5, 5.3);
    Complex C10(3.2, 6.3);

    Complex C11(3.5, 5.3);

    Complex z(-5.0, 3.0);
    Complex y(4.0, 7.0);
    Complex answer(-41, -23);


    testParse("{8.9,9}");
    testParse("{\t\t\t8.9, \n9}");
    testParse("   {8.9,9");


    cout << "TestMulti for " << z << " and " << y << " Answer: " << answer << " Result: "
         << (TestMulti(z, y, answer) ? "Right" : "False") << endl;
    answer = Complex(0, 0);
    cout << "TestMulti for " << C1 << " and " << C2 << " Answer: " << answer << " Result: "
         << (TestMulti(C1, C2, answer) ? "Right" : "False") << endl;

    answer = Complex(-34, 0);
    cout << "TestMulti for " << C2 << " and " << C3 << " Answer: " << answer << " Result: "
         << (TestMulti(C2, C3, answer) ? "Right" : "False") << endl;

    answer = Complex(-16, 30);
    cout << "TestMulti for " << C2 << " and " << C2 << " Answer: " << answer << " Result: "
         << (TestMulti(C2, C2, answer) ? "Right" : "False") << endl;

    answer = Complex(0, 15);
    cout << "TestMulti for " << C6 << " and " << C7 << " Answer: " << answer << " Result: "
         << (TestMulti(C6, C7, answer) ? "Right" : "False") << endl;

    answer = Complex(-34, 0);
    cout << "TestMulti for " << C4 << " and " << C5 << " Answer: " << answer << " Result: "
         << (TestMulti(C4, C5, answer) ? "Right" : "False") << endl;

    answer = Complex(-22.19, 39.01);
    cout << "TestMulti for " << C8 << " and " << C10 << " Answer: " << answer << " Result: "
         << (TestMulti(C8, C10, answer) ? "Right" : "False") << endl;

    cout << "----------------------------" << endl;
    cout << "TestEq for " << C11 << " and " << C10 << " Eq: " << (TestEq(C11, C10) ? "Right" : "False") << endl;
    cout << "TestEq for " << C10 << " and " << C10 << " Eq: " << (TestEq(C10, C10) ? "Right" : "False") << endl;
    cout << "TestEq for " << C1 << " and " << C10 << " Eq: " << (TestEq(C1, C10) ? "Right" : "False") << endl;
    cout << "TestEq for " << C10 << " and " << C1 << " Eq: " << (TestEq(C10, C1) ? "Right" : "False") << endl;


    cout << "----------------------------" << endl;
    cout << "Testdiffer for " << C11 << " and " << C10 << " Different: " << (Testdiffer(C11, C10) ? "Right" : "False")
         << endl;
    cout << "Testdiffer for " << C10 << " and " << C10 << " Different: " << (Testdiffer(C10, C10) ? "Right" : "False")
         << endl;
    cout << "Testdiffer for " << C1 << " and " << C10 << " Different: " << (Testdiffer(C1, C10) ? "Right" : "False")
         << endl;
    cout << "Testdiffer for " << C10 << " and " << C1 << " Different: " << (Testdiffer(C10, C1) ? "Right" : "False")
         << endl;


    cout << "----------------------------" << endl;


    answer = Complex(3, 5);
    cout << "TestSum for " << C1 << " and " << C2 << " Answer: " << answer << " Result: "
         << (TestSum(C1, C2, answer) ? "Right" : "False") << endl;

    answer = Complex(0, 10);
    cout << "TestSum for " << C2 << " and " << C3 << " Answer: " << answer << " Result: "
         << (TestSum(C2, C3, answer) ? "Right" : "False") << endl;

    answer = Complex(0, -10);
    cout << "TestSum for " << C4 << " and " << C5 << " Answer: " << answer << " Result: "
         << (TestSum(C4, C5, answer) ? "Right" : "False") << endl;

    answer = Complex(-3, -5);
    cout << "TestSum for " << C6 << " and " << C7 << " Answer: " << answer << " Result: "
         << (TestSum(C6, C7, answer) ? "Right" : "False") << endl;

    answer = Complex(0, 10.6);
    cout << "TestSum for " << C8 << " and " << C9 << " Answer: " << answer << " Result: "
         << (TestSum(C8, C9, answer) ? "Right" : "False") << endl;

    answer = Complex(6.7, 11.6);
    cout << "TestSum for " << C10 << " and " << C11 << " Answer: " << answer << " Result: "
         << (TestSum(C10, C11, answer) ? "Right" : "False") << endl;


    cout << "----------------------------" << endl;

    answer = Complex(-3, -5);
    cout << "TestSub for " << C1 << " and " << C2 << " Answer: " << answer << " Result: "
         << (TestSub(C1, C2, answer) ? "Right" : "False") << endl;

    answer = Complex(6, 0);
    cout << "TestSub for " << C2 << " and " << C3 << " Answer: " << answer << " Result: "
         << (TestSub(C2, C3, answer) ? "Right" : "False") << endl;

    answer = Complex(6, 0);
    cout << "TestSub for " << C4 << " and " << C5 << " Answer: " << answer << " Result: "
         << (TestSub(C4, C5, answer) ? "Right" : "False") << endl;

    answer = Complex(3, -5);
    cout << "TestSub for " << C6 << " and " << C7 << " Answer: " << answer << " Result: "
         << (TestSub(C6, C7, answer) ? "Right" : "False") << endl;

    answer = Complex(7, 0);
    cout << "TestSub for " << C8 << " and " << C9 << " Answer: " << answer << " Result: "
         << (TestSub(C8, C9, answer) ? "Right" : "False") << endl;

    answer = Complex(-0.3, 1.0);
    cout << "TestSub for " << C10 << " and " << C11 << " Answer: " << answer << " Result: "
         << (TestSub(C10, C11, answer) ? "Right" : "False") << endl;

    answer = Complex(0, 0);
    cout << "TestSub for " << C2 << " and " << C2 << " Answer: " << answer << " Result: "
         << (TestSub(C2, C2, answer) ? "Right" : "False") << endl;

    answer = Complex(0, 0);
    cout << "TestSub for " << C5 << " and " << C5 << " Answer: " << answer << " Result: "
         << (TestSub(C5, C5, answer) ? "Right" : "False") << endl;

    return 0;
}