#ifndef FIGURE_COLLECTION_HPP
#define FIGURE_COLLECTION_HPP
#include "figure.hpp"
#include "pyramid.hpp"
#include "cuboid.hpp"
#include <list>
#include <memory>

class FiguresCollection
{
private:
    std::list<std::unique_ptr<Figure>> figures;
public:
    void add_cuboid(Cuboid cuboid);
    void add_pyramid(Pyramid pyramid);
    double count_total_volume() const noexcept;
};
#endif