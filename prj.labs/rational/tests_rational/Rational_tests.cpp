#include "../rational.h"

using namespace std;

inline std::ostream &operator<<(std::ostream &ostrm, const Rational &rhs) {
    return rhs.writeTo(ostrm);
}

inline std::istream &operator>>(std::istream &istrm, Rational &rhs) {
    return rhs.readFrom(istrm);
}

bool testParse(const std::string &str) {
    using namespace std;
    istringstream istrm(str);
    Rational z;
    istrm >> z;
    if (istrm.good()) {
        cout << "Read success: " << str << " -> " << z << endl;
    } else {
        cout << "Read error  : " << str << " -> " << z << endl;
    }
    return istrm.good();
}


int main() {
    std::cout << "Hello" << std::endl;


    Rational c1(-5, -3);
    Rational c0(10, 6);
    Rational c2(-6, 3);
    Rational c3(6, -5);
    Rational c4(-6, 9);
    Rational c5(0, -19);
    Rational c6(-12, -12);
    Rational c7(4, 3);
    Rational result(1);

    cout << c1 << "sum" << c2 << "=" << c1 + c2 << endl;
    cout << c2 << "sum" << c2 << "=" << c2 + c2 << endl;
    cout << c3 << "sum" << c2 << "=" << c3 + c2 << endl;
    cout << c2 << "sum" << c3 << "=" << c2 + c3 << endl;
    cout << c5 << "sum" << c6 << "=" << c5 + c6 << endl;


    cout << "-------------------------" << endl;

    cout << c1 << "div" << c2 << "=" << c1 / c2 << endl;
    cout << c2 << "div" << c2 << "=" << c2 / c2 << endl;
    cout << c3 << "div" << c2 << "=" << c3 / c2 << endl;
    cout << c2 << "div" << c3 << "=" << c2 / c3 << endl;
    cout << c5 << "div" << c6 << "=" << c5 / c6 << endl;

    cout << "-------------------------" << endl;
    cout << c1 << "dif" << c2 << "=" << c1 - c2 << endl;
    cout << c2 << "dif" << c2 << "=" << c2 - c2 << endl;
    cout << c3 << "dif" << c2 << "=" << c3 - c2 << endl;
    cout << c2 << "dif" << c3 << "=" << c2 - c3 << endl;
    cout << c5 << "dif" << c6 << "=" << c5 - c6 << endl;
    cout << c7 << "dif" << c3 << "=" << c7 - c3 << endl;

    cout << "-------------------------" << endl;

    cout << c1 << "mult" << c2 << "=" << c1 * c2 << endl;
    cout << c2 << "mult" << c2 << "=" << c2 * c2 << endl;
    cout << c3 << "mult" << c2 << "=" << c3 * c2 << endl;
    cout << c2 << "mult" << c3 << "=" << c2 * c3 << endl;
    cout << c5 << "mult" << c6 << "=" << c5 * c6 << endl;
    cout << c7 << "mult" << c3 << "=" << c7 * c3 << endl;

    cout << "-------------------------" << endl;
    cout << c7 << "equal" << c0 << "=" << ((c7 == c0) ? "Equal" : "Notequal") << endl;
    cout << c1 << "equal" << c2 << "=" << ((c1 == c2) ? "Equal" : "Notequal") << endl;
    cout << c3 << "equal" << c4 << "=" << ((c3 == c4) ? "Equal" : "Notequal") << endl;
    cout << c5 << "equal" << c6 << "=" << ((c5 == c6) ? "Equal" : "Notequal") << endl;
    cout << c6 << "equal" << c5 << "=" << ((c6 == c5) ? "Equal" : "Notequal") << endl;
    cout << c5 << "equal" << c5 << "=" << ((c5 == c5) ? "Equal" : "Notequal") << endl;
    cout << c0 << "equal" << c1 << "=" << ((c0 == c1) ? "Equal" : "Notequal") << endl;
    cout << c1 << "equal" << c0 << "=" << ((c1 == c0) ? "Equal" : "Notequal") << endl;

    cout << "-------------------------" << endl;
    cout << c7 << "notequal" << c0 << "=" << ((c7 != c0) ? "True" : "False") << endl;
    cout << c1 << "notequal" << c2 << "=" << ((c1 != c2) ? "True" : "False") << endl;
    cout << c3 << "notequal" << c4 << "=" << ((c3 != c4) ? "True" : "False") << endl;
    cout << c5 << "notequal" << c6 << "=" << ((c5 != c6) ? "True" : "False") << endl;
    cout << c6 << "notequal" << c5 << "=" << ((c6 != c5) ? "True" : "False") << endl;
    cout << c5 << "notequal" << c5 << "=" << ((c5 != c5) ? "True" : "False") << endl;
    cout << c0 << "notequal" << c1 << "=" << ((c0 != c1) ? "True" : "False") << endl;
    cout << c1 << "notequal" << c0 << "=" << ((c1 != c0) ? "True" : "False") << endl;






    /*//budet vidovati iscluchenie
    Rational(4,0);
    c5/=c5;
    */



    testParse("{67/3}");
    testParse("{54     /3}");
    testParse("{54     /3");
    testParse("{67/            3}");


    return 0;
}