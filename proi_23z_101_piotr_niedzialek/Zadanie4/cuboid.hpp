#ifndef CUBOID_HPP
#define CUBOID_HPP

#include "figure.hpp"


class Cuboid : public Figure
{
private:
	double width;
	double length;
	double height;
public:
	Cuboid(double width,double length,double height);
	double count_area() const noexcept override; 
	double count_volume() const noexcept override;
};

#endif
