#include "../include/barang.hpp"
#include "../include/utils.hpp"
#include "../include/setting.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int totalBarang = 0;
Barang dataBarang[256];


void saveBarangAsFile(const string& name) {
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
        
        File.close();
    } else {
        cout << "File tidak ditemukan." << endl;
        cout << "Tekan enter untuk melanjutkan...";
        cin.get();
    }
}

void saveKlaimAsFile(Klaim klaim) {
    string fileName = "print/data-"+string(klaim.namaPengambil)+"-"+to_string(klaim.idBarang);
    ofstream File(fileName+".txt");

    if (File.is_open()) {
        File << "========================== Lost & Found ==========================" << endl;
        File << "Nama Pengambil : " << klaim.namaPengambil << endl;
        File << "Tanggal Klaim  : " << klaim.tanggalKlaim << endl;
        File << "Waktu Klaim    : " << klaim.waktuKlaim << endl << endl;

        File << "Id Barang      : " << klaim.idBarang << endl;
        File << "Nama Barang    : " << dataBarang[klaim.idBarang].namaBarang << endl;
        File << "Deskripsi      : " << dataBarang[klaim.idBarang].deskripsi << endl;
        File << "========================== Lost & Found ==========================" << endl;
        File.close();
    }
}

void klaimBarang(int idx) {
    Klaim klaim;
    int hari, bulan, tahun, jam, menit;

    cout << "Nama penerima: ";
    cin.getline(klaim.namaPengambil, 50);
    
    cout << endl << "Tanggal: " << endl;
    rangedInput("- Hari (1-31)        : ", hari, 1, 31);
    rangedInput("- Bulan (1-12)       : ", bulan, 1, 12);
    rangedInput("- Tahun              : ", tahun, 2000, 9999);

    snprintf(klaim.tanggalKlaim, 50,
            "%d/%d/%d",
            hari,
            bulan,
            tahun
    );

    overwriteAbove(4);

    cout << "Tanggal              : " << klaim.tanggalKlaim << endl;

    cout << "Waktu: " << endl;
    rangedInput("- Jam (0-23)         : ", jam, 0, 23);
    rangedInput("- Menit (0-59)       : ", menit, 0, 59);

    snprintf(klaim.waktuKlaim, 50,
            "%02d:%02d",
            jam,
            menit
    );

    overwriteAbove(3);
    cout << "Waktu                : " << klaim.waktuKlaim << endl;

    
    saveKlaimAsFile(klaim);
    saveBarangAsFile(setting.loadedFile);
    dataBarang[idx].diKlaim = true;

    cout << setfill('-') << setw(90) << "" << endl;
    cout << "Laporan klaim barang di simpan ke 'print/data" << dataBarang[idx].idBarang << ".txt'" << endl;
    cin.get();
}

void pilihBarang() {
    int menu;

    int idx;
    overwriteAbove(1);
    rangedInput("Pilih Id Barang: ", idx, 1, totalBarang);

    Barang *barangDipilih = nullptr;

    for (int i = 0; i < totalBarang; i++)
    {
        if (dataBarang[i].idBarang != idx) continue;
        else if (dataBarang[i].diKlaim) {
            cout << "Barang sudah diklaim.";
            cin.get();
            return;
        } else {
            barangDipilih = &dataBarang[i];
        }
    }
    

    CLEAR_SCREEN;

    cout << "Id Barang          : " <<  barangDipilih->idBarang << endl;
    cout << "Nama Barang        : " <<  barangDipilih->namaBarang << endl;
    cout << "Nama Barang        : " <<  barangDipilih->namaBarang << endl;
    cout << "Deskripsi          : " <<  barangDipilih->deskripsi << endl;
    cout << "Lokasi             : " <<  barangDipilih->lokasi << endl;
    cout << "Tanggal            : " <<  barangDipilih->tanggal << endl;
    cout << "Waktu              : " <<  barangDipilih->waktu << endl;

    cout << setfill('-') << setw(90) << "" << endl;
    cout << "1. Klaim Barang" << endl;
    cout << "0. Keluar" << endl;
    cout << setfill('-') << setw(90) << "" << endl;
    safeInput("Pilih: ", menu);

    if (menu == 1) {
        klaimBarang(idx-1);
    }
}

void inputBarang() {
    CLEAR_SCREEN;

    int jumlah;

    cout << setfill('-') << setw(90) << "" << endl;
    cout << setfill(' ') << setw(50) << "INPUT DATA" << endl;
    cout << setfill('-') << setw(90) << "" << endl;

    safeInput("Banyak data yang ingin diinput: ", jumlah);

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
        rangedInput("- Hari (1-31)        : ", hari, 1, 31);
        rangedInput("- Bulan (1-12)       : ", bulan, 1, 12);
        rangedInput("- Tahun              : ", tahun, 2000, 9999);

        snprintf(dataBarang[totalBarang].tanggal, 50,
                "%d/%d/%d",
                hari,
                bulan,
                tahun
        );

        overwriteAbove(4);
        cout << "Tanggal              : " << dataBarang[totalBarang].tanggal << endl;

        cout << "Waktu: " << endl;
        rangedInput("- Jam (0-23)         : ", jam, 0, 23);
        rangedInput("- Menit (0-59)       : ", menit, 0, 59);

        snprintf(dataBarang[totalBarang].waktu, 50,
                "%02d:%02d",
                jam,
                menit
        );

        overwriteAbove(3);
        cout << "Waktu                : " << dataBarang[totalBarang].waktu << endl;

        totalBarang++;
    }

    saveBarangAsFile(setting.loadedFile);
    cout << "\nData berhasil ditambahkan!\n";
}
