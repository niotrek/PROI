#pragma once

class Arithmetic {
	double a1;
	double r;
	int n;
	double an;
	double sn;
public:
	Arithmetic();
	Arithmetic(double a1, double r);
	void set_a1(double a1);
	void set_r(double r);
	void set_n(int n);
	void count_an();
	void count_sn();
	double get_an() const;
	double get_sn() const;
};