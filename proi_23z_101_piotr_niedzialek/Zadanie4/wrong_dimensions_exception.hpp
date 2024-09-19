#ifndef WRONG_DIMENSIONS_EXCEPTION_HPP
#define WRONG_DIMENSIONS_EXCEPTION_HPP
#include <stdexcept>

class WrongDimensionsException : public std::invalid_argument
{
public:
    WrongDimensionsException();

};

#endif