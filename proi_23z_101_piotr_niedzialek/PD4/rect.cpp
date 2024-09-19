#include "rect.hpp"
#include <iostream>
#include <string>


Rect::Rect(std::string fill, std::string stroke, int x, int y, int width, int height)
    : GraphicObject(fill, stroke), x(x), y(y), width(width), height(height) {
    if (x < 0 || y < 0 || width <= 0 || height <= 0) 
    {
        throw std::invalid_argument("Coordinates must be non-negative and dimensions must be positive.");
    }
}
std::string Rect::toSVG() const 
{
    return "<rect x=\"" + std::to_string(x) + "\" y=\"" + std::to_string(y) +
        "\" width=\"" + std::to_string(width) + "\" height=\"" + std::to_string(height) +
        "\" fill=\"" + fill + "\" stroke=\"" + stroke + "\" />";
}




