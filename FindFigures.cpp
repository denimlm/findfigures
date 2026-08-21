#include "FindFigures.hpp"
#include <iostream>

    FindFigures::FindFigures(std::vector<std::vector<int>>&out):localStorage{std::move(out)}{
        matrixValidation();
    }
   /* findFigures()
    * Search for provided patterns
    * return number of figures found
    */
    int FindFigures::findFigures(int pattern=1){
        std::queue<std::pair<int,int>>lQ;
        int figurePattern = 1;
        for(int row = 0; row < localStorage.size(); row++) {
            for(int col = 0; col < localStorage[0].size(); col++) {
                if(localStorage[row][col] == pattern) {
                    figurePattern++;
                    //set current element with current figure pattern
                    localStorage[row][col] = figurePattern;
                    lQ.push({row,col});

                    floodFill(lQ, localStorage, pattern, figurePattern);
                }
            }
        }
        return (figurePattern-1);
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
    void FindFigures::floodFill(std::queue<std::pair<int,int>>& coordinates, std::vector<std::vector<int>>&matrix, int initialPattern, int newPatterns){
        std::vector<std::pair<int,int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!coordinates.empty()) {
            std::pair<int,int>front = coordinates.front();
            int qX = front.first;
            int qY = front.second;
            coordinates.pop();

            for(std::pair<int,int>& it : direction) {
                int x = qX + it.first;
                int y = qY + it.second;
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
