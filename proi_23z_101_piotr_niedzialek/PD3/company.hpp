#ifndef COMPANY_HPP	
#define COMPANY_HPP

#include <string>
#include <iostream>
#include "address.hpp"

class Company
{
	private:
		int64_t NIP;
		Address address;
		std::string name;
		std::string phone_number;
		std::string email_address;
	public:
		Company() = default;
		Company(int64_t NIP, Address address, std::string name, std::string phone_number, std::string email_address);

		int64_t get_nip() const;
		std::string get_name() const;
		std::string get_phone_number() const;
		std::string get_email_address() const;
		Address get_address() const;

		void set_nip(int64_t nip);
		void set_name(std::string name);
		void set_phone_number(std::string phone_number);
		void set_email_address(std::string email_address);
		void set_address(Address address);
		friend std::ostream& operator<<(std::ostream& os, const Company& company);
		bool operator==(const Company& other) const;
};

std::ostream& operator<<(std::ostream& os, const Company& company);





#endif