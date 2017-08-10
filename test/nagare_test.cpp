#include <nagare/nagare.h>

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

TEST_CASE("nagare test", "[main]")
{
    SECTION("add")
    {
        auto const actual = nagare::add(1, 2);
        REQUIRE(actual == 3);
    }
}


