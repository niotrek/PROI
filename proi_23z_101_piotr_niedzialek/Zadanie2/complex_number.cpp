#include "complex_number.hpp"

ComplexNumber::ComplexNumber() : real_part(0.0), imaginary_part(0.0)
{
    std::cout << "Default constructor, this = " << this << std::endl;
}

ComplexNumber::ComplexNumber(double real_part, double imaginary_part) : real_part(real_part), imaginary_part(imaginary_part)
{
    std::cout << "Constructor with arguments, this = " << this << std::endl;
}

double ComplexNumber::get_real_part() const
{
    return real_part;
}

double ComplexNumber::get_imaginary_part() const
{
    return imaginary_part;
}

void ComplexNumber::set_real_part(double real_part)
{
    this->real_part = real_part;
}

void ComplexNumber::set_imaginary_part(double imaginary_part)
{
    this->imaginary_part = imaginary_part;
}

ComplexNumber& ComplexNumber::operator++()
{
    real_part += 1;
    return *this;
}

ComplexNumber ComplexNumber::operator++(int)
{
    ComplexNumber old_value = *this;
    ++(*this); //albo po prostu mo�na wywo�a� operator++(); ewentualnie jawnie wskaza�, �e ma by� wywo�any dla tego obiektu: this -> operator++();
    return old_value;
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& second_argument)
{
    real_part += second_argument.real_part;
    imaginary_part += second_argument.imaginary_part;
    return *this;
}

ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& second_argument) {
    ComplexNumber temp = *this;
    real_part = real_part * second_argument.real_part - imaginary_part * second_argument.imaginary_part;
    imaginary_part = temp.real_part * second_argument.imaginary_part + temp.imaginary_part * second_argument.real_part;
    return *this;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& second_argument) const {
    ComplexNumber result = *this;
    result *= second_argument;
    return result;
}

ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& second_argument) {
    ComplexNumber temp = *this;
    if (second_argument.real_part == 0 && second_argument.imaginary_part == 0) {
        std::cout << "dzielenie przez zero" << std::endl;
    }
    else {
        real_part = (real_part * second_argument.real_part + imaginary_part * second_argument.imaginary_part) / (
            (second_argument.real_part * second_argument.real_part) + (second_argument.imaginary_part * second_argument.imaginary_part));
        imaginary_part = (temp.imaginary_part * second_argument.real_part - temp.real_part * second_argument.imaginary_part) / (
            (second_argument.real_part * second_argument.real_part) + (second_argument.imaginary_part * second_argument.imaginary_part));
    }
   
    return *this;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& second_argument) const {
    ComplexNumber result = *this;
    result /= second_argument;
    return result;
}
ComplexNumber ComplexNumber::operator+(const ComplexNumber& second_argument) const
{
    ComplexNumber sum = *this;
    sum += second_argument;
    return sum;
}

bool ComplexNumber::operator==(const ComplexNumber& second_argument) const
{
    return real_part == second_argument.real_part && imaginary_part == second_argument.imaginary_part; //UWAGA: takie por�wnanie warto�ci zmiennoprzecinkowych mo�e w og�lnym przypadku dawa� nieoczekiwane wyniki ze wzgl�du na niedok�adno�� reprezentacji - lepiej za�o�y� pewien margines b��du
}

bool ComplexNumber::operator!=(const ComplexNumber& second_argument) const
{
    return !(*this == second_argument);
}

std::ostream& operator<<(std::ostream& os, const ComplexNumber& number)
{
    os << "(" << number.real_part << " + " << number.imaginary_part << "i)";
    return os;
}

//W tym przyk�adzie poni�sze funkcje nie s� potrzebne, ca�kowicie wystarczy�yby ich wersje wygenerowane przez kompilator
//Konstruktor kopiuj�cy - tworzy nowy, zupe�nie oddzielny obiekt na podstawie istniej�cego (nie modyfikuje orygina�u)
ComplexNumber::ComplexNumber(const ComplexNumber& source) : real_part(source.real_part), imaginary_part(source.imaginary_part)
{
    std::cout << "Copy constructor, this = " << this << ", source = " << &source << std::endl;
}

//Konstruktor przesuwaj�cy - tworzy nowy obiekt na bazie �r�d�owego, zabieraj�c jego zasoby i "uniewa�niaj�c" orygina�
ComplexNumber::ComplexNumber(ComplexNumber&& source) : real_part(source.real_part), imaginary_part(source.imaginary_part)
{
    std::cout << "Move constructor, this = " << this << ", source = " << &source << std::endl;
    //"uniewa�nienie" �r�d�owego obiektu
    source.real_part = 0;
    source.imaginary_part = 0;
}

//Kopiuj�cy operator przypisania - "kopiuje" do ju� istniej�cego obiektu, orygina� jest niezale�ny od wyniku przypisania
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& source)
{
    std::cout << "Copy assignment operator, this = " << this << ", source = " << &source << std::endl;
    if (this != &source) //nie powinien przypisywa� sam do siebie!
    {
        real_part = source.real_part;
        imaginary_part = source.imaginary_part;
    }
    return *this;
}

//Przesuwaj�cy operator przypisania - "przenosi" do ju� istniej�cego obiektu, zabieraj�c zasoby oryginalnego obiektu i "uniewa�niaj�c" go
ComplexNumber& ComplexNumber::operator=(ComplexNumber&& source)
{
    std::cout << "Move assignment operator, this = " << this << ", source = " << &source << std::endl;
    if (this != &source) //nie powinien przypisywa� sam do siebie!
    {
        real_part = source.real_part;
        imaginary_part = source.imaginary_part;
        //"uniewa�nienie" �r�d�owego obiektu
        source.real_part = 0;
        source.imaginary_part = 0;
    }
    return *this;
}

//Destruktor - zwalnia zasoby zaj�te przez obiekt
ComplexNumber::~ComplexNumber()
{
    std::cout << "Destructor, this = " << this << std::endl;
    //zwolnienie zasob�w
    //klasa ComplexNumber �adnych zasob�w nie zajmowa�a, wi�c nic nie musi tu zwalnia�
}
