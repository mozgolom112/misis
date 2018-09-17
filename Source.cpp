#include <iostream>
#include <sstream>

using namespace std;

struct Complex {
	Complex() = default; // �� ������� ������	
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);
	bool operator==(const Complex& rhs) const { return (re == rhs.re) && (im == rhs.im); } //��, ��� � ������� (Complex& rhs), ��� rhs - ��� ���������� ���� Complex. ����������� ���������� ����� ���.����������. �.�. �������� ������, �� ���������� �� ������. ���� ���
	bool operator!=(const Complex& rhs) const { return !operator==(rhs); }//const { return (re != rhs.re) || (im != rhs.im); } �� ��� ����� ���� � �� ��� ����� ��� ������. �� ��� ������!!! 
	Complex& operator +=(const Complex& rhs);
	Complex& operator +=(const double rhs) { return operator+=(Complex(rhs)); }
	Complex& operator -=(const Complex& rhs);
	Complex& operator -=(const double rhs) { return operator-=(Complex(rhs)); }
	Complex& operator *=(const Complex& rhs);
	Complex& operator *=(const double rhs) { return operator*=(Complex(rhs)); }
	









	std::ostream& writeTo(std::ostream& ostrm) const;  //std::ostream - ���, ostrm
	std::istream& readFrom(std::istream& istrm) ;

	double re{ 0.0 }; 
	double im{ 0.0 }; //syn. double example = 0.0; �� ������� ���������
	

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};

Complex operator+ (const Complex& lhs, const Complex& rhs);
Complex operator- (const Complex& lhs, const Complex& rhs);

inline std::ostream& operator <<(std::ostream& ostrm, const Complex& rhs) //������ �������, �������� ��������� � �����������  �� ��������
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator >>(std::istream& istrm, Complex& rhs) 
{
	return rhs.readFrom(istrm);
}


bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good()) {
		cout << "Read success: " << str << " -> " << z << endl;
	}
	else {
		cout << "Read error : " << str << " -> " << z << endl;
	}
	return istrm.good();
}
//Tests

bool TestMulti() { //������� ���� ������

	Complex z(-5.0, 3.0);
	Complex y(4.0, 7.0);
	Complex answer(-41, -23);
	z *= y;
	return (z == answer);
}

bool TestEq() {
	Complex n1(56.4, 23.6);
	Complex n2(56.4, 23.6);
	return (n1 == n2);
}

bool Testdiffer() {
	Complex n1(52.4, 23.6);
	Complex n2(56.4, 23.6);
	return !(n1 == n2);
}

bool TestSum() {
	Complex n1(4.6, 32.3);
	Complex n2(2.4, 3.7);
	Complex answer(7.0, 36.0);
		Complex result = n1 + n2;
		return (result == answer);
}

bool TestSub() {
	Complex n1(4.0, 32.0);
	Complex n2(2.0, 3.5);
	Complex answer(2.0, 28.5);
	n1 -= n2;
	return (n1 == answer);
}

int main()
{
	cout << "TestMulti " << (TestMulti() ? "Right" : "False") << endl;
	cout << "TestEq " << (TestEq() ? "Right" : "False") << endl;
	cout << "Testdiffer " << (Testdiffer() ? "Right" : "False") << endl;
	cout << "TestSum " << (TestSum() ? "Right" : "False") << endl;
	cout << "TestSub " << (TestSub() ? "Right" : "False") << endl; //�������� ������ ��� ��������� 0.3 - 0.4

	
	return 0;
	
}





Complex::Complex(const double real) 
	: Complex(real, 0.0) 
{

}

Complex::Complex(const double real, const double imaginary) 
	: re(real)
	, im(imaginary) //���� ���������� ��������? ��� ���� ��� �����
{

}


//���������
Complex& Complex::operator+=(const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this; //��� ��� �����? ��� ��� ����� ������� ��������?
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex& Complex::operator-=(const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}
Complex operator-(const Complex& lhs, const Complex& rhs)
{
	Complex dif(lhs);
	dif -= rhs;
	return dif;
	//return Complex(lhs.re-rhs.re, lhs.im - rhs.im); // ���� ��� ����� ��� ���������� ����� -=. �� ������, ����� ����� ����� �������� ������������ ��������� -=? ��� � ��� �� ����������� �����
}

Complex& Complex::operator*=(const Complex& rhs)
{
	double TempRe = re; //���� �������� ����� ������!!!
	re = (re * rhs.re) - (im * rhs.im);
	im = (TempRe * rhs.im) + (im * rhs.re);
	return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
	Complex mult(lhs);
	mult *= rhs;
	return mult;
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << re << separator << im << rightBrace; //������
	return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm) // const - ������ ������ ��� readForm ������ const?
{
	char leftBrace(0); //����������� �� ������
	double real(0.0);
	char comma(0);
	double imaganary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
	if (istrm.good()) //istrm.good() ���� ���� ������ ��� ������. ���������� bool
	{ 
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) && (Complex::rightBrace == rightBrace)) //�������� �������
		{
			re = real;
			im = imaganary;

		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
		

	}
	return istrm;
}
