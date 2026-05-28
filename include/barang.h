#pragma once

struct Barang {
    int idBarang;
    char namaBarang[50];
    char kategori[50];
    char deskripsi[50];
    char lokasi[50];
    char tanggal[50];
    char waktu[50];
};

extern int totalBarang;
extern Barang dataBarang[100];

void inputBarang();
void pilihBarang();