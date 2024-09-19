#include "guest_list.hpp"
#include <algorithm>

std::vector<Guest>::iterator GuestList::find_guest(const Guest& person)
{
    auto contact = std::find(guests.begin(), guests.end(), person);
    return contact;
}

std::optional<Guest> GuestList::find_guest(std::string first_name, std::string last_name) const
{
    auto contact_it = std::find_if(guests.begin(), guests.end(),
        [&](const Guest& p) { return p.has_given_name(first_name, last_name); });
    if (contact_it != guests.end())
    {
        return std::optional<Guest>(*contact_it);
    }
    return std::nullopt;
}


bool GuestList::add_guest(const Guest& person)
{
    if (find_guest(person) == guests.end())
    {
        guests.push_back(person); //dodawanie nowego elementu zawsze na koniec
        return true;
    }
    return false;
}


bool GuestList::edit_guest(const Guest& old_person_data, const Guest& new_person_data)
{
    if (find_guest(new_person_data) == guests.end()) //wartoœci, na któr¹ chcemy podmieniæ, nie ma na liœcie kontaktów, wiêc mo¿na zmieniaæ - nie bêdzie duplikatu
    {
        std::replace(guests.begin(), guests.end(), old_person_data, new_person_data);
        return true;
    }
    return false;
}

bool GuestList::edit_guest(std::string old_person_first_name, std::string old_person_last_name, const Guest& new_person_data)
{
    if (find_guest(new_person_data) == guests.end())
    {
        std::replace_if(guests.begin(), guests.end(),
            [&](const Guest& p) { return p.has_given_name(old_person_first_name, old_person_last_name); },
            new_person_data);
        return true;
    }
    return false;
}

void GuestList::remove_guest(const Guest& person)
{
    auto logical_end = std::remove(guests.begin(), guests.end(), person);
    guests.erase(logical_end, guests.end());
}

void GuestList::remove_guest(std::string person_first_name, std::string person_last_name)
{
    guests.erase(std::remove_if(guests.begin(), guests.end(),
        [&](const Guest& p) { return p.has_given_name(person_first_name, person_last_name); }), guests.end());
}

void GuestList::sort_guests_by_last_name()
{
    std::sort(guests.begin(), guests.end());
}

std::ostream& operator<<(std::ostream& os, const GuestList& guests_list)
{
    unsigned counter = 1;
    for (const auto& contact : guests_list.guests)
    {
        os << counter << ". " << contact << std::endl;
        counter++;
    }
    return os;
}