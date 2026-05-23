#include <iostream>
#include <iomanip>
#include "display.h"
#include "barang.h"
#include "helper.h"
using namespace std;

void tampilHint() {
    cout << "Hint:" << endl;
    cout << setfill(' ');
    cout << left
        << setw(30) << "[1] Pilih Barang"
        << setw(30) << "[3] Cari Barang"
        << setw(30) << "[5] Pengaturan"
        << endl
        << setw(30) << "[2] Buat Laporan"
        << setw(30) << "[4] Sort Barang"
        << setw(30) << "[0] Kembali/Keluar"
        << endl;
    cout << setfill('-') << setw(90) << "" << endl;
}

void tampilData() {
    cout << setfill('-') << setw(90) << "" << endl;

    cout << setfill(' ');
    cout << left
        << setw(4) << "ID"
        << setw(18) << "NAMA BARANG"
        << setw(18) << "KATEGORI"
        << setw(18) << "LOKASI"
        << setw(18) << "TANGGAL"
        << setw(14) << "WAKTU"
        << endl;
    cout << setfill('-') << setw(90) << "" << endl;
    cout << setfill(' ');

    for (int i = 0; i < totalBarang; i++)
    {
        cout << left
            << setw(4) << dataBarang[i].idBarang
            << setw(18) << dataBarang[i].namaBarang
            << setw(18) << dataBarang[i].kategori
            << setw(18) << dataBarang[i].lokasi
            << setw(18) << dataBarang[i].tanggal
            << setw(14) << dataBarang[i].waktu
            << endl;
    }
    cout << setfill('-') << setw(90) << "" << endl;
}