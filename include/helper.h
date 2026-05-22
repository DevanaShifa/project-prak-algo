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
void safeInput(const string msg, T& value) {
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
 * @param max nilai maximum
 */
template<typename T>
void rangedInput(
    const string msg, 
    T& value, 
    int min,
    int max
) {
    string input;

    while (true)
    {
        cout << msg;

        getline(cin, input);

        if (input < min) {
            cout << "Nilai harus lebih dari " << min;
        } else if (input > max) {
            cout << "Nilai harus kurang dari " << max;
        } else {
            stringstream ss(input);
            if (ss >> value) {
                return;
            }
    
            cout << "Tipedata tidak valid!\n";
        }
    }
}