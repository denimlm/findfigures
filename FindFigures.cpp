#include "FindFigures.hpp"
#include <iostream>
#include <set>

/*
 * Constructor with validation of provided resource
 */
FindFigures::FindFigures(std::vector<std::vector<int>>&out):localStorage{std::move(out)}{
    matrixValidation();
}
/*
* findFigures()
* Main method for searching of figures in matrix
* param[in] - pattern - uint32_t pattern to search
* return figuresFound
*/
uint32_t FindFigures::findFigures(int pattern=1){
    if(pattern == 0){
        throw std::invalid_argument("Provide correct non zero integer pattern value.");
    }
    std::queue<std::pair<int,int>>storeCoordinates;
    std::set<std::pair<int, int>> visited;
    uint32_t figuresFound = 0; //different than input pattern
    for(int row = 0; row < localStorage.size(); row++) {
        for(int col = 0; col < localStorage[0].size(); col++) {
            if(localStorage[row][col] == pattern) {
                if(visited.find({row,col})==visited.end()){
                    figuresFound++;
                }
                visited.insert({row,col}); //Global visited
                storeCoordinates.push({row,col}); //Local visited

                floodFill(storeCoordinates, localStorage, visited, pattern);
            }
        }
    }
    return figuresFound;
}

/*
* displayMatrix()
* Show matrix content on the screen
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
* param[in] - patternToSearch - pattern sustain figures
*/
void FindFigures::floodFill(std::queue<std::pair<int,int>>& coordinates, const std::vector<std::vector<int>>&matrix,
                            std::set<std::pair<int,int>>&covered, const int patternToSearch) {
    uint32_t qX = 0;
    uint32_t qY = 0;
    uint32_t x = 0;
    uint32_t y = 0;
    // Local navigation
    std::vector<std::pair<int,int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//directions [right, left, down, up]

    while(!coordinates.empty()) {
        std::pair<int,int>front = coordinates.front();
        qX = front.first;
        qY = front.second;
        coordinates.pop();
        for(std::pair<int,int>& it : direction) {
            x = qX + it.first;
            y = qY + it.second;
            // Check boundary conditions
            if(x >=0 && x < matrix.size() && y >= 0 && y < matrix[0].size() &&
                matrix[x][y] == patternToSearch && (covered.find({x,y}) == covered.end()) ) {
                covered.insert({x,y});
                coordinates.push({x, y});
            }
        }
    }
}
/*
* matrixValidation()
* Check boundary conditions for provided matrix
* May throw an error
*/
void FindFigures::matrixValidation() const {
    if(localStorage.empty() || localStorage[0].empty()){
        throw std::invalid_argument("Provided matrix cannot be empty.");
    }
}
