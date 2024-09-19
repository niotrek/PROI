#include "line.hpp"
#include <iostream> 



Line::Line(std::string fill, std::string stroke, int x1, int y1, int x2, int y2)
    : GraphicObject(fill, stroke), x1(x1), y1(y1), x2(x2), y2(y2) {
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) {
        throw std::invalid_argument("Coordinates must be non-negative.");
    }
}

std::string Line::toSVG() const 
{
    return "<line x1=\"" + std::to_string(x1) + "\" y1=\"" + std::to_string(y1) +
    "\" x2=\"" + std::to_string(x2) + "\" y2=\"" + std::to_string(y2) +
    "\" stroke=\"" + stroke + "\" />";
 }
