#ifndef GUEST_LIST_HPP
#define GUEST_LIST_HPP

#include <vector>
#include <optional>
#include "guest.hpp"

class GuestList
{
private:
    std::vector<Guest> guests; 
    std::vector<Guest>::iterator find_guest(const Guest& person);
public:
    std::optional<Guest> find_guest(std::string first_name, std::string last_name) const;
    bool add_guest(const Guest& guest);
    bool edit_guest(const Guest& old_guest_data, const Guest& new_guest_data);
    bool edit_guest(std::string old_guest_first_name, std::string old_guest_last_name, const Guest& new_guest_data);
    void remove_guest(const Guest& guest);
    void remove_guest(std::string guest_first_name, std::string _last_name);
    void sort_guests_by_last_name();
    friend std::ostream& operator<<(std::ostream& os, const GuestList& guest_list);
};

std::ostream& operator<<(std::ostream& os, const GuestList& guest_list);

#endif