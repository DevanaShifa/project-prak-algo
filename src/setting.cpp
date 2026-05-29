#include <iostream>
#include "setting.hpp"

Setting setting;

void initSetting() {
    setting.loadedFile = "database";
    setting.sortingAlgorithm = SortAlg::Bubble;
    setting.searchAlgorithm = SearchAlg::Selection;
}