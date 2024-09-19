#pragma once
#include <iostream>

class Fraction {
private:
	int numerator;
	int denominator;
public:
	Fraction();
	Fraction(int numerator, int denumerator);
	double get_numerator() const;
	double get_denominator() const;
	void set_numerator(double numerator);
	void set_denominator(double denominator);
	Fraction& reduce_fractions();
	Fraction reduce_fractions_const() const;
	Fraction& common_denominator(const Fraction& second_fraction);
	Fraction common_denominator_const(const Fraction& second_fraction) const;
	Fraction& operator+= (const Fraction& second_fraction);
	Fraction operator+ (const Fraction& second_fraction) const;
	Fraction& operator-= (const Fraction& second_fraction);
	Fraction operator- (const Fraction& second_fraction) const;
	Fraction& operator*= (const Fraction& second_fraction);
	Fraction operator* (const Fraction& second_fraction) const;
	Fraction& operator/= (const Fraction& second_fraction);
	Fraction operator/ (const Fraction& second_fraction) const;
	bool operator==(const Fraction& second_argument) const;
	bool operator!=(const Fraction& second_argument) const;
	bool operator>(const Fraction& second_argument) const;
	bool operator>=(const Fraction& second_argument) const;
	bool operator<(const Fraction& second_argument) const;
	bool operator<=(const Fraction& second_argument) const;
	
	friend std::ostream& operator<<(std::ostream& os, const Fraction& number);
	friend std::istream& operator>>(std::istream& is, Fraction& number); 
};

std::ostream& operator<<(std::ostream& os, const Fraction& number);
std::istream& operator>>(std::istream& is, Fraction& number);