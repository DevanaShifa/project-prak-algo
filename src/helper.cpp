#include <iostream>
#include <fstream>
#include "helper.h"
#include "barang.h"
#include "setting.h"

#define MKDIR system("mkdir -p .lnfdata")

void overwriteAbove(int jump) {
    for (int i = 0; i < jump; i++) {
        std::cout << "\033[A";
        std::cout << "\033[2K";
    }

    std::cout << "\r";
}

void saveBarangAsFile(const string& name) {
    MKDIR;
    ofstream File(".lnfdata/"+name, ios::binary);

    if (File.is_open()) {
        File.write(
            reinterpret_cast<char*>(&totalBarang),
            sizeof(totalBarang)
        );

        File.write(
            reinterpret_cast<char*>(dataBarang),
            sizeof(Barang) * totalBarang
        );

        File.close();
    } else {
        cout << "Gagal membuat file." << endl;
    }
}

void loadBarangFromFile(const string& name) {
    MKDIR;
    ifstream File(".lnfdata/"+name);

    if (File.is_open()) {
        File.read(
            reinterpret_cast<char*>(&totalBarang),
            sizeof(totalBarang)
        );

        File.read(
            reinterpret_cast<char*>(dataBarang),
            sizeof(Barang) * totalBarang
        );

        cout << "\nData berhasil di muat..." << endl;
        File.close();
    } else {
        cout << "File tidak ditemukan." << endl;
        cout << "Tekan enter untuk melanjutkan...";
        cin.get();
    }
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