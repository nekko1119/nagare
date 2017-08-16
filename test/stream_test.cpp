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
        SECTION("each should call the passed function as many iterators range")
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

    SECTION("map")
    {
        SECTION("map should return a stream that applied the passed function")
        {
            auto const func = [](int it) { return it * it; };
            std::vector<int> actual;
            actual.reserve(original.size());
            for (auto const& it : target.map(func)) {
                actual.emplace_back(it);
            }
            std::vector<int> expected = {1, 4, 9};
            REQUIRE(actual == expected);
        }

        SECTION("map should be lazy evaluation")
        {
            auto count      = 0U;
            auto const func = [&count](int it) {
                ++count;
                return it;
            };
            auto const mapped = target.map(func);
            REQUIRE(count == 0U);
            for (auto const& it : mapped) {
            }
            REQUIRE(count == original.size());
        }
    }
}
