#include <iostream>
#include <fstream>
#include "helper.h"
#include "barang.h"

#define MKDIR system("mkdir database")

void showTitle() {
std::cout << 
R"(
 _              _             _____                     _ 
| |    ___  ___| |_   _ __   |  ___|__  _   _ _ __   __| |
| |   / _ \/ __| __| | '_ \  | |_ / _ \| | | | '_ \ / _` |
| |__| (_) \__ \ |_  | | | | |  _| (_) | |_| | | | | (_| |
|_____\___/|___/\__| |_| |_| |_|  \___/ \__,_|_| |_|\__,_|
)" << endl;
}

void overwriteAbove(int jump) {
    for (int i = 0; i < jump; i++) {
        std::cout << "\033[A";
        std::cout << "\033[2K";
    }

    std::cout << "\r";
}

void saveBarangAsFile(const string& name) {
    MKDIR;
    ofstream File("database/"+name, ios::binary);

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

void readBarangFromFile(const string& name) {
    MKDIR;
    ifstream File("database/"+name);

    if (File.is_open()) {
        File.read(
            reinterpret_cast<char*>(&totalBarang),
            sizeof(totalBarang)
        );

        File.read(
            reinterpret_cast<char*>(dataBarang),
            sizeof(Barang) * totalBarang
        );

        File.close();
    } else {
        cout << "Gagal membaca file." << endl;
    }
}
