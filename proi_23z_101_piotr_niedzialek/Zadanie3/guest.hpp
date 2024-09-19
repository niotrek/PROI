#ifndef GUEST_HPP
#define GUEST_HPP

#include <string>
#include <iostream>

class Guest
{
private:
    std::string first_name;
    std::string last_name;
 
public:
    Guest() = default;
    Guest(std::string first_name, std::string last_name);

    std::string get_first_name() const;
    std::string get_last_name() const;
    
    void set_first_name(std::string first_name);
    void set_last_name(std::string last_name);

    //operatory
    bool operator==(const Guest& other) const;
    bool operator<(const Guest& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Guest& guest);

    bool has_given_name(std::string first_name, std::string last_name) const;

};

std::ostream& operator<<(std::ostream& os, const Guest& guest);

#endif