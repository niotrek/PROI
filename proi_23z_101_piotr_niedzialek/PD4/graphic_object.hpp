#ifndef GRAPHIC_OBJECT_HPP
#define GRAPHIC_OBJECT_HPP
#include <string>


class GraphicObject {
public:
    std::string fill;
    std::string stroke;
    GraphicObject(std::string fill, std::string stroke);
    virtual std::string toSVG() const = 0;
};

#endif