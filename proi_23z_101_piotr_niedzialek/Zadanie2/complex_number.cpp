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
    ++(*this); //albo po prostu mo¿na wywo³aæ operator++(); ewentualnie jawnie wskazaæ, ¿e ma byæ wywo³any dla tego obiektu: this -> operator++();
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
    return real_part == second_argument.real_part && imaginary_part == second_argument.imaginary_part; //UWAGA: takie porównanie wartoœci zmiennoprzecinkowych mo¿e w ogólnym przypadku dawaæ nieoczekiwane wyniki ze wzglêdu na niedok³adnoœæ reprezentacji - lepiej za³o¿yæ pewien margines b³êdu
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

//W tym przyk³adzie poni¿sze funkcje nie s¹ potrzebne, ca³kowicie wystarczy³yby ich wersje wygenerowane przez kompilator
//Konstruktor kopiuj¹cy - tworzy nowy, zupe³nie oddzielny obiekt na podstawie istniej¹cego (nie modyfikuje orygina³u)
ComplexNumber::ComplexNumber(const ComplexNumber& source) : real_part(source.real_part), imaginary_part(source.imaginary_part)
{
    std::cout << "Copy constructor, this = " << this << ", source = " << &source << std::endl;
}

//Konstruktor przesuwaj¹cy - tworzy nowy obiekt na bazie Ÿród³owego, zabieraj¹c jego zasoby i "uniewa¿niaj¹c" orygina³
ComplexNumber::ComplexNumber(ComplexNumber&& source) : real_part(source.real_part), imaginary_part(source.imaginary_part)
{
    std::cout << "Move constructor, this = " << this << ", source = " << &source << std::endl;
    //"uniewa¿nienie" Ÿród³owego obiektu
    source.real_part = 0;
    source.imaginary_part = 0;
}

//Kopiuj¹cy operator przypisania - "kopiuje" do ju¿ istniej¹cego obiektu, orygina³ jest niezale¿ny od wyniku przypisania
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& source)
{
    std::cout << "Copy assignment operator, this = " << this << ", source = " << &source << std::endl;
    if (this != &source) //nie powinien przypisywaæ sam do siebie!
    {
        real_part = source.real_part;
        imaginary_part = source.imaginary_part;
    }
    return *this;
}

//Przesuwaj¹cy operator przypisania - "przenosi" do ju¿ istniej¹cego obiektu, zabieraj¹c zasoby oryginalnego obiektu i "uniewa¿niaj¹c" go
ComplexNumber& ComplexNumber::operator=(ComplexNumber&& source)
{
    std::cout << "Move assignment operator, this = " << this << ", source = " << &source << std::endl;
    if (this != &source) //nie powinien przypisywaæ sam do siebie!
    {
        real_part = source.real_part;
        imaginary_part = source.imaginary_part;
        //"uniewa¿nienie" Ÿród³owego obiektu
        source.real_part = 0;
        source.imaginary_part = 0;
    }
    return *this;
}

//Destruktor - zwalnia zasoby zajête przez obiekt
ComplexNumber::~ComplexNumber()
{
    std::cout << "Destructor, this = " << this << std::endl;
    //zwolnienie zasobów
    //klasa ComplexNumber ¿adnych zasobów nie zajmowa³a, wiêc nic nie musi tu zwalniaæ
}
