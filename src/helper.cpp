#include <iostream>
#include <sstream>
#include "helper.h"
using namespace std;

/**
 * validasi input agar program tidak error ketika tipe data tidak sesuai
 * @param msg pesan input yang ditampilkan
 * @param output nilai int yang telah di konversi dari `input`
 */
void inputAngka(string msg, int& output) {
    string input;

    while (true)
    {
        cout << msg;

        getline(cin, input);

        stringstream ss(input);

        if (ss >> output) {
            return;
        }

        cout << "Input harus angka!\n";
    }
}