#include "FindFigures.hpp"
#include <iostream>
#include <cstdint>
#include <climits>

FindFigures::FindFigures(std::vector<std::vector<uint32_t>>&out):localStorage{std::move(out)}{
    matrixValidation();
}
/* findFigures()
* Search for provided patterns
* return number of figures found
*/
uint32_t FindFigures::findFigures(uint32_t pattern=1){
    if(pattern == 0 || pattern == UINT_MAX){
        throw std::invalid_argument("Provide correct non zero integer, or less than UINT_MAX pattern value");
    }
    uint32_t decrement = 1; //convenient counter for substraction to get final result
    std::queue<std::pair<uint32_t,uint32_t>>storeCoordinates;
    uint32_t figurePattern = 1; //different than input pattern
    for(int row = 0; row < localStorage.size(); row++) {
        for(int col = 0; col < localStorage[0].size(); col++) {
            if(localStorage[row][col] == pattern) {
                figurePattern++;
                if(pattern==figurePattern){
                    figurePattern++;
                    decrement++;
                }
                //set current element with current figure pattern
                localStorage[row][col] = figurePattern;
                storeCoordinates.push({row,col});

                floodFill(storeCoordinates, localStorage, pattern, figurePattern);
            }
        }
    }
    return (figurePattern-decrement);
}
/*
    * displayMatrix() - show collected matrix
    */
void FindFigures::displayMatrix(){
    for(int i = 0; i < localStorage.size(); i++){
        for(int j = 0; j < localStorage[0].size(); j++){
            std::cout << localStorage[i][j] << " ";
        }
        std::cout << '\n';
    }
}

/*
    * floodFill()
    * This algorithm works by starting from a first pattern from witch figure is build and spreading outwards until the boundaries (no pattern) reached.
    */
void FindFigures::floodFill(std::queue<std::pair<uint32_t,uint32_t>>& coordinates, std::vector<std::vector<uint32_t>>&matrix, uint32_t initialPattern, uint32_t newPatterns){
    uint32_t qX = 0;
    uint32_t qY = 0;
    uint32_t x = 0;
    uint32_t y = 0;
    // Local navigation
    std::vector<std::pair<uint32_t,uint32_t>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//directions [right, left, up, down]
    while(!coordinates.empty()) {
        std::pair<uint32_t,uint32_t>front = coordinates.front();
        qX = front.first;
        qY = front.second;
        coordinates.pop();

        for(std::pair<uint32_t,uint32_t>& it : direction) {
            x = qX + it.first;
            y = qY + it.second;
            // Check boundary conditions
            if(x >=0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y] == initialPattern ){
                matrix[x][y] = newPatterns;
                coordinates.push({x, y});
            }
        }
    }
}
//Simple validation function for constructor
void FindFigures::matrixValidation() const {
    if(localStorage.empty() || localStorage[0].empty()){
        throw std::invalid_argument("Provided matrix cannot be empty.");
    }
}
