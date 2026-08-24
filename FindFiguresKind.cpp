#include "FindFiguresKind.hpp"
#include <stdexcept>

FindFiguresKind::FindFiguresKind(std::unique_ptr<IFindFiguresSwitch> strategy, int patternToSearch)
        :findKind(std::move(strategy)), pattern(patternToSearch) {}

void FindFiguresKind::setStrategy(std::unique_ptr<IFindFiguresSwitch> selected, int patternToSearch) {
    findKind = std::move(selected);
    if(findKind)
        pattern = patternToSearch;
}

void FindFiguresKind::showMatrix(){
    if(findKind) {
        findKind->displayMatrix();
    }
}

uint32_t FindFiguresKind::execute(){
    if(!findKind){
        throw std::runtime_error("Critical error in FindFiguresKind: nullptr.");
    }
    return findKind->findFigures(pattern);
}

