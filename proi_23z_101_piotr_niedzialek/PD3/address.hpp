#ifndef ADDRESS_HPP
#define ADDRESS_HPP

#include <string>
#include <iostream>

class Address
{
    private:
        std::string street_name;
        std::string street_number; //nie jako liczba, bo mogą być adresy typu Uliczna 1/3 albo Uliczna 1A
        std::string flat_number; //podobnie jak powyżej
        std::string post_code;
        std::string city;
        std::string country;
    public:
        //konstruktory
        Address() = default; //wymuszamy, aby kompilator wygenerował konstruktor domyślny (nie zrobi tego automatycznie, bo klasa - poniżej - ma zdefiniowany konstruktor argumentowy)
        Address(std::string street_name, std::string street_number, std::string flat_number, std::string post_code, std::string city, std::string country);
        
        //gettery
        std::string get_street_name() const;
        std::string get_street_number() const;
        std::string get_flat_number() const;
        std::string get_post_code() const;
        std::string get_city() const;
        std::string get_country() const;

        //settery
        void set_street_name(std::string street_name);
        void set_street_number(std::string street_number);
        void set_flat_number(std::string flat_number);
        void set_post_code(std::string post_code);
        void set_city(std::string city);
        void set_country(std::string country); 

        //operatory
        bool operator==(const Address& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Address& address);

};

std::ostream& operator<<(std::ostream& os, const Address& address);



#endif