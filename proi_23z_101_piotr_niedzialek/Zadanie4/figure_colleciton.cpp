#include "figure_collection.hpp"
#include "figure.hpp"
#include "cuboid.hpp"
#include "pyramid.hpp"
#include "wrong_dimensions_exception.hpp"
#include <iostream>
#include <algorithm>

void FiguresCollection::add_cuboid(Cuboid cuboid)
{
    std::unique_ptr<Cuboid> added_cuboid = std::make_unique<Cuboid>(cuboid);
    figures.push_back(std::move(added_cuboid));
}

void FiguresCollection::add_pyramid(Pyramid pyramid)
{
	std::unique_ptr<Pyramid> added_pyramid = std::make_unique<Pyramid>(pyramid);
	figures.push_back(std::move(added_pyramid));
}
double FiguresCollection::count_total_volume() const noexcept //ilustracja polimorfizmu - operowanie na kolekcji wska�nik�w do klasy bazowej, wywo�anie metody wirtualnej
{
    unsigned total_volume = 0;
    for (const auto& figure_ptr : figures)
    {
        total_volume += figure_ptr->count_volume(); //calculate_price jest metod� wirtualn�, wi�c przy odwo�aniu przez wska�nik wywo�a si� wersja w�a�ciwa dla dynamicznego typu obiektu
    }
    return total_volume;
}

