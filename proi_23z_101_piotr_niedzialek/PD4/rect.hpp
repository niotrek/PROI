#ifndef RECT_HPP
#define RECT_HPP
#include <string>
#include "graphic_object.hpp"


class Rect : public GraphicObject {
public:
    int x, y, width, height;

    Rect(std::string fill, std::string stroke, int x, int y, int width, int height);

    std::string toSVG() const;
};

#endif