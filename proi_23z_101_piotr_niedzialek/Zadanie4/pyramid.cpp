#include "pyramid.hpp"
#include <iostream>
// #include <stdexcept> //zawiera deklaracje typów wyjatków dziedzicz¹cych po std::exception (samo std::exception jest zadeklarowane w pliku <exception>)
#include "wrong_dimensions_exception.hpp"

Pyramid::Pyramid(double width, double length, double height)
{
	if (height <= 0)
	{
		throw WrongDimensionsException();
	}
	else if (width <= 0)
	{
		throw WrongDimensionsException();
	}
	else if (length <= 0)
	{
		throw WrongDimensionsException();
	}
	else
	{
		this->width = width;
		this->length = length;
		this->height = height;
	}
}
double Pyramid::count_area() const noexcept
{
	return length * width;
}

double Pyramid::count_volume() const noexcept
{
	return (length * width * height)/3;
}