#pragma once
#include <iostream>

enum SortAlg {
    Bubble,
    Insertion
};

enum SearchAlg {
    Selection,
    Binary
};

struct Setting {
    std::string loadedFile;
    SortAlg sortingAlgorithm;
    SearchAlg searchAlgorithm;
};

extern Setting setting;

void initSetting();