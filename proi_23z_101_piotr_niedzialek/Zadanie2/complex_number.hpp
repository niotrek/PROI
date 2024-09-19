#ifndef COMPLEX_NUMBER_HPP
#define COMPLEX_NUMBER_HPP
#include <iostream>

class ComplexNumber
{
private:
    double real_part;
    double imaginary_part;
public:
    ComplexNumber();
    ComplexNumber(double real_part, double imaginary_part);
    double get_real_part() const;
    double get_imaginary_part() const;
    void set_real_part(double real_part);
    void set_imaginary_part(double imaginary_part);

    //inkrementacja - za³ó¿my, ¿e zwiêksza wartoœæ liczby zespolonej o 1 (czyli o (1 + 0i))
    //wersja prefiksowa -zwraca wartoœæ po inkrementacji
    ComplexNumber& operator++();
    //wersja postfiksowa - te¿ inkrementuje, ale zwraca wartoœæ przed inkrementacj¹
    ComplexNumber operator++(int);

    //dodawanie dwóch liczb zespolonych
    //wersja z przypisaniem
    ComplexNumber& operator+=(const ComplexNumber& second_argument);
    //wersja bez przypisywania (orygina³ pozostaje bez zmian)
    ComplexNumber operator+(const ComplexNumber& second_argument) const;
    ComplexNumber& operator*=(const ComplexNumber& second_argument);
    ComplexNumber operator*(const ComplexNumber& second_argument) const;
    ComplexNumber& operator/=(const ComplexNumber& second_argument);
    ComplexNumber operator/(const ComplexNumber& second_argument) const;
    //sprawdzanie równoœci dwóch liczb zespolonych

    bool operator==(const ComplexNumber& second_argument) const;
    bool operator!=(const ComplexNumber& second_argument) const;


    //Konstruktory kopiuj¹cy i przesuwaj¹cy, operatory przypisania, destruktor
    //UWAGA: tu pokazane tylko dla przyk³adu, nie musimy ich tworzyæ, jeœli nasza klasa nie zajmuje ¿adnych zasobów
    //(wystarcz¹ ich wersje wygenerowane przez kompilator)
    ComplexNumber(const ComplexNumber& source); //konstruktor kopiuj¹cy
    ComplexNumber(ComplexNumber&& source); //konstruktor przesuwaj¹cy
    ComplexNumber& operator=(const ComplexNumber& source); //kopiuj¹cy operator przypisania
    ComplexNumber& operator=(ComplexNumber&& source); //przesuwaj¹cy operator przypisania
    ~ComplexNumber(); //destruktor
    //Mo¿na tak¿e wymusiæ wygenerowanie przez kompilator powy¿szych funkcji oraz konstruktora domyœlnego
    //np. jeœli mimo posiadania konstruktora argumentowego chcemy mieæ konstruktor domyœlny wygenerowany przez kompilator:
    // ComplexNumber() = default;
    //Lub mo¿na jawnie zabroniæ kompilatorowi generowania któregoœ z powy¿szych
    //np. jeœli nie pozwalamy na kopiowanie obiektów naszej klasy, trzeba zabroniæ generowania konstruktora kopiuj¹cego i kopiuj¹cego operatora przypisania
    // ComplexNumber(const ComplexNumber&) = delete;
    // ComplexNumber& operator=(const ComplexNumber&) = delete;


    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& number); // ta funkcja nie jest sk³adow¹ klasy ComplexNumber, jest z ni¹ tylko zaprzyjaŸniona (ma dostêp do jej niepublicznych sk³adowych)

};

std::ostream& operator<<(std::ostream& os, const ComplexNumber& number);

#endif

