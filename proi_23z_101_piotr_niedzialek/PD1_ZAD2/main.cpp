#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include "calculator.hpp"


int main()
{
	Calculator convert;
	std::string input;
	while (true)
	{
		std::cout << "Podaj jednostke (mm^2, cm^2 ... ary, akry hektary)" << std::endl;
		std::cout << "Wyjscie: wpisz \"exit\"" << std::endl;
		std::cin >> input;
		system("cls");
		if (input == "exit")
		{
			return 0;
		}
		if (!convert.set_unit(input))
		{
			std::cout << "Bledna jednostka" << std::endl;
			continue;
		}
		start:
		std::cout << "Podaj wartosc" << std::endl;
		std::cout << "Wyjscie: wpisz \"exit\"" << std::endl;
		std::cin >> input;
		system("cls");
		if (input == "exit")
		{
			return 0;
		}
		if (!convert.set_value(input))
		{
			std::cout << "Bledna wartosc" << std::endl;
			goto start;
		}
		start2:
		std::cout << "Podaj jednostke docelowa" << std::endl;
		std::cout << "Wyjscie: wpisz \"exit\"" << std::endl;
		std::cin >> input;
		system("cls");
		if (input == "exit")
		{
			return 0;
		}
		if (!convert.set_second_unit(input))
		{
			std::cout << "Bledna jednostka" << std::endl;
			goto start2;
		}
		std::cout << "Wynik: " << convert.get_result() << std::endl;
		std::cout << "Nacisnij dowolny znak i enter zeby kontynuowac / wpisz\"exit\" aby wyjsc" << std::endl;
		std::cin >> input;
		system("cls");
		if (input == "exit")
		{
			return 0;
		}
		else 
		{
			continue;
		}
		
	}
	return 0;

}