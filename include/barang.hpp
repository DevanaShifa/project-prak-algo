#pragma once
#include <iostream>
using namespace std;

struct Barang {
    int idBarang;
    char namaBarang[50];
    char kategori[50];
    char deskripsi[50];
    char lokasi[50];
    char tanggal[50];
    char waktu[50];
    bool diKlaim;
};

struct Klaim {
    int idBarang;
    char namaPengambil[50];
    char tanggalKlaim[50];
    char waktuKlaim[50];
};

extern int totalBarang;
extern Barang dataBarang[256];

void inputBarang();
void pilihBarang();

void saveBarangAsFile(const std::string& name);
void loadBarangFromFile(const std::string& name);