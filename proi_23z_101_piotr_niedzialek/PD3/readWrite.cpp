#include <iostream>
#include <vector>
#include <string>
#include "item.hpp"
#include "company.hpp"
#include "invoice.hpp"
#include "readWrite.hpp"
#include <fstream>
#include <sstream>

ReadWrite::ReadWrite(std::string fileNameItems, std::string fileNameCompanies, std::string fileNamePrint) 
    : fileNameItems(fileNameItems), fileNameCompanies(fileNameCompanies), fileNamePrint(fileNamePrint) {}

bool ReadWrite::readItems()
{
    std::ifstream inputFile(fileNameItems);

    if (inputFile.is_open()) 
    {
        std::string line;

        while (std::getline(inputFile, line)) 
        {
            std::istringstream iss(line);
            std::string name;
            double price;
            int quantity;

            if (iss >> name >> quantity >> price) 
            {
                Item newItem(name, quantity, price);
                items.push_back(newItem);
            }
        }
        inputFile.close();
        return true;
    }
    else 
    {
        std::cerr << "Error: Unable to open file " << fileNameItems << std::endl;
        return false;
    }
}
bool ReadWrite::readCompanies()
{
    std::ifstream inputFile(fileNameCompanies);

    if (inputFile.is_open())
    {
        std::string line;
        int i = 0;

        while (std::getline(inputFile, line) && i < 2)
        {
            std::istringstream iss(line);
            std::string name;
            int64_t NIP;

            if (iss >> name >> NIP)
            {
                Company company;
                company.set_name(name);
                company.set_nip(NIP);
                companies[i] = company;
            }
            i++;
        }
        inputFile.close();
        return true;
    }
    else
    {
        std::cerr << "Error: Unable to open file " << fileNameCompanies << std::endl;
        return false;
    }
}
std::string ReadWrite::get_fileNameItems() const
{
    return fileNameItems;
}
std::string ReadWrite::get_fileNameCompanies() const
{
    return fileNameCompanies;
}
std::string ReadWrite::get_fileNamePrint() const
{
    return fileNamePrint;
}
void ReadWrite::set_fileNameItems(const std::string& fileName)
{
    fileNameItems = fileName;
}
void ReadWrite::set_fileNameCompanies(const std::string& fileName)
{
    fileNameCompanies = fileName;
}
void ReadWrite::set_fileNamePrint(const std::string& fileName)
{
    fileNamePrint = fileName;
}
void ReadWrite::add_items_to_invoice(Invoice& invoice)
{
    for (auto& item : items)
    {
        invoice.add_item(item);
    }
}
void ReadWrite::add_companies_to_invoice(Invoice& invoice)
{
    invoice.set_issuer(companies[0]);
    invoice.set_recipient(companies[1]);
}
bool ReadWrite::writeInvoice(Invoice& invoice)
{
    std::ofstream outputFile(fileNamePrint);

    if (outputFile.is_open()) 
    {
        outputFile << invoice << std::endl;
        outputFile.close();
        std::cout << "Invoice written to " << fileNamePrint << std::endl;
    }
    else 
    {
        std::cerr << "Error: Unable to open file " << fileNamePrint << std::endl;
        return false;
    }
    return true;
}