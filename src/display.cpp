#include "../include/display.hpp"
#include "../include/barang.hpp"
#include "../include/utils.hpp"
#include "../include/setting.hpp"
#include "../include/sorting.hpp"
#include "../include/searching.hpp"
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

void showData(Barang arr[], int size) {
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

    for (int i = 0; i < size; i++)
    {
        if (arr[i].diKlaim) continue;
        cout << left
            << setw(4) << arr[i].idBarang
            << setw(18) << arr[i].namaBarang
            << setw(18) << arr[i].kategori
            << setw(18) << arr[i].lokasi
            << setw(18) << arr[i].tanggal
            << setw(14) << arr[i].waktu
            << endl;
    }
    cout << setfill('-') << setw(90) << "" << endl;
}

void showSearch() {
    char search[50];
    Barang dataBarangSearch[100];
    int totalBarangSearch = 0;

    overwriteAbove(1);
    cout << "Search: "; cin.getline(search, 50);
    sequentialSearch(dataBarang, dataBarangSearch, totalBarang, totalBarangSearch, search);

    CLEAR_SCREEN;
    showData(dataBarangSearch, totalBarangSearch);

    cout << "Tekan enter untuk melanjutkan...";
    cin.get();
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
    safeInput("> ", sort);

    switch (sort)
    {
    case 1:
        handleSortData(dataBarang, totalBarang, [](const Barang& a, const Barang& b) {
            return a.idBarang > b.idBarang;
        });
        break;
    case 2:
        handleSortData(dataBarang, totalBarang, [](const Barang& a, const Barang& b) {
            return a.namaBarang[0] > b.namaBarang[0];
        });
        break;
    case 3:
        handleSortData(dataBarang, totalBarang, [](const Barang& a, const Barang& b) {
            return a.kategori[0] > b.kategori[0];
        });
        break;
    case 4:
        handleSortData(dataBarang, totalBarang, [](const Barang& a, const Barang& b) {
            return a.lokasi[0] > b.lokasi[0];
        });
        break;
    case 5:
        handleSortData(dataBarang, totalBarang, [](const Barang& a, const Barang& b) {
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

    cout << "Data berhasil di simpan..." << endl;
    cin.ignore();
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

    cout << "Data berhasil di load..." << endl;

    cin.ignore();
    cin.get();
}

void selectSortAlg() {
    int sorting;

    do
    {
        CLEAR_SCREEN;
        cout << "Ubah algoritma sorting" << endl;
        cout << setfill('-') << setw(90) << "" << endl;
        cout << " 1. BUBBLE SORT           " << endl;
        cout << " 2. SELECTION SORT        " << endl;
        cout << " 3. INSERTION SORT        " << endl;
        cout << " 4. SHELL SORT            " << endl;
        cout << " 0. Batal                " << endl;

        cout << setfill('-') << setw(90) << "" << endl;
        safeInput("Pilih: ", sorting);

        switch (sorting)
        {
        case 1:
            setting.sortingAlgorithm = SortAlg::Bubble;
            return;
        case 2:
            setting.sortingAlgorithm = SortAlg::Selection;
            return;
        case 3:
            setting.sortingAlgorithm = SortAlg::Insertion;
            return;
        case 4:
            setting.sortingAlgorithm = SortAlg::Shell;
            return;
        case 0:
            return;
        
        default:
            cout << "Pilihan tidak ada!" << endl;
            cout << "Tekan enter untuk melanjutkan...";
            cin.get();
            break;
        }
    } while (sorting != 0);
}

void showSettings() {
    int menu;

    do
    {
        CLEAR_SCREEN;
        cout << "Pengaturan" << endl;
        cout << " - File                : " << setting.loadedFile << endl
             << " - Algoritma Sorting   : " << toString(setting.sortingAlgorithm) << endl;
        cout << setfill('-') << setw(90) << "" << endl;
        cout << "1. Save" << endl
             << "2. Load" << endl
             << "3. Ubah algoritma sorting" << endl
             << "0. Back" << endl;
        cout << setfill('-') << setw(90) << "" << endl;
        safeInput("> ", menu);
    
        switch (menu)
        {
        case 1:
            showSaveSetting();
            break;
        case 2:
            showLoadSetting();
            break;
        case 3:
            selectSortAlg();
            saveSettingAsFile();
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