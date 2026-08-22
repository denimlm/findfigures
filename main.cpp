#include <iostream>
#include <vector>
#include <queue>
#include "FindFigures.hpp"
#include <climits>

// Find number of all individial figures
/*
 * +---+---+---+---+---+
 * | 1 |   |   |   |   |
 * +---+---+---+---+---+
 * | 1 |   | 2 | 2 |   |
 * +---+---+---+---+---+
 * |   | 2 |   | 2 |   |
 * +---+---+---+---+---+
 * |   | 2 | 2 | 2 |   |
 * +---+---+---+---+---+
 * |   |   |   |   | 3 |
 * +---+---+---+---+---+
 */


int main() {
    //Initialize matrix with pattern "1"
    std::vector<std::vector<uint32_t>>screen {
        {1,0,0,0,0,0,1,1,1,1,0,0},
        {1,0,1,1,0,0,1,0,0,1,0,0},
        {0,1,0,1,0,0,1,0,1,1,0,0},
        {0,1,1,1,0,0,1,1,1,1,0,0},
        {0,0,0,0,0,1,0,0,0,1,1,1},
        {1,0,0,0,1,0,0,0,1,0,0,0},
        {0,0,1,0,0,0,1,1,0,0,0,0},
        {0,1,1,1,0,0,0,1,1,0,0,1}};

    uint32_t figures = 0; //define variable to store number of figures found

    try{
        FindFigures ff(screen);
        std::cout << "Provided matrix " << std::endl;
        ff.displayMatrix(); //Display initial matrix state
        figures = ff.findFigures(1); //Provide pattern to search
        // Show figures found
        std::cout << "figures found = " << figures << std::endl;
    }
    catch(const std::invalid_argument& e){
        std::cerr<< "Error: " << e.what() << std::endl;
    }

    return 0;
}
