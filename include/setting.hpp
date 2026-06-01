#pragma once
#include <iostream>

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

template<typename T, typename Compare>
void sortData(T arr[], int size, Compare cmp) {
    switch (setting.sortingAlgorithm) {
        case Bubble:
            bubbleSort(arr, size, cmp);
            break;

        case Selection:
            selectionSort(arr, size, cmp);
            break;
    }
}