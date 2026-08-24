#include <iostream>
#include <vector>
#include <queue>
#include "FindFigures.hpp"

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
    std::vector<std::vector<int>>screen {
        {1,0,0,0,0,0,1,1,1,1,0,0},
        {1,0,1,1,0,0,1,0,0,1,0,0},
        {0,1,0,1,0,0,1,0,1,1,0,0},
        {0,1,1,1,0,0,1,1,1,1,0,0},
        {0,0,0,0,0,1,0,0,0,1,1,1},
        {1,0,0,0,1,0,0,0,1,0,0,0},
        {0,0,1,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,0,0,0,0,0,0,0,1}};

    uint32_t figures = 0; //define variable to store number of figures found

    try{
        //[1] Initialization
        FindFigures ff(screen);
        std::cout << "Provided matrix " << std::endl;
        ff.displayMatrix(); //Display initial matrix state
        //[2] Call find method and assign return value to dedicated variable
        figures = ff.findFigures(1); //Provide pattern to search
        //[3] Show figures found
        std::cout << "#################\n" << "figures found = " << figures << std::endl;
    }
    catch(const std::invalid_argument& e){
        std::cerr<< "Error: " << e.what() << std::endl;
    }

    return 0;
}
