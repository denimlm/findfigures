#pragma once

#include <vector>
#include <queue>
#include <cstdint>
#include <climits>
#include <set>

class FindFigures {
    std::vector<std::vector<uint32_t>> localStorage;
public:
    explicit FindFigures(std::vector<std::vector<uint32_t>>&out);

    FindFigures(const FindFigures&)=delete;
    FindFigures& operator=(const FindFigures&) = delete;
    FindFigures(FindFigures&&) = delete;
    FindFigures& operator=(FindFigures&&) = delete;

    uint32_t findFigures(uint32_t pattern);

    void displayMatrix();

private:

   /*
    * floodFill()
    * This algorithm works by starting from a first pattern from witch figure is build and spreading outwards until the boundaries (no pattern) reached.
    * This algorithm works by starting from a first pattern from witch figure is build and spreading outwards until the boundaries (no pattern) reached.
    * param[in] - coordinates - current coordinates identified with pattern
    * param[in] - matrix - matrix elements contain figures drawn with patterns
    * param[in] - covered - contain alredy visited indexes from matrix
    * param[in] - initialPattern - pattern contain figures
    */
    void floodFill(std::queue<std::pair<uint32_t,uint32_t>>& coordinates, const std::vector<std::vector<uint32_t>>&matrix, std::set<std::pair<uint32_t,uint32_t>>&covered, const uint32_t initialPattern);

    void matrixValidation() const;
};
