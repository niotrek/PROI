#pragma once


enum struct MONTH
{
	Invalid, January, February, March, April, May, June, July, August, September, Oktober, November, December
};

class Date {
private:
	int year;
	MONTH month;
	int day;
public:
	Date();
	void set_year(int Year);
	void set_month(MONTH Month);
	void set_day(int Day);
	int get_year();
	MONTH get_month();
	int get_day();
	bool checkValid(int Day, MONTH Month, int Year);
};



