#include "../include/display.hpp"
#include "../include/barang.hpp"
#include "../include/utils.hpp"
#include "../include/setting.hpp"
#include "../include/sorting.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

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

void showHint() {
    cout << "Hint:" << endl;
    cout << setfill(' ');
    cout << left
        << setw(30) << "[1] Pilih Barang"
        << setw(30) << "[3] Sort Barang"
        << setw(30) << "[5] Pengaturan"
        << endl
        << setw(30) << "[2] Buat Laporan"
        << setw(30) << "[4] Cari Barang"
        << setw(30) << "[0] Kembali/Keluar"
        << endl;
    cout << setfill('-') << setw(90) << "" << endl;
}

void showData() {
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

void showSort() {
    int sort;

    overwriteAbove(5);
    cout << "Sort Berdasarkan:" << endl;
    cout << setfill(' ');
    cout << left
        << setw(30) << "(1) ID"
        << setw(30) << "(3) Kategori"
        << setw(30) << "(5) Tanggal"
        << endl
        << setw(30) << "(2) Nama Barang"
        << setw(30) << "(4) Lokasi"
        << setw(30) << "(0) Kembali"
        << endl;
    cout << setfill('-') << setw(90) << "" << endl;
    safeInput<int>("> ", sort);

    switch (sort)
    {
    case 1:
        selectSortData(dataBarang, totalBarang, [](const Barang& a, const Barang& b) {
            return a.idBarang > b.idBarang;
        });
        break;
    case 2:
        selectSortData(dataBarang, totalBarang, [](const Barang& a, const Barang& b) {
            return a.namaBarang[0] > b.namaBarang[0];
        });
        break;
    case 3:
        selectSortData(dataBarang, totalBarang, [](const Barang& a, const Barang& b) {
            return a.kategori[0] > b.kategori[0];
        });
        break;
    case 4:
        selectSortData(dataBarang, totalBarang, [](const Barang& a, const Barang& b) {
            return a.lokasi[0] > b.lokasi[0];
        });
        break;
    case 5:
        selectSortData(dataBarang, totalBarang, [](const Barang& a, const Barang& b) {
            return a.tanggal[0] > b.tanggal[0];
        });
        break;
        
    case 0:
        break;
    
    default:
        cout << "Menu tidak valid!" << endl;
        cout << "> ";
        break;
    }
}

void showSaveSetting() {
    string fileName;

    overwriteAbove(1);
    cout << "Save" << endl;
    cout << setfill('-') << setw(90) << "" << endl;
    cout << "Nama file: "; cin >> fileName;
    saveBarangAsFile(fileName);

    setting.loadedFile = fileName;
    saveSettingAsFile();

    cout << "\nData berhasil di simpan..." << endl;
    cin.get();
}

void showLoadSetting() {
    string fileName;

    overwriteAbove(1);
    cout << "Load" << endl;
    cout << setfill('-') << setw(90) << "" << endl;
    cout << "Nama file: "; cin >> fileName;
    loadBarangFromFile(fileName);

    setting.loadedFile = fileName;
    saveSettingAsFile();

    cin.get();
}

void showSettings() {
    int menu;

    do
    {
        CLEAR_SCREEN;
        cout << "Settings" << endl;
        cout << setfill('-') << setw(90) << "" << endl;
        cout << "1. Save" << endl
             << "2. Load" << endl
             << "3. Ubah algoritma sorting" << endl
             << "4. Ubah algoritma searching" << endl
             << "0. Back" << endl;
        cout << setfill('-') << setw(90) << "" << endl;
        safeInput<int>("> ", menu);
    
        switch (menu)
        {
        case 1:
            showSaveSetting();
            break;
        case 2:
            showLoadSetting();
            break;
        case 0:
            break;
        
        default:
            cout << "Pilihan tidak ada!" << endl;
            cout << "Tekan enter untuk melanjutkan...";
            cin.get();
            break;
        }
    } while (menu != 0);
}