#pragma once
#include <iostream>
#include "sorting.hpp"
#include "barang.hpp"

enum SortAlg {
    Bubble,
    Selection,
    Insertion,
    Shell,
};

struct Setting {
    std::string loadedFile;
    SortAlg sortingAlgorithm;
};

extern Setting setting;

void initSetting();

void saveSettingAsFile();
void loadSettingFromFile();

void selectSortAlg();

void handleSortData(Barang arr[], int size, LCompare cmp);