#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include "IFindFiguresSwitch.hpp"
#include "FindFiguresInvasive.hpp"
#include "FindFigures.hpp"
#include "FindFiguresKind.hpp"

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

        std::vector<std::vector<int>>screen2 {
        {1,0,0,0,0,0,1,0,1,1,0,0},
        {1,0,1,1,0,0,1,0,0,1,0,0},
        {0,1,0,1,0,0,1,0,0,0,0,0},
        {0,1,1,1,0,0,1,1,1,1,0,0},
        {0,0,0,0,0,1,0,0,0,1,1,1},
        {1,0,0,0,1,0,0,0,1,0,0,0},
        {0,0,1,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,0,0,0,0,0,0,0,1},
        {0,1,1,1,0,0,0,0,0,0,0,1}
        };

    try{
        //[1] Initialization
        FindFiguresKind ff(std::make_unique<FindFigures>(screen), 1);
        std::cout << "Provided matrix " << std::endl;
        ff.showMatrix(); //Display initial matrix state
        //[2] Call find method and assign return value to dedicated variable
        figures = ff.execute(); //Call required method
        //[3] Show figures found
        std::cout << "#################\n" << "figures found = " << figures << std::endl;

        //[4] Change find type with matrix modification approach
        ff.setStrategy(std::make_unique<FindFiguresInvasive>(screen2),1);
        std::cout << "New 'invasive' figures search was set with new matrix: \n";
        //[5] Show matrix
        ff.showMatrix(); //Display initial matrix state
        //[6]Call method
        figures = 0;
        figures = ff.execute();
        //[7] Show modified matrix
        std::cout << "After new figures search 'invasive' execution: \n";
        ff.showMatrix(); //Display modified matrix state
        //[8] Show result
        std::cout << "#################\n" << "figures found = " << figures << std::endl;
    }
    catch(const std::invalid_argument& e){
        std::cerr<< "Error: " << e.what() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << "Interface error: " << e.what() << "\n";
    }

    return 0;
}
