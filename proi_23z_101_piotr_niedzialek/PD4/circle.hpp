#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <string>
#include "graphic_object.hpp"
#include <iostream>
  

class Circle : public GraphicObject {
public:
    int cx, cy, radius;

    Circle(std::string fill, std::string stroke, int cx, int cy, int radius);
       
    std::string toSVG() const; 
};



#endif
