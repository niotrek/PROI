#ifndef PYRAMID_HPP
#define PYRAMID_HPP

#include "figure.hpp"


class Pyramid : public Figure
{
private:
	double width;
	double length;
	double height;
public:
	Pyramid(double width, double length, double height);
	double count_area() const noexcept override;
	double count_volume() const noexcept override;
};

#endif