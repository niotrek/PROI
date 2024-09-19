#ifndef INVOICE_HPP
#define INVOICE_HPP

#include <iostream>
#include <vector>
#include "item.hpp"
#include "company.hpp"

class Invoice
{
private:
	std::vector<Item> goods;
	Company issuer;
	Company recipient;
	double payment;
	void count_payment();
	std::vector<Item>::iterator find_items(const Item& item);
public:
	Invoice() = default;
	Invoice(Company issuer, Company recipient);
	Company get_issuer() const;
	Company get_recipient() const;
	double get_payment() const;
	std::vector<Item> get_goods() const;
	std::string find_item(const Item& item);

	void set_issuer(Company issuer);
	void set_recipient(Company recipient);

	bool add_item(const Item& item);
	bool edit_item(const Item& old_item, const Item& new_item);
	void remove_item(const Item& item);
	
	void sort_by_name();
	std::vector<Item> search_by_price(const double value);
	friend std::ostream& operator<<(std::ostream& os, const Invoice& invoice);
};
std::ostream& operator<<(std::ostream& os, const Invoice& invoice);


#endif