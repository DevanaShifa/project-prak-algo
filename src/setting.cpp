#include "../include/setting.hpp"
#include "../include/utils.hpp"
#include "../include/barang.hpp"
#include "../include/sorting.hpp"
#include <iostream>
#include <fstream>

using namespace std;

Setting setting;

void initSetting() {
    setting.loadedFile = "database";
    setting.sortingAlgorithm = SortAlg::Bubble;
}


void saveSettingAsFile() {
    ofstream File(".lnfdata/setting.txt");

    if (File.is_open()) {
        File << "loaded-file: " << setting.loadedFile << endl;
        File << "sorting-algorithm: " << setting.sortingAlgorithm;

        File.close();
    } else {
        cout << "Gagal membuat file." << endl;
    }
}

void loadSettingFromFile() {
    ifstream File(".lnfdata/setting.txt");

    if (File.is_open()) {
        string temp;

        getline(File, temp, ':');
        getline(File, setting.loadedFile);

        setting.loadedFile.erase(0, 1);

        getline(File, temp, ':');
        File >> (int&)setting.sortingAlgorithm;

        File.close();
    } else {
        initSetting();
        saveSettingAsFile();
    }
}

void handleSortData(Barang arr[], int size, LCompare cmp) {
    switch (setting.sortingAlgorithm) {
        case Bubble:
            bubbleSort(arr, size, cmp);
            break;

        case Selection:
            selectionSort(arr, size, cmp);
            break;

        case Insertion:
            insertionSort(arr, size, cmp);
            break;

        case Shell:
            shellSort(arr, size, cmp);
            break;
    }
}