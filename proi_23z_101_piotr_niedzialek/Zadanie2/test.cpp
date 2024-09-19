#include "catch_amalgamated.hpp"
#include <sstream>
#include "complex_number.hpp"


TEST_CASE("complex number tests", "[complex number]")
{
    ComplexNumber zero;
    ComplexNumber one_real(1.0, 0.0);
    ComplexNumber one_imag(0.0, 1.0);
    ComplexNumber one_real_one_imag(1.0, 1.0);
    ComplexNumber some_number(2.4, 3.9);
    ComplexNumber some_number2(4, 8);
    ComplexNumber some_number3(5.5, 6.2);
    ComplexNumber some_number4(8, 4);

    SECTION("multiplication") {
        CHECK(some_number2 * some_number3 == ComplexNumber(-27.6, 68.8));
        CHECK(some_number2 == ComplexNumber(4.0, 8.0));
        CHECK(some_number3 == ComplexNumber(5.5, 6.2));

        CHECK((one_imag *= some_number) == ComplexNumber(-3.9, 2.4));
        CHECK(one_imag == ComplexNumber(-3.9, 2.4));
        CHECK(some_number == ComplexNumber(2.4, 3.9));
    }

    SECTION("division") {
        CHECK(some_number2 / some_number4 == ComplexNumber(0.8,0.6));
        CHECK(some_number2 == ComplexNumber(4.0, 8.0));
        CHECK(some_number4 == ComplexNumber(8.0, 4.0));

        CHECK((one_imag /= some_number) == ComplexNumber(-3.9, 2.4));
        CHECK(one_imag == ComplexNumber(-3.9, 2.4));
        CHECK(some_number == ComplexNumber(2.4, 3.9));
    }

    SECTION("tests of constructors, getters and setters")
    {
        CHECK(zero.get_real_part() == 0.0); //UWAGA: takie porównanie wartoœci zmiennoprzecinkowych mo¿e w ogólnym przypadku dawaæ nieoczekiwane wyniki ze wzglêdu na niedok³adnoœæ reprezentacji - lepiej za³o¿yæ pewien margines b³êdu
        CHECK(zero.get_imaginary_part() == 0.0);
        CHECK(one_real.get_real_part() == 1.0);
        CHECK(one_real.get_imaginary_part() == 0.0);
        CHECK(one_imag.get_real_part() == 0.0);
        CHECK(one_imag.get_imaginary_part() == 1.0);
        CHECK(one_real_one_imag.get_real_part() == 1.0);
        CHECK(one_real_one_imag.get_imaginary_part() == 1.0);
        CHECK(some_number.get_real_part() == 2.4);
        CHECK(some_number.get_imaginary_part() == 3.9);

        zero.set_imaginary_part(2.1);
        CHECK(zero.get_real_part() == 0.0);
        CHECK(zero.get_imaginary_part() == 2.1);
        zero.set_real_part(98.2);
        CHECK(zero.get_real_part() == 98.2);
        CHECK(zero.get_imaginary_part() == 2.1);
    }

    SECTION("comparison tests")
    {
        ComplexNumber another_zero;
        ComplexNumber another_one_real(1.0, 0.0);
        ComplexNumber another_one_imag(0.0, 1.0);
        ComplexNumber another_one_real_one_imag(1.0, 1.0);
        ComplexNumber another_some_number(2.4, 3.9);

        CHECK(zero == zero);
        CHECK(zero == another_zero);
        CHECK(one_real == one_real);
        CHECK(one_real == another_one_real);
        CHECK(some_number == some_number);
        CHECK(another_some_number == some_number);
        CHECK(another_one_imag == one_imag);
        CHECK(one_real_one_imag == another_one_real_one_imag);
        CHECK_FALSE(zero == another_some_number);
        CHECK_FALSE(one_imag == one_real_one_imag);

        CHECK_FALSE(zero != another_zero);
        CHECK_FALSE(another_one_real != one_real);
        CHECK_FALSE(one_imag != another_one_imag);
        CHECK_FALSE(another_one_real_one_imag != one_real_one_imag);
        CHECK_FALSE(some_number != another_some_number);
        CHECK(one_real != one_real_one_imag);
        CHECK(one_real_one_imag != another_some_number);
    }

    SECTION("pre-incrementation tests")
    {
        CHECK(++zero == ComplexNumber(1.0, 0.0));
        CHECK(zero == ComplexNumber(1.0, 0.0));

        CHECK(++one_real == ComplexNumber(2.0, 0.0));
        CHECK(one_real == ComplexNumber(2.0, 0.0));

        CHECK(++one_imag == ComplexNumber(1.0, 1.0));
        CHECK(one_imag == ComplexNumber(1.0, 1.0));

        CHECK(++one_real_one_imag == ComplexNumber(2.0, 1.0));
        CHECK(one_real_one_imag == ComplexNumber(2.0, 1.0));

        CHECK(++some_number == ComplexNumber(3.4, 3.9));
        CHECK(some_number == ComplexNumber(3.4, 3.9));

        ++some_number;
        CHECK(some_number == ComplexNumber(4.4, 3.9));

    }

    SECTION("post-incrementation tests")
    {
        CHECK(zero++ == ComplexNumber(0.0, 0.0));
        CHECK(zero == ComplexNumber(1.0, 0.0));

        CHECK(one_real++ == ComplexNumber(1.0, 0.0));
        CHECK(one_real == ComplexNumber(2.0, 0.0));

        CHECK(one_imag++ == ComplexNumber(0.0, 1.0));
        CHECK(one_imag == ComplexNumber(1.0, 1.0));

        CHECK(one_real_one_imag++ == ComplexNumber(1.0, 1.0));
        CHECK(one_real_one_imag == ComplexNumber(2.0, 1.0));

        CHECK(some_number++ == ComplexNumber(2.4, 3.9));
        CHECK(some_number == ComplexNumber(3.4, 3.9));
        CHECK(some_number++ == ComplexNumber(3.4, 3.9));
        CHECK(some_number == ComplexNumber(4.4, 3.9));
    }

    SECTION("addition operator tests")
    {
        CHECK(one_imag + one_real == ComplexNumber(1.0, 1.0));
        CHECK(one_real == ComplexNumber(1.0, 0.0));
        CHECK(one_imag == ComplexNumber(0.0, 1.0));

        CHECK(one_imag + some_number == ComplexNumber(2.4, 4.9));
        CHECK(one_imag == ComplexNumber(0.0, 1.0));
        CHECK(some_number == ComplexNumber(2.4, 3.9));

        CHECK(some_number + one_real == ComplexNumber(3.4, 3.9));
        CHECK(some_number == ComplexNumber(2.4, 3.9));
        CHECK(one_real == ComplexNumber(1.0, 0.0));

        CHECK(some_number + zero == some_number);
        CHECK(some_number == ComplexNumber(2.4, 3.9));
        CHECK(zero == ComplexNumber(0.0, 0.0));

        CHECK(zero + one_real_one_imag == ComplexNumber(1.0, 1.0));
        CHECK(zero == ComplexNumber(0.0, 0.0));
        CHECK(one_real_one_imag == ComplexNumber(1.0, 1.0));
    }

    SECTION("addition operator with assignment tests")
    {
        CHECK((one_imag += one_real) == ComplexNumber(1.0, 1.0));
        CHECK(one_real == ComplexNumber(1.0, 0.0));
        CHECK(one_imag == ComplexNumber(1.0, 1.0));

        CHECK((one_imag += some_number) == ComplexNumber(3.4, 4.9));
        CHECK(one_imag == ComplexNumber(3.4, 4.9));
        CHECK(some_number == ComplexNumber(2.4, 3.9));

        CHECK((some_number += one_real) == ComplexNumber(3.4, 3.9));
        CHECK(some_number == ComplexNumber(3.4, 3.9));
        CHECK(one_real == ComplexNumber(1.0, 0.0));

        CHECK((some_number += zero) == ComplexNumber(3.4, 3.9));
        CHECK(some_number == ComplexNumber(3.4, 3.9));
        CHECK(zero == ComplexNumber(0.0, 0.0));

        CHECK((zero += one_real_one_imag) == ComplexNumber(1.0, 1.0));
        CHECK(zero == ComplexNumber(1.0, 1.0));
        CHECK(one_real_one_imag == ComplexNumber(1.0, 1.0));
    }

    SECTION("tests of operator<<")
    {
        std::stringstream stream_zero;
        stream_zero << zero;
        CHECK(stream_zero.str() == "(0 + 0i)");

        std::stringstream stream_one_real;
        stream_one_real << one_real;
        CHECK(stream_one_real.str() == "(1 + 0i)");

        std::stringstream stream_one_imag;
        stream_one_imag << one_imag;
        CHECK(stream_one_imag.str() == "(0 + 1i)");

        std::stringstream stream_one_real_one_imag;
        stream_one_real_one_imag << one_real_one_imag;
        CHECK(stream_one_real_one_imag.str() == "(1 + 1i)");

        std::stringstream stream_some_number;
        stream_some_number << some_number;
        CHECK(stream_some_number.str() == "(2.4 + 3.9i)");

    }

    SECTION("copy constructor tests")
    {
        ComplexNumber some_number_copy(some_number);
        CHECK(some_number_copy == ComplexNumber(2.4, 3.9));
        CHECK(some_number == ComplexNumber(2.4, 3.9));
        CHECK(some_number_copy == some_number);

        ComplexNumber another_copy = some_number;
        CHECK(another_copy == ComplexNumber(2.4, 3.9));
        CHECK(some_number == ComplexNumber(2.4, 3.9));
        CHECK(another_copy == some_number);
    }

    SECTION("move constructor tests")
    {
        ComplexNumber moved_number(std::move(some_number));
        CHECK(moved_number == ComplexNumber(2.4, 3.9));
        CHECK(some_number == ComplexNumber(0.0, 0.0));
        CHECK(moved_number != some_number);
    }

    SECTION("copy assignment tests")
    {
        ComplexNumber result;
        result = some_number;
        CHECK(result == ComplexNumber(2.4, 3.9));
        CHECK(some_number == ComplexNumber(2.4, 3.9));
        CHECK(result == some_number);
    }

    SECTION("move assignment tests")
    {
        ComplexNumber result;
        result = some_number + one_real_one_imag;
        CHECK(result == ComplexNumber(3.4, 4.9));
        CHECK(some_number == ComplexNumber(2.4, 3.9));
        CHECK(one_real_one_imag == ComplexNumber(1.0, 1.0));

        result = std::move(some_number);
        CHECK(result == ComplexNumber(2.4, 3.9));
        CHECK(some_number == ComplexNumber(0.0, 0.0));
        CHECK(result != some_number);
    }


}



