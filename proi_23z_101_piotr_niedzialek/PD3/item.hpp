#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>

class Item
{
	private:
		std::string name;
		int quantity;
		double price; 
		double total_price;
	public:
		Item() = default;
		Item(std::string name, int quantity, double price);
		
		std::string get_name() const;
		int get_quantity() const;
		double get_price() const;
		double get_total_price() const;

		void count_total_price();
		void set_name(std::string name);
		void set_price(double price);
		void set_quantity(int quantity);
		bool operator==(const Item& other) const;
		bool operator<(const Item& other) const;
		friend std::ostream& operator<<(std::ostream& os, const Item& item);
};

std::ostream& operator<<(std::ostream& os, const Item& person);

#endif