#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "circle.hpp"
#include "rect.hpp"
#include "line.hpp"
#include "svg.hpp"

TEST_CASE("Circle toSVG", "[circle]") {
    Circle circle("red", "blue", 50, 50, 50);
    REQUIRE(circle.toSVG() == "<circle cx=\"50\" cy=\"50\" r=\"50\" fill=\"red\" stroke=\"blue\" />");
}

TEST_CASE("Circle invalid radius", "[circle]") {
    REQUIRE_THROWS_AS(Circle("red", "blue", 50, 50, -50), std::invalid_argument);
}

TEST_CASE("Circle invalid position", "[circle]") {
    REQUIRE_THROWS_AS(Circle("red", "blue", -50, -50, 50), std::invalid_argument);
}

TEST_CASE("Rect toSVG", "[rect]") {
    Rect rect("green", "black", 10, 20, 100, 200);
    REQUIRE(rect.toSVG() == "<rect x=\"10\" y=\"20\" width=\"100\" height=\"200\" fill=\"green\" stroke=\"black\" />");
}

TEST_CASE("Rect invalid dimensions", "[rect]") {
    REQUIRE_THROWS_AS(Rect("green", "black", 10, 20, -100, -200), std::invalid_argument);
}

TEST_CASE("Rect invalid position", "[rect]") {
    REQUIRE_THROWS_AS(Rect("green", "black", -10, -20, 100, 200), std::invalid_argument);
}

TEST_CASE("Line toSVG", "[line]") {
    Line line("yellow", "purple", 0, 0, 300, 0);
    REQUIRE(line.toSVG() == "<line x1=\"0\" y1=\"0\" x2=\"300\" y2=\"0\" stroke=\"purple\" />");
}

TEST_CASE("Line invalid position", "[line]") {
    REQUIRE_THROWS_AS(Line("yellow", "purple", -10, -20, 300, 0), std::invalid_argument);
}
TEST_CASE("SVG remove", "[svg]") {
    SVG svg;
    svg.add(std::make_unique<Circle>("red", "blue", 50, 50, 50));
    svg.add(std::make_unique<Rect>("green", "black", 10, 20, 100, 200));
    svg.add(std::make_unique<Line>("yellow", "purple", 0, 0, 300, 0));

    REQUIRE(svg.objects.size() == 3);  

    svg.remove(1);  

    REQUIRE(svg.objects.size() == 2);  
}
TEST_CASE("SVG add and save", "[svg]") {
    SVG svg;
    svg.add(std::make_unique<Circle>("red", "blue", 50, 50, 50));
    svg.add(std::make_unique<Rect>("green", "black", 100, 200, 100, 200));
    svg.add(std::make_unique<Line>("yellow", "purple", 150, 250, 300, 450));

    std::string filename = "test.svg";
    svg.save(filename);

    std::ifstream file(filename);
    std::string line;
    std::string contents;

    while (std::getline(file, line)) {
        contents += line + "\n";
    }

    REQUIRE(contents == "<svg xmlns=\"http://www.w3.org/2000/svg\">\n<circle cx=\"50\" cy=\"50\" r=\"50\" fill=\"red\" stroke=\"blue\" />\n<rect x=\"100\" y=\"200\" width=\"100\" height=\"200\" fill=\"green\" stroke=\"black\" />\n<line x1=\"150\" y1=\"250\" x2=\"300\" y2=\"450\" stroke=\"purple\" />\n</svg>\n");
}
