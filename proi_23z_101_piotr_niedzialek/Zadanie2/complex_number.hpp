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

    //inkrementacja - za��my, �e zwi�ksza warto�� liczby zespolonej o 1 (czyli o (1 + 0i))
    //wersja prefiksowa -zwraca warto�� po inkrementacji
    ComplexNumber& operator++();
    //wersja postfiksowa - te� inkrementuje, ale zwraca warto�� przed inkrementacj�
    ComplexNumber operator++(int);

    //dodawanie dw�ch liczb zespolonych
    //wersja z przypisaniem
    ComplexNumber& operator+=(const ComplexNumber& second_argument);
    //wersja bez przypisywania (orygina� pozostaje bez zmian)
    ComplexNumber operator+(const ComplexNumber& second_argument) const;
    ComplexNumber& operator*=(const ComplexNumber& second_argument);
    ComplexNumber operator*(const ComplexNumber& second_argument) const;
    ComplexNumber& operator/=(const ComplexNumber& second_argument);
    ComplexNumber operator/(const ComplexNumber& second_argument) const;
    //sprawdzanie r�wno�ci dw�ch liczb zespolonych

    bool operator==(const ComplexNumber& second_argument) const;
    bool operator!=(const ComplexNumber& second_argument) const;


    //Konstruktory kopiuj�cy i przesuwaj�cy, operatory przypisania, destruktor
    //UWAGA: tu pokazane tylko dla przyk�adu, nie musimy ich tworzy�, je�li nasza klasa nie zajmuje �adnych zasob�w
    //(wystarcz� ich wersje wygenerowane przez kompilator)
    ComplexNumber(const ComplexNumber& source); //konstruktor kopiuj�cy
    ComplexNumber(ComplexNumber&& source); //konstruktor przesuwaj�cy
    ComplexNumber& operator=(const ComplexNumber& source); //kopiuj�cy operator przypisania
    ComplexNumber& operator=(ComplexNumber&& source); //przesuwaj�cy operator przypisania
    ~ComplexNumber(); //destruktor
    //Mo�na tak�e wymusi� wygenerowanie przez kompilator powy�szych funkcji oraz konstruktora domy�lnego
    //np. je�li mimo posiadania konstruktora argumentowego chcemy mie� konstruktor domy�lny wygenerowany przez kompilator:
    // ComplexNumber() = default;
    //Lub mo�na jawnie zabroni� kompilatorowi generowania kt�rego� z powy�szych
    //np. je�li nie pozwalamy na kopiowanie obiekt�w naszej klasy, trzeba zabroni� generowania konstruktora kopiuj�cego i kopiuj�cego operatora przypisania
    // ComplexNumber(const ComplexNumber&) = delete;
    // ComplexNumber& operator=(const ComplexNumber&) = delete;


    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& number); // ta funkcja nie jest sk�adow� klasy ComplexNumber, jest z ni� tylko zaprzyja�niona (ma dost�p do jej niepublicznych sk�adowych)

};

std::ostream& operator<<(std::ostream& os, const ComplexNumber& number);

#endif

