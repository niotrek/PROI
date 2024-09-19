#include <iostream>
#include <vector>
#include "invoice.hpp"
#include <algorithm>

Invoice::Invoice(Company issuer, Company recipient) : issuer(issuer), recipient(recipient), payment(0.0) {}

std::vector<Item>::iterator Invoice::find_items(const Item& item)
{
	auto items = std::find(goods.begin(), goods.end(), item);
	return items;
}
std::string Invoice::find_item(const Item& item)
{
    if (std::find(goods.begin(), goods.end(), item) == goods.end())
    {
        return "not found";
    }
    else 
    {
        return "found";
    }
}

Company Invoice::get_issuer() const
{
    return issuer;
}
double Invoice::get_payment() const
{
    return payment;
}
Company Invoice::get_recipient() const
{
    return recipient;
}
std::vector<Item> Invoice::get_goods() const 
{
    return goods;
}
void Invoice::set_issuer(Company issuer)
{
    this->issuer = issuer;
}
void Invoice::set_recipient(Company recipient)
{
    this->recipient = recipient;
}
bool Invoice::add_item(const Item& item) 
{
    if (find_items(item) == goods.end())
    {
        goods.push_back(item); 
        payment = 0.0;
        count_payment();
        return true;
    }
    else
    {
        auto it = find_items(item);
        Item item2 = *it;
        if (item2.get_name() == item.get_name())
        {
            item2.set_quantity(item2.get_quantity() + item.get_quantity());
            item2.count_total_price();
            payment = 0.0;
            count_payment();
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool Invoice::edit_item(const Item& old_item, const Item& new_item) 
{
    if (find_items(new_item) == goods.end()) 
    {
        std::replace(goods.begin(), goods.end(), old_item, new_item);
        payment = 0.0;
        count_payment();
        return true;
    }
    return false;
}
void Invoice::remove_item(const Item& item)
{
    auto logical_end = std::remove(goods.begin(), goods.end(), item);
    goods.erase(logical_end, goods.end());
    payment = 0.0;
    count_payment();
}
void Invoice::count_payment() 
{
    for (const auto& item : goods) {
        payment += item.get_total_price();
    }
}
void Invoice::sort_by_name()
{
    std::sort(goods.begin(), goods.end());
}
std::vector<Item> Invoice::search_by_price(const double value)
{
    std::vector<Item> found_items;
    for (const auto& item : this->goods)
    {
        if (item.get_price() >= value)
        {
            found_items.push_back(item);
        }
    }
    return found_items;
}
std::ostream& operator<<(std::ostream& os, const Invoice& invoice)
{
    os << "Issuer: " << invoice.issuer << std::endl;
    for (const auto& item : invoice.goods) {
        os << item << std::endl;
    }
    os << "Recipient: " << invoice.recipient << std::endl;
    os << "Payment: " << invoice.payment << " PLN" << std::endl;
    return os;
    
}