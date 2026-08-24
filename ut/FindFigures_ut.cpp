#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <catch2/matchers/catch_matchers_exception.hpp>
#include "FindFigures.hpp"

TEST_CASE("FindFigures - check for different figures in a matrix") {
    SECTION("Search for different figures in the matrix") {
        std::vector<std::vector<int>> demo_matrix = {
            {1, 0, 0, 0, 0},
            {1, 0, 1, 1, 0},
            {0, 1, 0, 1, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 0, 0, 1}
        };

        FindFigures searcher(demo_matrix);

        auto results = searcher.findFigures(1); // pattern of type '1' to search

        // 3 Figures mus be found
        REQUIRE(results == 3);

    }

    SECTION("Check for no pattern behavior") {
        std::vector<std::vector<int>> zero_matrix = {
            {0, 0, 0},
            {0, 0, 0}
        };
        FindFigures searcher(zero_matrix);

        auto results = searcher.findFigures(1);
        REQUIRE(results == 0);
    }

    SECTION("Test with empty matrix") {
        std::vector<std::vector<int>> empty_matrix{};

        REQUIRE_THROWS_WITH([&](){
            FindFigures searcher(empty_matrix);
            }(),
            "Provided matrix cannot be empty."
        );
    }

    SECTION("Test interface throw with wrong pattern=0") {
        std::vector<std::vector<int>> matrix = {
            {1, 0, 0},
            {0, 0, 1}
        };
        FindFigures searcher(matrix);

        REQUIRE_THROWS_WITH([&](){
            searcher.findFigures(0);
            }(),
            "Provide correct non zero integer pattern value."
        );
    }
}

