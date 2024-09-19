#include "address.hpp"


Address::Address(std::string street_name, std::string street_number, std::string flat_number, std::string post_code, std::string city, std::string country):
street_name(street_name), street_number(street_number), flat_number(flat_number), post_code(post_code), city(city), country(country){}
        
//gettery
std::string Address::get_street_name() const
{
    return street_name;
}

std::string Address::get_street_number() const
{
    return street_number;
}

std::string Address::get_flat_number() const
{
    return flat_number;
}

std::string Address::get_post_code() const
{
    return post_code;
}

std::string Address::get_city() const
{
    return city;
}

std::string Address::get_country() const
{
    return country;
}

//settery
void Address::set_street_name(std::string street_name)
{
    this -> street_name = street_name;
}

void Address::set_street_number(std::string street_number)
{
    this -> street_number = street_number;
}

void Address::set_flat_number(std::string flat_number)
{
    this -> flat_number = flat_number;
}

void Address::set_post_code(std::string post_code)
{
    this -> post_code = post_code;
}

void Address::set_city(std::string city)
{
    this -> city = city;
}

void Address::set_country(std::string country)
{
    this -> country = country;
}

//operatory
bool Address::operator==(const Address& other) const
{
    return street_name == other.street_name && street_number == other.street_number && flat_number == other.flat_number &&
            post_code == other.post_code && city == other.city && country == other.country;
}

std::ostream& operator<<(std::ostream& os, const Address& address)
{
    os << address.street_name << " " << address.street_number << "/" << address.flat_number << "; " << address.post_code << " " << address.city << "; " << address.country;
    return os;
}