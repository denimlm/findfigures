#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <catch2/matchers/catch_matchers_exception.hpp>
#include "FindFigures.hpp"

TEST_CASE("FindFigures - check for different figures in a matrix") {
    SECTION("Search for different figures in the matrix") {
        std::vector<std::vector<int>> complex_canvas = {
            {1, 0, 0, 0, 0},
            {1, 0, 1, 1, 0},
            {0, 1, 0, 1, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 0, 0, 1}
        };

        FindFigures searcher(complex_canvas);

        auto results = searcher.findFigures(1); // 1 pattern to search

        // 3 Figures mus be found
        REQUIRE(results == 3);

    }

    SECTION("Check for no pattern behavior") {
        std::vector<std::vector<int>> zero_canvas = {
            {0, 0, 0},
            {0, 0, 0}
        };
        FindFigures searcher(zero_canvas);

        auto results = searcher.findFigures(1);
        REQUIRE(results == 0);
    }

    SECTION("Test with empty matrix") {
        std::vector<std::vector<int>> empty_canvas{};

        REQUIRE_THROWS_WITH([&](){
            FindFigures searcher(empty_canvas);
            }(),
            "Provided matrix cannot be empty."
        );
    }
}

