#include "company.hpp"	

Company::Company(int64_t NIP, Address address, std::string name, std::string phone_number, std::string email_address) :
	NIP(NIP), name(name), phone_number(phone_number), email_address(email_address) {}

int64_t Company::get_nip() const
{
    return NIP;
}

std::string Company::get_name() const
{
    return name;
}

std::string Company::get_phone_number() const
{
    return phone_number;
}

std::string Company::get_email_address() const
{
    return email_address;
}

Address Company::get_address() const
{
    return address;
}

void Company::set_nip(int64_t NIP)
{
    this -> NIP = NIP;
}

void Company::set_name(std::string name)
{
    this -> name = name;
}

void Company::set_phone_number(std::string phone_number)
{
    this -> phone_number = phone_number;
}

void Company::set_email_address(std::string email_address)
{
    this ->email_address = email_address;
}

void Company::set_address(Address address)
{
    this -> address = address;
}
std::ostream& operator<<(std::ostream& os, const Company& company)
{
    os << company.name << " NIP: " << company.NIP << std::endl;
    return os;
}
bool Company::operator==(const Company& other) const
{
    return NIP == other.NIP && address == other.address && name == other.name &&
        phone_number == other.phone_number && email_address == other.email_address;
}