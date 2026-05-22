#pragma once
#include <iostream>
#include <sstream>
using namespace std;

/**
 * validasi input agar program tidak error ketika tipe data tidak sesuai
 * @param msg pesan output yang ditampilkan
 * @param value variabel penyimpan input
 */
template<typename T>
void safeInput(string msg, T& value) {
    string input;

    while (true)
    {
        cout << msg;

        getline(cin, input);

        stringstream ss(input);

        if (ss >> value) {
            return;
        }

        cout << "Tipedata tidak valid!\n";
    }
}