#pragma once
#include <iostream>
#include "sorting.hpp"

enum SortAlg {
    Bubble,
    Selection
};

enum SearchAlg {
    Sequential,
    Binary
};

struct Setting {
    std::string loadedFile;
    SortAlg sortingAlgorithm;
    SearchAlg searchAlgorithm;
};

extern Setting setting;

void initSetting();

void saveSettingAsFile();
void loadSettingFromFile();

void selectSortData(Barang arr[], int size, LCompare cmp);