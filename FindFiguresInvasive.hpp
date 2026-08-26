#pragma once

#include <vector>
#include <queue>
#include <cstdint>
#include "IFindFiguresSwitch.hpp"

class FindFiguresInvasive : public IFindFiguresSwitch {
    std::vector<std::vector<int>> localStorage;
public:
    explicit FindFiguresInvasive(std::vector<std::vector<int>> out);

    FindFiguresInvasive(const FindFiguresInvasive&)=delete;
    FindFiguresInvasive& operator=(const FindFiguresInvasive&) = delete;
    FindFiguresInvasive(FindFiguresInvasive&&) = delete;
    FindFiguresInvasive& operator=(FindFiguresInvasive&&) = delete;


    uint32_t findFigures(int pattern) override;
    void displayMatrix();

private:
    void floodFill(std::queue<std::pair<int,int>>& coordinates, std::vector<std::vector<int>>&matrix,
                   const int patternToSearch, int newPattern);

    void matrixValidation() const;
};

