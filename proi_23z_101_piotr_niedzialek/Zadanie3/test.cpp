#include "catch_amalgamated.hpp"
#include <sstream>
#include "guest.hpp"
#include "guest_list.hpp"
#include <vector>

TEST_CASE("guest list tests")
{
    Guest john("John", "Smith");
    Guest mary("Mary", "Newman");
    Guest tom("Tom", "Brown");
    Guest anne("Anne", "Fox");
    Guest george("George", "Black");

    GuestList guests;
    guests.add_guest(john);
    guests.add_guest(mary);
    guests.add_guest(tom);
    guests.add_guest(anne);
    guests.add_guest(george);

    SECTION("adding to list and finding") 
    {
        auto found_guest = guests.find_guest("John", "Smith");
        CHECK(found_guest->get_first_name() == "John");
        CHECK(found_guest->get_last_name() == "Smith");

        auto found_guest2 = guests.find_guest("Mary", "Newman");
        CHECK(found_guest2->get_first_name() == "Mary");
        CHECK(found_guest2->get_last_name() == "Newman");

        auto found_guest3 = guests.find_guest("Tom", "Brown");
        CHECK(found_guest3->get_first_name() == "Tom");
        CHECK(found_guest3->get_last_name() == "Brown");

        auto found_guest4 = guests.find_guest("Anne", "Fox");
        CHECK(found_guest4->get_first_name() == "Anne");
        CHECK(found_guest4->get_last_name() == "Fox");

        //szukanie osoby której nie ma na liœcie goœci
        auto found_gest5 = guests.find_guest("Poli", "Technika");
        CHECK(found_gest5 == std::nullopt);
    }

  /*  SECTION("deleting guests")
    {
        guests.remove_guest(john);
        auto found_guest = guests.find_guest("John","Smith");
        CHECK(found_guest == std::nullopt);
        guests.remove_guest(mary);
        auto found_guest2 = guests.find_guest("Mary", "Newman");
        CHECK(found_guest2 == std::nullopt);
        guests.remove_guest(tom);
        auto found_guest3 = guests.find_guest("Tom", "Brown");
        CHECK(found_guest3 == std::nullopt);
        guests.remove_guest(anne);
        auto found_guest4 = guests.find_guest("Anne", "Fox");
        CHECK(found_guest4 == std::nullopt);
        guests.remove_guest(george);
        auto found_guest5 = guests.find_guest("George", "Black");
        CHECK(found_guest5 == std::nullopt);
    }
    */
}



