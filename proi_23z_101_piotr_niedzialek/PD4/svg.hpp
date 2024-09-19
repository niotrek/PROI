#ifndef SVG_HPP
#define SVG_HPP

#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include "graphic_object.hpp"


class SVG 
{
public:
    std::vector<std::unique_ptr<GraphicObject>> objects;
    void add(std::unique_ptr<GraphicObject> obj);
    void save(const std::string& filename);
    void remove(int index);
};

#endif
