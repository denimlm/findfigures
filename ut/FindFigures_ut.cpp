#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <catch2/matchers/catch_matchers_exception.hpp>
#include "FindFigures.hpp"
#include "FindFiguresInvasive.hpp"
#include "FindFiguresKind.hpp"

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

/* Test Invasive approach */
TEST_CASE("FindFiguresInvasive - check for different figures in a matrix with change of matrix") {
    SECTION("Search for different figures in the matrix") {
        std::vector<std::vector<int>> demo_matrix = {
            {1, 0, 0, 0, 0},
            {1, 0, 1, 1, 0},
            {0, 1, 0, 1, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 0, 0, 1}
        };

        FindFiguresInvasive searcher(demo_matrix);

        auto results = searcher.findFigures(1); // pattern of type '1' to search

        // 3 Figures mus be found
        REQUIRE(results == 3);

    }

    SECTION("Check for no pattern behavior") {
        std::vector<std::vector<int>> zero_matrix = {
            {0, 0, 0},
            {0, 0, 0}
        };
        FindFiguresInvasive searcher(zero_matrix);

        auto results = searcher.findFigures(1);
        REQUIRE(results == 0);
    }

    SECTION("Test with empty matrix") {
        std::vector<std::vector<int>> empty_matrix{};

        REQUIRE_THROWS_WITH([&](){
            FindFiguresInvasive searcher(empty_matrix);
            }(),
            "Provided matrix cannot be empty."
        );
    }

    SECTION("Test interface throw with wrong pattern=0") {
        std::vector<std::vector<int>> matrix = {
            {1, 0, 0},
            {0, 0, 1}
        };
        FindFiguresInvasive searcher(matrix);

        REQUIRE_THROWS_WITH([&](){
            searcher.findFigures(0);
            }(),
            "Provide correct non zero integer pattern value."
        );
    }
}

/* Tests with change of search type - strategy approach */
TEST_CASE("FindFiguresKind - check for different figures in a matrix with different approach") {
    SECTION("Search for different figures in the matrix") {
        std::vector<std::vector<int>> demo_matrix = {
            {1, 0, 0, 0, 0},
            {1, 0, 1, 1, 0},
            {0, 1, 0, 1, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 0, 0, 1}
        };

        FindFiguresKind searcher(std::make_unique<FindFigures>(demo_matrix),1);

        auto results = searcher.execute();

        // 3 Figures mus be found
        REQUIRE(results == 3);

    }

    SECTION("Check for no pattern behavior") {
        std::vector<std::vector<int>> zero_matrix = {
            {0, 0, 0},
            {0, 0, 0}
        };
        FindFiguresKind searcher(std::make_unique<FindFigures>(zero_matrix),1);

        auto results = searcher.execute();
        REQUIRE(results == 0);
    }

    SECTION("Test with empty matrix") {
        std::vector<std::vector<int>> empty_matrix{};

        REQUIRE_THROWS_WITH([&](){
            FindFiguresKind searcher(std::make_unique<FindFigures>(empty_matrix),1);
            }(),
            "Provided matrix cannot be empty."
        );
    }

    SECTION("Test interface throw with wrong pattern=0") {
        std::vector<std::vector<int>> matrix = {
            {1, 0, 0},
            {0, 0, 1}
        };
        FindFiguresKind searcher(std::make_unique<FindFigures>(matrix),0);

        REQUIRE_THROWS_WITH([&](){
            searcher.execute();
            }(),
            "Provide correct non zero integer pattern value."
        );
    }

    SECTION("Test FindfiguresKind non invasive and invasive switch strategy") {
        std::vector<std::vector<int>> demo_matrix = {
            {1, 0, 0, 0, 0},
            {1, 0, 1, 1, 0},
            {0, 1, 0, 1, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 0, 0, 1}
        };

        FindFiguresKind searcher(std::make_unique<FindFigures>(demo_matrix),1);

        auto results = searcher.execute();

        // 3 Figures mus be found
        REQUIRE(results == 3);
        std::vector<std::vector<int>> new_matrix = {
            {1, 0, 0, 0, 0},
            {1, 0, 1, 1, 0},
            {0, 1, 0, 1, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 0, 0, 1}
        };
        results = 0;
        searcher.setStrategy(std::make_unique<FindFiguresInvasive>(new_matrix),1);

        results = searcher.execute();
        REQUIRE(results == 3);
    }

    SECTION("Test FindfiguresKind non invasive and invasive switch strategy") {
        std::vector<std::vector<int>> demo_matrix = {
            {1, 0, 0, 0, 0},
            {1, 0, 1, 1, 0},
            {0, 1, 0, 1, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 0, 0, 1}
        };

        FindFiguresKind searcher(std::make_unique<FindFigures>(demo_matrix),1);

        auto results = searcher.execute();

        // 3 Figures mus be found
        REQUIRE(results == 3);
        std::vector<std::vector<int>> new_matrix = {
            {1, 0, 0, 0, 0},
            {1, 0, 1, 1, 0},
            {0, 1, 0, 1, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 0, 0, 1}
        };
        results = 0;
        searcher.setStrategy(nullptr,1);

        REQUIRE_THROWS_WITH([&](){
            searcher.execute();
            }(),
            "Critical error in FindFiguresKind: nullptr."
        );
    }
}
