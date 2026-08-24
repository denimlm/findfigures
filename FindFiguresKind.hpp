#pragma once
/* FindFiguresKind to utilize strategy of changing search algorithms from non invasive to invasive (matrix change) */
#include <memory>
#include <cstdint>
#include "IFindFiguresSwitch.hpp"

class FindFiguresKind {
private:
    std::unique_ptr<IFindFiguresSwitch> findKind;
    int pattern;

public:
    explicit FindFiguresKind(std::unique_ptr<IFindFiguresSwitch> strategy, int patternToSearch);

    void setStrategy(std::unique_ptr<IFindFiguresSwitch> selected, int patternToSearch);

    void showMatrix();

    uint32_t execute();
};
