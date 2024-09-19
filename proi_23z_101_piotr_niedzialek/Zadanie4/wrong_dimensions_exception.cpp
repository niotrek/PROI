#include "wrong_dimensions_exception.hpp"

WrongDimensionsException::WrongDimensionsException() :
	std::invalid_argument("Dimensions are lower or equal to zero ") {}