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
    std::vector<std::vector<int>>screen {{1,0,0,0,0,0,1,0,0,0,0,0},{1, 0, 1, 1, 0,0,1,0,0,0,0,0}, {0, 1, 0, 1, 0,0,1,0,0,1,0,0},{0,1,1,1,0,0,1,0,0,1,0,0}, {0, 0, 0, 0, 0,1,1,0,0,1,1,1}, {1, 0, 0, 0, 1,0,1,0,0,0,0,0}, {0,0,1,0,0,0,1,0,0,0,1,1}, {0,1,1,1,0,0,1,0,0,0,1,1}};
    int figures = 0;
    try{
        FindFigures ff(screen);
        std::cout << "Initial " << std::endl;
        ff.displayMatrix();
        figures = ff.findFigures(1);
        std::cout << "After" << std::endl;
        ff.displayMatrix();
    }
    catch(const std::invalid_argument& e){
        std::cerr<< "Error: " << e.what() << std::endl;
    }

    std::cout << "figures = " << figures << std::endl;
    std::cout << "END" << std::endl;
    return 0;
}
