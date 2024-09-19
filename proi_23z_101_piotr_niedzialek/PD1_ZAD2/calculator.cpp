#include "calculator.hpp"
#include <stdexcept>


Calculator::Calculator() : unit(0), second_unit(0), value(0), result(0)
{}

bool Calculator::set_unit(std::string input)
{
	auto x = conversion_to_m2.find(input);
	if (x != conversion_to_m2.end())
	{
		unit = x->second;
	}
	else
	{
		return false;
	}
}
bool Calculator::set_value(std::string input)
{
	try
	{
		value = std::stod(input);
	}
	catch (std::invalid_argument& e)
	{
		return false;
	}
}
bool Calculator::set_second_unit(std::string input)
{
	auto y = conversion_to_m2.find(input);
	if (y != conversion_to_m2.end())
	{
		second_unit = y->second;
	}
	else
	{
		return false;
	}
}
double Calculator::get_result()
{

	result = value * unit / second_unit;
	return result;
}