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
    void floodFill(std::queue<std::pair<uint32_t,uint32_t>>& coordinates, const std::vector<std::vector<uint32_t>>&matrix,
                   std::set<std::pair<uint32_t,uint32_t>>&covered, const uint32_t initialPattern);

    void matrixValidation() const;
};
