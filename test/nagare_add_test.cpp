#include <nagare/nagare.h>
#include <catch.hpp>

TEST_CASE("nagare test 2", "[main]")
{
    SECTION("add 2")
    {
        auto const actual = nagare::add(1, 2);
        REQUIRE(actual == 3);
    }
}