#include <nagare/stream.hpp>
#include <vector>

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

TEST_CASE("stream", "[stream]")
{
    using container      = std::vector<int>;
    using iterator       = container::iterator;
    using const_iterator = container::const_iterator;

    container original    = {1, 2, 3};
    container const empty = {};
    nagare::stream<iterator> target{original.begin(), original.end()};

    SECTION("each")
    {
        SECTION("each should call a passed function as many iterators range")
        {
            auto count      = 0U;
            auto const func = [&count](int) { ++count; };
            target.each(func);
            REQUIRE(count == original.size());

            count = 0U;
            nagare::stream<const_iterator> empty_stream{empty.begin(),
                                                        empty.end()};
            empty_stream.each(func);
            REQUIRE(count == empty.size());
        }
    }
}
