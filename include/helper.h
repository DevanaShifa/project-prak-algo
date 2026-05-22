#pragma once
#include <iostream>
#include <sstream>
using namespace std;

/**
 * menimpa baris sebelumnya
 * @param jump jumlah baris yang akan ditimpa
 */
void overwriteAbove(int jump);

/**
 * validasi input agar program tidak error ketika tipe data tidak sesuai
 * @param msg pesan output yang ditampilkan
 * @param value variabel penyimpan input
 */
template<typename T>
void safeInput(const string& msg, T& value) {
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

/**
 * memastikan input harus berada di range tertentu
 * @param msg pesan output yang ditampilkan
 * @param value variabel penyimpan input
 * @param min nilai minimum
 * @param max nilai maksimum
 */
template<typename T>
void rangedInput(
    const string& msg,
    T& value,
    T min,
    T max
) {
    string input;

    while (true)
    {
        cout << msg;
        getline(cin, input);
        stringstream ss(input);

        if (!(ss >> value)) {
            cout << "Tipe data tidak valid!\n";
            continue;
        }

        if (value < min) {
            cout << "Nilai harus >= " << min << "!\n";
            continue;
        }
        if (value > max) {
            cout << "Nilai harus <= " << max << "!\n";
            continue;
        }
        return;
    }
}