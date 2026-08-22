#include "FindFigures.hpp"
#include <iostream>
#include <set>

FindFigures::FindFigures(std::vector<std::vector<uint32_t>>&out):localStorage{std::move(out)}{
    matrixValidation();
}
/* findFigures()
* Search for provided patterns
* return number of figures found
*/
uint32_t FindFigures::findFigures(uint32_t pattern=1){
    if(pattern == 0){
        throw std::invalid_argument("Provide correct non zero integer pattern value.");
    }
    std::queue<std::pair<uint32_t,uint32_t>>storeCoordinates;
    std::set<std::pair<uint32_t, uint32_t>> visited;
    uint32_t figurePattern = 0; //different than input pattern
    for(int row = 0; row < localStorage.size(); row++) {
        for(int col = 0; col < localStorage[0].size(); col++) {
            if(localStorage[row][col] == pattern) {
                if(visited.find({row,col})==visited.end()){
                    figurePattern++;
                }
                visited.insert({row,col}); //Global visited
                storeCoordinates.push({row,col}); //Local visited

                floodFill(storeCoordinates, localStorage, visited, pattern);
            }
        }
    }
    return figurePattern;
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
* param[in] - coordinates - current coordinates identified with pattern
* param[in] - matrix - matrix elements contain figures drawn with patterns
* param[in] - covered - contain alredy visited indexes from matrix
* param[in] - initialPattern - pattern contain figures
*/
void FindFigures::floodFill(std::queue<std::pair<uint32_t,uint32_t>>& coordinates, const std::vector<std::vector<uint32_t>>&matrix,
                            std::set<std::pair<uint32_t,uint32_t>>&covered, const uint32_t initialPattern) {
    uint32_t qX = 0;
    uint32_t qY = 0;
    uint32_t x = 0;
    uint32_t y = 0;
    // Local navigation
    std::vector<std::pair<uint32_t,uint32_t>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//directions [right, left, down, up]

    while(!coordinates.empty()) {
        std::pair<uint32_t,uint32_t>front = coordinates.front();
        qX = front.first;
        qY = front.second;
        coordinates.pop();
        covered.insert({qX,qY});
        for(std::pair<uint32_t,uint32_t>& it : direction) {
            x = qX + it.first;
            y = qY + it.second;
            // Check boundary conditions
            if(x >=0 && x < matrix.size() && y >= 0 && y < matrix[0].size() &&
                matrix[x][y] == initialPattern && (covered.find({x,y})==covered.end()) ) {
                covered.insert({x,y});
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
