#include "circle.hpp"
#include "graphic_object.hpp"

Circle::Circle(std::string fill, std::string stroke, int cx, int cy, int radius) : GraphicObject(fill, stroke), cx(cx), cy(cy), radius(radius) 
{
    if (cx < 0 || cy < 0 || radius < 0) 
    {
        throw std::invalid_argument("Coordinates and radius must be non-negative.");
    }
}
std::string Circle::toSVG() const  
{
    return "<circle cx=\"" + std::to_string(cx) + "\" cy=\"" + std::to_string(cy) +
        "\" r=\"" + std::to_string(radius) + "\" fill=\"" + fill + "\" stroke=\"" + stroke + "\" />";
}


