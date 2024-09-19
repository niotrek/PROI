#include "item.hpp"

Item::Item(std::string name, int quantity, double price) : name(name), quantity(quantity),price(price), total_price(quantity*price) {}

void Item::count_total_price() 
{
	total_price = quantity * price;
}
std::string Item::get_name() const
{
	return name;
}
int Item::get_quantity() const
{
	return quantity;
}
double Item::get_price() const
{
	return price;
}
double Item::get_total_price() const
{
	return total_price;
}
void Item::set_name(std::string name)
{
	this->name = name;
}
void Item::set_price(double price)
{
	this->price = price;
	count_total_price();
}
void Item::set_quantity(int quantity)
{
	this->quantity = quantity;
	count_total_price();
}
bool Item::operator==(const Item& other) const
{
	return name == other.name && quantity == other.quantity && price == other.price &&
		total_price == other.total_price;
}
bool Item::operator<(const Item& other) const
{
	return name < other.name;
}
std::ostream& operator<<(std::ostream& os, const Item& item)
{
	os << item.name << " " << item.quantity << " x " << item.price << " = " << item.total_price << " PLN" << std::endl;
	return os;
}