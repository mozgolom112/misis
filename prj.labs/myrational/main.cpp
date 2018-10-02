#include "Rational.h"

inline std::ostream& operator <<(std::ostream& ostrm, const Rational& rhs) {
	return rhs.writeTo(ostrm);
}
inline std::istream& operator >>(std::istream& istrm, Rational& rhs) {
	return rhs.readFrom(istrm);
}

bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Rational z;
	istrm >> z;
	if (istrm.good()) {
		cout << "Read success: " << str << " -> " << z << endl;
	}
	else {
		cout << "Read error  : " << str << " -> " << z << endl;
	}
	return istrm.good();
}



int main()
{
	std::cout << "Hello" << std::endl;

	Rational x(5, 7); Rational y(8, 9);
	Rational sum = x;
	sum += y;
	Rational dif = x;
	dif -= y;
	Rational multi = x;
	multi *= y;
	Rational div = x;
	div /= y;

	testParse("{67/3}");
	testParse("{54     /3}");
	testParse("{54     /3");
	testParse("{67/            3}");

	
	return 0;
}
