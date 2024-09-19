#ifndef LINE_HPP
#define LINE_HPP

#include "graphic_object.hpp"
#include <string>

class Line : public GraphicObject {
public:
    int x1, y1, x2, y2;

    Line(std::string fill, std::string stroke, int x1, int y1, int x2, int y2);

    std::string toSVG() const;
};

#endif