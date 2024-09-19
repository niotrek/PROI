#include "date.hpp"
#include <iostream>


Date::Date() : year(0), month(MONTH::Invalid), day(0)
{}
int Date::get_year()
{
	return year;
}
MONTH Date::get_month()
{
	return month;
}
int Date::get_day()
{
	return day;
}
void Date::set_year(int Year)
{
	if (day != 0 && month != MONTH::Invalid && Year != 0)
	{
		if (Date::checkValid(day, month, Year))
		{
			year = Year;
		}
		else
		{
			std::cout << "Invalid date" << std::endl;
			day = 0;
			month = MONTH::Invalid;
		}
	}
	else
	{
		if (Year > 0)
		{
			year = Year;
		}
		else
		{
			std::cout << "Invalid year" << std::endl;
			day = 0;
			month = MONTH::Invalid;
		}
	}
}
void Date::set_month(MONTH Month)
{
	if (day != 0 && Month != MONTH::Invalid && year != 0)
		if (Date::checkValid(day, Month, year))
		{
			month = Month;
		}
		else
		{
			std::cout << "Invalid date" << std::endl;
			day = 0;
			year = 0;
		}
	else
	{
		month = Month;
	}

}
void Date::set_day(int Day)
{
	if (Day != 0 && month != MONTH::Invalid && year != 0)
		if (Date::checkValid(Day, month, year))
		{
			day = Day;
		}
		else
		{
			std::cout << "Invalid date" << std::endl;
			month = MONTH::Invalid;
			year = 0;
		}
	else
	{
		if (Day < 32 && Day > 0)
		{
			day = Day;
		}
		else
		{
			std::cout << "Invalid day" << std::endl;
		}
	}
}
bool Date::checkValid(int Day, MONTH Month, int Year)
{
	if (Month == MONTH::April || Month == MONTH::June ||
		Month == MONTH::September || Month == MONTH::November)
	{
		if (Day > 30 || Day < 1)
		{
			return false;
		}
	}
	else if (Month == MONTH::January || Month == MONTH::March
		|| Month == MONTH::May || Month == MONTH::July || Month == MONTH::August ||
		Month == MONTH::Oktober || Month == MONTH::December)
	{
		if (Day > 31 || Day < 1)
		{
			return false;
		}
	}
	else if (Month == MONTH::February)
	{
		if (Year % 4 == 0)
		{
			if (Day > 29 || Day < 1)
			{
				return false;
			}
		}
		else
		{
			if (Day > 28 || Day < 1)
			{
				return false;
			}
		}

	}
	return true;
}



