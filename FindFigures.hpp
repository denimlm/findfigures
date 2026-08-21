#pragma once

#include <vector>
#include <queue>

class FindFigures {
    std::vector<std::vector<int>> localStorage;
public:
    explicit FindFigures(std::vector<std::vector<int>>&out);

    FindFigures(const FindFigures&)=delete;
    FindFigures& operator=(const FindFigures&) = delete;
    FindFigures(FindFigures&&) = delete;
    FindFigures& operator=(FindFigures&&) = delete;

    int findFigures(int pattern);

    void displayMatrix();

private:
    /*
        The Flood Filling Algorithm fills the internal region which is bounded by pixels with different colors.
        This algorithm works by starting from a point inside the polygon and spreading outwards until the boundaries are reached.
        A 4-Connected Flood Fill will be used for this class
     */
    void floodFill(std::queue<std::pair<int,int>>& coordinates, std::vector<std::vector<int>>&matrix, int initialPattern, int newPatterns);

    void matrixValidation() const;
};
