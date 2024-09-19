#ifndef READWRITE_HPP
#define READWRITE_HPP

#include <iostream>
#include <vector>
#include <string>
#include "item.hpp"
#include "company.hpp"
#include "invoice.hpp"
#include <array>

class ReadWrite
{
	private:
		std::string fileNameItems;
		std::string fileNameCompanies;
		std::string fileNamePrint;
		std::vector<Item> items;
		std::array<Company, 2> companies;
	public:
		ReadWrite() = default;
		ReadWrite(std::string fileNameItems, std::string fileNameCompanies, std::string fileNamePrint);
		bool readItems();
		bool readCompanies();
		std::string get_fileNameItems() const;
		std::string get_fileNameCompanies() const;
		std::string get_fileNamePrint() const;
		void set_fileNameItems(const std::string& fileName);
		void set_fileNameCompanies(const std::string& fileName);
		void set_fileNamePrint(const std::string& fileName);
		void add_items_to_invoice(Invoice& invoice);
		void add_companies_to_invoice(Invoice& invoice);
		bool writeInvoice(Invoice& invoice);
};





#endif
