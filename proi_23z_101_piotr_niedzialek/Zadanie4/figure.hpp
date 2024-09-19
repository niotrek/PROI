#ifndef FIGURE_HPP
#define FIGURE_HPP



class Figure
{
public:
    virtual double count_area() const noexcept = 0; //metoda czysto wirtualna (nie ma cia³a)
    virtual double count_volume() const noexcept = 0;
    virtual ~Figure() = 0; //destruktor czysto wirtualny (powinien zawsze wyst¹piæ w klasie abstrakcyjnej)
};


#endif