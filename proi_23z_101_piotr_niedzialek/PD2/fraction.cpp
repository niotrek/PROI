#include "fraction.hpp"

Fraction::Fraction() : numerator(0), denominator(1) {}
Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

double Fraction::get_numerator() const {
	return numerator;
}
double Fraction::get_denominator() const {
	return denominator;
}
void Fraction::set_numerator(double numerator) {
	this->numerator = numerator;
}
void Fraction::set_denominator(double denominator) {
	if (denominator > 0) {
		this->denominator = denominator;
	}
	else {
		std::cout << "mianownik musi byc wiekszy od zera" << std::endl;
	}
}
Fraction& Fraction::reduce_fractions() {	
	int a = denominator;
	int b = numerator;
	while (b != 0) {
		int pom = a % b;
		a = b;
		b = pom;
	}
	if (denominator == numerator || a != denominator) {
		denominator = denominator / a;
		numerator = numerator / a;
	}
	return *this; //czemu nie void
}
Fraction Fraction::reduce_fractions_const() const {
	Fraction result = *this;
	int a = denominator;
	int b = numerator;
	while (b != 0) {
		int pom = a % b;
		a = b;
		b = pom;
	}
	if (denominator == numerator || a != denominator) {
		result.denominator = denominator / a;
		result.numerator = numerator / a;
	}
	return result;
}
Fraction& Fraction::common_denominator(const Fraction& second_fraction) {
	Fraction second;
	second = second_fraction.reduce_fractions_const();
	this->reduce_fractions();
	numerator *= second.denominator;
	denominator *= second.denominator;
	return *this;
}
Fraction Fraction::common_denominator_const(const Fraction& second_fraction) const {
	Fraction second, result;
	result = this->reduce_fractions_const();
	second = second_fraction.reduce_fractions_const();
	result.numerator *= second.denominator;
	result.denominator *= second.denominator;
	return result;
}
Fraction& Fraction::operator+= (const Fraction& second_fraction) {
	//std::cout <<"krok 1: "<< this->get_numerator() << "/" << this->get_denominator() << std::endl;
	this->common_denominator(second_fraction);
	//std::cout << "krok 2: " << this->get_numerator() << "/" << this->get_denominator() << std::endl;
	Fraction second;
	second = second_fraction.common_denominator_const(*this);
	//std::cout << "ulamek 2: " << second_fraction.get_numerator() << "/" << second_fraction.get_denominator() << std::endl;
	//std::cout << "ulamek 2 redukcja: " << second.get_numerator() << "/" << second.get_denominator() << std::endl;
	this->numerator += second.numerator;
	//std::cout << "wynik " << this->get_numerator() << "/" << this->get_denominator() << std::endl;
	return *this; //co jeœli teraz w mainie u¿yjê przypisania do nowej zmiennej
}
Fraction Fraction::operator+ (const Fraction& second_fraction) const {
	Fraction sum = *this;
	sum += second_fraction;
	return sum;
}
Fraction& Fraction::operator-= (const Fraction& second_fraction) {
	this->common_denominator(second_fraction);
	Fraction second;
	second = second_fraction.common_denominator_const(*this);
	this->numerator -= second.numerator;
	return *this;
}
Fraction Fraction::operator- (const Fraction& second_fraction) const {
	Fraction diff = *this;
	diff -= second_fraction;
	return diff;
}
Fraction& Fraction::operator*= (const Fraction& second_fraction) {
	this->numerator *= second_fraction.numerator;
	this->denominator *= second_fraction.denominator;
	this->reduce_fractions();
	return *this; //co tak na prawdê zwracam, adres?
}
Fraction Fraction::operator* (const Fraction& second_fraction) const {
	Fraction result = *this;
	result *= second_fraction;
	return result;
}
Fraction& Fraction::operator/= (const Fraction& second_fraction) {
	if (second_fraction.numerator == 0) {
		std::cout << "dzielenie przez zero" << std::endl;
	}
	else {
		this->numerator *= second_fraction.denominator;
		this->denominator *= second_fraction.numerator;
		this->reduce_fractions();
	}
	return *this;
}
Fraction Fraction::operator/ (const Fraction& second_fraction) const {
	Fraction result;
	if (second_fraction.numerator != 0) {
		result = *this;
		result /= second_fraction;
	}
	else {
		std::cout << "dzielenie przez zero" << std::endl;
	}
	return result;
	
}
bool Fraction::operator==(const Fraction& second_argument) const {
	Fraction first, second;
	first = this->common_denominator_const(second_argument);
	second = second_argument.common_denominator_const(*this);
	return first.numerator == second.numerator && first.denominator == second.denominator;
}
bool Fraction::operator!=(const Fraction& second_argument) const {
	return !(*this == second_argument);
}
bool Fraction::operator>(const Fraction& second_argument) const {
	Fraction first, second;
	first = this->common_denominator_const(second_argument);
	second = second_argument.common_denominator_const(*this);
	return first.numerator > second.numerator;
}
bool Fraction::operator>=(const Fraction& second_argument) const {
	Fraction first, second;
	first = this->common_denominator_const(second_argument);
	second = second_argument.common_denominator_const(*this);
	return first.numerator >= second.numerator;
}
bool Fraction::operator<(const Fraction& second_argument) const {
	Fraction first, second;
	first = this->common_denominator_const(second_argument);
	second = second_argument.common_denominator_const(*this);
	return first.numerator < second.numerator;
}
bool Fraction::operator<=(const Fraction& second_argument) const {
	Fraction first, second;
	first = this->common_denominator_const(second_argument);
	second = second_argument.common_denominator_const(*this);
	return first.numerator <= second.numerator;
}
std::ostream& operator<<(std::ostream& os, const Fraction& number)
{
	os << number.numerator << "/" << number.denominator;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& number) {
	int num, den;
	char slash;
	is >> num >> slash >> den;
	if (slash != '/')
	{
		std::cerr << "poprawny format num/den" << std::endl;
	}
	else
	{
	number.set_numerator(num);
	number.set_denominator(den);
	}
	return is;
}