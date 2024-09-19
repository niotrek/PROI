#include <iostream>
#include "date.hpp"


int main()
{
	Date wrong;
	wrong.set_day(29);
	wrong.set_month(MONTH::February);
	wrong.set_year(5);
	std::cout << "The date is " << wrong.get_day() <<"-"
		<< static_cast<int>(wrong.get_month()) <<"-" << wrong.get_year() << std::endl;


	Date correct;
	correct.set_day(31);
	correct.set_month(MONTH::May);
	correct.set_year(4);

	std::cout << "The date is " << correct.get_day() << "-"
		<< static_cast<int>(correct.get_month()) << "-" << correct.get_year() << std::endl;


	
	return 0;
}
