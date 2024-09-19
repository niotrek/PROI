#include <iostream>
#include "invoice.hpp"
#include "item.hpp"
#include "company.hpp"
#include "address.hpp"
#include "readWrite.hpp"
#include "catch_amalgamated.hpp"
#include <sstream>
#include <vector>


TEST_CASE("invoice test", "[invoice]")
{
    Address apple_address("Flower Street", "1", "20", "01-234", "London", "England");
    Company apple(1234567891, apple_address, "Apple", "123456789", "apple.example@wp.pl");
  
    Address microsoft_address("Bond Street", "34/36", "2", "00091", "Dublin", "Ireland");
    Company microsoft(9234567892, microsoft_address, "Microsoft", "987654321", "microsoft.example@wp.pl");

    Address pw_address("PW Street", "4/36", "21", "00001", "Warsaw", "Poland");
    Company pw(8134567892, pw_address, "pw", "309210459", "pw.example@wp.pl");

    Item screws("screws", 5, 2.5);
    Item bowls("bowls", 27, 21.2);
    Item candles("candles", 100, 1.04);
    Item burgers("burgers", 1, 25.20);


    SECTION("items")
    {
        CHECK(screws.get_name() == "screws");
        CHECK(bowls.get_name() == "bowls");
        CHECK(candles.get_name() == "candles");
        CHECK(burgers.get_name() == "burgers");
        CHECK(screws.get_quantity() == 5);
        CHECK(bowls.get_quantity() == 27);
        CHECK(candles.get_quantity() == 100);
        CHECK(burgers.get_quantity() == 1);
        CHECK(screws.get_price() == 2.5);
        CHECK(bowls.get_price() == 21.2);
        CHECK(candles.get_price() == 1.04);
        CHECK(burgers.get_price() == 25.20);
        CHECK(screws.get_total_price() == 12.5);
        CHECK(bowls.get_total_price() == 572.4);
        CHECK(candles.get_total_price() == 104);
        CHECK(burgers.get_total_price() == 25.20);
    }

    SECTION("companies")
    {
        CHECK(apple.get_name() == "Apple");
        CHECK(microsoft.get_name() == "Microsoft");
        CHECK(pw.get_name() == "pw");
        CHECK(apple.get_nip() == 1234567891);
        CHECK(microsoft.get_nip() == 9234567892);
        CHECK(pw.get_nip() == 8134567892);
        CHECK(apple.get_phone_number() == "123456789");
        CHECK(microsoft.get_phone_number() == "987654321");
        CHECK(pw.get_phone_number() == "309210459");
    }

    SECTION("invoice")
    {
        Invoice invoice(apple, microsoft);
        invoice.add_item(screws);
        invoice.add_item(bowls);
        invoice.add_item(candles);
        invoice.add_item(burgers);
        CHECK(invoice.get_issuer() == apple);
        CHECK(invoice.get_recipient() == microsoft);
        std::vector<Item> items = invoice.get_goods();
        CHECK(items[0] == screws);
        CHECK(items[1] == bowls);
        CHECK(items[2] == candles);
        CHECK(items[3] == burgers);

        CHECK(invoice.get_payment() == 714.1);

        invoice.sort_by_name();
        std::vector<Item> items_sorted = invoice.get_goods();
        CHECK(items_sorted[0] == bowls);
        CHECK(items_sorted[1] == burgers);
        CHECK(items_sorted[2] == candles);
        CHECK(items_sorted[3] == screws);

        std::vector<Item> found = invoice.search_by_price(3);
        CHECK(found[0] == bowls);
        CHECK(found[1] == burgers);

        Item cheeseburgers("cheeseburgers", 5, 26.5);
        Item plates("plates", 3, 12.2);
        invoice.edit_item(burgers, cheeseburgers);
        invoice.edit_item(bowls, plates);

        CHECK(invoice.get_payment() == 285.6);

        std::vector<Item> items_edited = invoice.get_goods();
        CHECK(items_edited[0] == plates);
        CHECK(items_edited[1] == cheeseburgers);

        invoice.remove_item(cheeseburgers);
        invoice.remove_item(plates);
        CHECK(invoice.find_item(cheeseburgers) == "not found");
        CHECK(invoice.find_item(plates) == "not found");

        CHECK(invoice.get_payment() == 116.5);
    }

    SECTION("readWrite")
    {
        Invoice invoice2;
        ReadWrite files("items.txt", "companies.txt", "output.txt");
        Item carrots("carrots", 300, 2.45);
        Item potatos("potatos", 250, 0.99);
        Item ladders("ladders", 2, 329.99);
        Item iphone("iphone", 5, 5899);
        Company dell;
        dell.set_name("dell");
        dell.set_nip(3456789212);
        Company hp;
        hp.set_name("hp");
        hp.set_nip(4314235673);
        files.readItems();
        files.add_items_to_invoice(invoice2);
        std::vector<Item> items = invoice2.get_goods();
        CHECK(items[0] == carrots);
        CHECK(items[1] == potatos);
        CHECK(items[2] == ladders);
        CHECK(items[3] == iphone);
        files.readCompanies();
        files.add_companies_to_invoice(invoice2);
        CHECK(invoice2.get_issuer().get_name() == "dell");
        CHECK(invoice2.get_issuer().get_nip() == 3456789212);
        CHECK(invoice2.get_recipient().get_name() == "hp");
        CHECK(invoice2.get_recipient().get_nip() == 4314235673);
        files.writeInvoice(invoice2);
    }
 
}

