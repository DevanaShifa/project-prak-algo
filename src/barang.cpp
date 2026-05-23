#include <iostream>
#include <iomanip>
#include "barang.h"
#include "display.h"
#include "helper.h"

using namespace std;

int totalBarang = 0;
Barang dataBarang[100];

void inputBarang() {
    CLEAR_SCREEN;

    int jumlah;

    cout << setfill('-') << setw(90) << "" << endl;
    cout << setfill(' ') << setw(50) << "INPUT DATA" << endl;
    cout << setfill('-') << setw(90) << "" << endl;

    safeInput<int>("Banyak data yang ingin diinput: ", jumlah);

    for (int i = 0; i < jumlah; i++) {
        int hari, bulan, tahun;
        int jam, menit;
        cout << "\nData ke-" << totalBarang + 1 << endl;

        dataBarang[totalBarang].idBarang = totalBarang + 1;

        cout << "Nama Barang          : "; cin.getline(dataBarang[totalBarang].namaBarang, 50);
        cout << "Kategori             : "; cin.getline(dataBarang[totalBarang].kategori, 50);
        cout << "Deskripsi            : "; cin.getline(dataBarang[totalBarang].deskripsi, 100);
        cout << "Lokasi               : "; cin.getline(dataBarang[totalBarang].lokasi, 50);

        cout << endl << "Tanggal: " << endl;
        rangedInput<int>("- Hari (1-31)        : ", hari, 1, 31);
        rangedInput<int>("- Bulan (1-12)       : ", bulan, 1, 12);
        rangedInput<int>("- Tahun              : ", tahun, 2000, 9999);

        snprintf(dataBarang[totalBarang].tanggal, 50,
                "%d/%d/%d",
                hari,
                bulan,
                tahun
        );

        overwriteAbove(4);
        cout << "Tanggal              : " << dataBarang[totalBarang].tanggal << endl;

        cout << "Waktu: " << endl;
        rangedInput<int>("- Jam (0-23)         : ", jam, 0, 23);
        rangedInput<int>("- Menit (0-59)       : ", menit, 0, 59);

        snprintf(dataBarang[totalBarang].waktu, 50,
                "%02d:%02d",
                jam,
                menit
        );

        overwriteAbove(3);
        cout << "Waktu                : " << dataBarang[totalBarang].waktu << endl;

        totalBarang++;
    }
    cout << "\nData berhasil ditambahkan!\n";
}