#include "fraction.hpp"
#include "catch_amalgamated.hpp"
#include <iostream>
#include <sstream>


TEST_CASE("Constructors") {
	Fraction number;
	REQUIRE(number.get_numerator() == 0);
	REQUIRE(number.get_denominator() == 1);
	
	Fraction number2(9, 10);
	REQUIRE(number2.get_numerator() == 9);
	REQUIRE(number2.get_denominator() == 10);

	Fraction number3(90, 150);
	REQUIRE(number3.get_numerator() == 90);
	REQUIRE(number3.get_denominator() == 150);
}

TEST_CASE("Setters") {
	Fraction number(2, 3);
	number.set_numerator(18);
	number.set_denominator(23);
	REQUIRE(number.get_numerator() == 18);
	REQUIRE(number.get_denominator() == 23);
}

TEST_CASE("Reduce fractions") {
	Fraction number(1280, 8980);
	Fraction number2 = number.reduce_fractions_const();
	REQUIRE(number.get_numerator() == 1280);
	REQUIRE(number.get_denominator() == 8980);
	REQUIRE(number2.get_numerator() == 64);
	REQUIRE(number2.get_denominator() == 449);
	number.reduce_fractions();
	REQUIRE(number.get_numerator() == 64);
	REQUIRE(number.get_denominator() == 449);

	Fraction number3(19683, 531441);
	Fraction number4 = number3.reduce_fractions_const();
	REQUIRE(number3.get_numerator() == 19683);
	REQUIRE(number3.get_denominator() == 531441);
	REQUIRE(number4.get_numerator() == 1);
	REQUIRE(number4.get_denominator() == 27);
	number3.reduce_fractions();
	REQUIRE(number3.get_numerator() == 1);
	REQUIRE(number3.get_denominator() == 27);
}

TEST_CASE ("Common denominator") {
	Fraction number(1280, 8980);
	Fraction number2(19683, 531441);
	Fraction number3 = number.common_denominator_const(number2);
	Fraction number4 = number2.common_denominator_const(number);
	REQUIRE(number.get_numerator() == 1280);
	REQUIRE(number.get_denominator() == 8980);
	REQUIRE(number2.get_numerator() == 19683);
	REQUIRE(number2.get_denominator() == 531441);
	REQUIRE(number3.get_numerator() == 1728);
	REQUIRE(number3.get_denominator() == 12123);
	REQUIRE(number4.get_numerator() == 449);
	REQUIRE(number4.get_denominator() == 12123);
	Fraction number5(2, 49);
	Fraction number5_2(2, 49);
	Fraction number6(61, 71);
	number5.common_denominator(number6);
	number6.common_denominator(number5_2);
	REQUIRE(number5.get_numerator() == 142);
	REQUIRE(number5.get_denominator() == 3479);
	REQUIRE(number6.get_numerator() == 2989);
	REQUIRE(number6.get_denominator() == 3479);
}

TEST_CASE("operator + and +=") {
	Fraction number(28, 49);
	Fraction number2(123, 431);
	Fraction number3 = number + number2;
	REQUIRE(number.get_numerator() == 28);
	REQUIRE(number.get_denominator() == 49);
	REQUIRE(number2.get_numerator() == 123);
	REQUIRE(number2.get_denominator() == 431);
	REQUIRE(number3.get_numerator() == 2585);
	REQUIRE(number3.get_denominator() == 3017);

	number += number2;
	REQUIRE(number.get_numerator() == 2585);
	REQUIRE(number.get_denominator() == 3017);
}

TEST_CASE("operator - and -=") {
	Fraction number(28, 49);
	Fraction number2(123, 431);
	Fraction number3 = number - number2;
	REQUIRE(number.get_numerator() == 28);
	REQUIRE(number.get_denominator() == 49);
	REQUIRE(number2.get_numerator() == 123);
	REQUIRE(number2.get_denominator() == 431);
	REQUIRE(number3.get_numerator() == 863);
	REQUIRE(number3.get_denominator() == 3017);

	number -= number2;
	REQUIRE(number.get_numerator() == 863);
	REQUIRE(number.get_denominator() == 3017);
}

TEST_CASE("operator * and *=") {
	Fraction number(28, 49);
	Fraction number2(123, 431);
	Fraction number3 = number * number2;
	REQUIRE(number.get_numerator() == 28);
	REQUIRE(number.get_denominator() == 49);
	REQUIRE(number2.get_numerator() == 123);
	REQUIRE(number2.get_denominator() == 431);
	REQUIRE(number3.get_numerator() == 492);
	REQUIRE(number3.get_denominator() == 3017);

	number *= number2;
	REQUIRE(number.get_numerator() == 492);
	REQUIRE(number.get_denominator() == 3017);
}

TEST_CASE("operator / and /=") {
	Fraction number(28, 49);
	Fraction number2(123, 431);
	Fraction number3 = number / number2;
	REQUIRE(number.get_numerator() == 28);
	REQUIRE(number.get_denominator() == 49);
	REQUIRE(number2.get_numerator() == 123);
	REQUIRE(number2.get_denominator() == 431);
	REQUIRE(number3.get_numerator() == 1724);
	REQUIRE(number3.get_denominator() == 861);

	number /= number2;
	REQUIRE(number.get_numerator() == 1724);
	REQUIRE(number.get_denominator() == 861);

	Fraction number4(28, 49);
	Fraction number5(0, 431);
	Fraction number6 = number4 / number5;
	REQUIRE(number6.get_numerator() == 0);
	REQUIRE(number6.get_denominator() == 1);

	number4 /= number5;
	REQUIRE(number4.get_numerator() == 28);
	REQUIRE(number4.get_denominator() == 49);
}

TEST_CASE("comparing") {
	Fraction number1(123, 456);
	Fraction number2(492, 1824);
	Fraction number3(789, 1011);
	REQUIRE((number1 == number2) == true);
	REQUIRE((number1 >= number2) == true);
	REQUIRE((number1 > number2) == false);
	REQUIRE((number1 <= number2) == true);
	REQUIRE((number1 < number2) == false);
	REQUIRE((number1 == number3) == false);
	REQUIRE((number1 >= number3) == false);
	REQUIRE((number1 > number3) == false);
	REQUIRE((number1 <= number3) == true);
	REQUIRE((number1 < number3) == true);
}

TEST_CASE("COUT") {
	Fraction number(123, 456);
	auto stdoutBuffer = std::cout.rdbuf();
	std::ostringstream oss;
	std::cout.rdbuf(oss.rdbuf());
	std::cout << number << std::endl;
	std::cout.rdbuf(stdoutBuffer);
	REQUIRE(oss.str() == "123/456\n");
}

TEST_CASE("CIN") {
	Fraction number;
	std::cin >> number;
	std::cout << number;
}
