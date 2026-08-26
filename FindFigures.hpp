#pragma once

#include <vector>
#include <queue>
#include <cstdint>
#include "IFindFiguresSwitch.hpp"

class FindFigures : public IFindFiguresSwitch {
    std::vector<std::vector<int>> localStorage;
public:
    explicit FindFigures(std::vector<std::vector<int>>out);

    FindFigures(const FindFigures&)=delete;
    FindFigures& operator=(const FindFigures&) = delete;
    FindFigures(FindFigures&&) = delete;
    FindFigures& operator=(FindFigures&&) = delete;


    uint32_t findFigures(int pattern) override;
    void displayMatrix();

private:
    void floodFill(std::queue<std::pair<int,int>>& coordinates, const std::vector<std::vector<int>>&matrix,
                   std::vector<std::vector<bool>>&covered, const int patternToSearch);

    void matrixValidation() const;
};
