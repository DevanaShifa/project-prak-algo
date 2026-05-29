#include <iostream>
#include "setting.h"

Setting setting;

void initSetting() {
    setting.loadedFile = "database";
    setting.sortingAlgorithm = SortAlg::Bubble;
    setting.searchAlgorithm = SearchAlg::Selection;
}