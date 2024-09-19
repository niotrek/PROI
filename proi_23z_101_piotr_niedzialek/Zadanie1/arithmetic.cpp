#include "arithmetic.hpp"
#include <iostream>

Arithmetic::Arithmetic() : a1(0), r(0), n(0), an(0), sn(0) {}
Arithmetic::Arithmetic(double a1, double r) : a1(a1), r(r), n(0), an(0), sn(0) {}

void Arithmetic::set_a1(double a1) {
	this->a1 = a1;
}
void Arithmetic::set_r(double r) {
	this->r = r;
}
void Arithmetic::set_n(int n) {
	if (n > 0)
	{
		this->n = n;
	}
	else
	{
		std::cout << "n niewlasciwe, powinno byc wieksze od 0" << std::endl;
	}
}
void Arithmetic::count_an() {
	if (n == 0) 
	{
		std::cout << "podaj liczbe n poczatkowych wyrazow\n";
	}
	else 
	{
		an = a1 + (n - 1) * r;
	}
}
void Arithmetic::count_sn() {
	if (n == 0)
	{
		std::cout << "podaj liczbe n poczatkowych wyrazow\n";
	}
	else
	{
		sn = (2 * a1 + (n - 1) * r) * n / 2;
	}
}
double Arithmetic::get_an() const {
	return an;
}
double Arithmetic::get_sn() const {
	return sn;
}
