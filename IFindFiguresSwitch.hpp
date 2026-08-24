#pragma once
/* Use strategy pattern */
#include <cstdint>

class IFindFiguresSwitch {
public:
    virtual ~IFindFiguresSwitch() = default;
    virtual uint32_t findFigures(int pattern)=0;

    virtual void displayMatrix() = 0;
};
