#include "guest.hpp"

Guest::Guest(std::string first_name, std::string last_name) :
    first_name(first_name), last_name(last_name) {}

std::string Guest::get_first_name() const
{
    return first_name;
}

std::string Guest::get_last_name() const
{
    return last_name;
}

void Guest::set_first_name(std::string first_name)
{
    this->first_name = first_name;
}

void Guest::set_last_name(std::string last_name)
{
    this->last_name = last_name;
}


//operatory
bool Guest::operator==(const Guest& other) const
{
    return first_name == other.first_name && last_name == other.last_name;
}

bool Guest::operator<(const Guest& other) const 
{
    return last_name < other.last_name;
}

std::ostream& operator<<(std::ostream& os, const Guest& guest)
{
    os << guest.first_name << " " << guest.last_name << std::endl;
    return os;
}

bool Guest::has_given_name(std::string first_name, std::string last_name) const
{
    return this->first_name == first_name && this->last_name == last_name;
}