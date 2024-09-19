#include "svg.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <memory>



void SVG::add(std::unique_ptr<GraphicObject> obj) 
{
    objects.push_back(std::move(obj));
}
void SVG::remove(int index) {
    if (index < 0 || index >= objects.size()) 
    {
        throw std::out_of_range("Index out of range");
    }
    objects.erase(objects.begin() + index);
}

void SVG::save(const std::string& filename) 
{
    std::ofstream file(filename);
    if (!file.is_open()) 
    {
        throw std::runtime_error("Could not open file " + filename);
    }
    file << "<svg xmlns=\"http://www.w3.org/2000/svg\">\n";
    for (const auto& obj : objects)
    {
        file << obj->toSVG() << "\n";
    }
    file << "</svg>";
    file.close();
}