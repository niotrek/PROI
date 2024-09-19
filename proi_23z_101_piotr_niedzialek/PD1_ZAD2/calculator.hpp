#pragma once
#include <map>
#include <string>


const std::map<std::string, double> conversion_to_m2{
	{"mm^2", 0.000001 }, {"cm^2", 0.0001}, {"dm^2", 0.01}, {"m^2", 1},
	{"km^2", 1000000}, {"ary", 100}, {"hektary", 10000}, {"akry",4046.8564224011 }
};

class Calculator {
private:
	double unit;
	double second_unit;
	double value;
	double result;
public:
	Calculator();
	bool set_unit(std::string input);
	bool set_value(std::string input);
	bool set_second_unit(std::string input);
	double get_result();
};