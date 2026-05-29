#include <iostream>
#include <fstream>
#include "../include/setting.hpp"
#include "../include/utils.hpp"

using namespace std;

Setting setting;

void initSetting() {
    setting.loadedFile = "database";
    setting.sortingAlgorithm = SortAlg::Bubble;
    setting.searchAlgorithm = SearchAlg::Selection;
}


void saveSettingAsFile() {
    MKDIR;
    ofstream File(".lnfdata/setting.txt");

    if (File.is_open()) {
        File << "loaded-file: " << setting.loadedFile << endl;
        File << "sorting-algorithm: " << setting.sortingAlgorithm << endl;
        File << "searching-algorithm: " << setting.searchAlgorithm;

        File.close();
    } else {
        cout << "Gagal membuat file." << endl;
    }
}

void loadSettingFromFile() {
    MKDIR;
    ifstream File(".lnfdata/setting.txt");

    if (File.is_open()) {
        string temp;

        getline(File, temp, ':');
        getline(File, setting.loadedFile);

        setting.loadedFile.erase(0, 1);

        getline(File, temp, ':');
        File >> (int&)setting.sortingAlgorithm;

        getline(File, temp);

        getline(File, temp, ':');
        File >> (int&)setting.searchAlgorithm;

        File.close();
    } else {
        initSetting();
        saveSettingAsFile();
    }
}