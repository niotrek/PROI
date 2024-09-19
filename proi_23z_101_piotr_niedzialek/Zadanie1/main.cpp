#include <iostream>
#include "arithmetic.hpp"


int main()
{
	Arithmetic sequence1;

	double a1 = 0.0, r = 0.0;
	int n = 0;
	std::cout << "Podaj wartosc a1, r, n\n";
	std::cin >> a1;
	std::cin >> r;
	std::cin >> n;

	sequence1.set_a1(a1);
	sequence1.set_r(r);
	sequence1.set_n(n);
	sequence1.count_an();
	sequence1.count_sn();

	std::cout << "an wynosi: " << sequence1.get_an() << std::endl;
	std::cout << "sn wynosi: " << sequence1.get_sn() << std::endl;

	return 0;
}

