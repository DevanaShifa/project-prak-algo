#include<iostream>
#include<iomanip>
using namespace std;

struct Barang{
    string nama;
    string loc;
    string tanggal;
};

Barang brg[100];
int n = 0;

void inputDataBarang(){
    int n;
    cout << endl << "===== INPUT DATA BARANG ====="<< endl;
    cout << "Jumlah Barang : ";
    cin >> n; cout << endl;
    cin.ignore();

    for(int i=0; i<n; i++){
        cout << "\nData ke-" << i + 1 << endl;
        cout << "Nama Barang : "; getline(cin, brg[i].nama);
        cout << "Lokasi Barang ditemukan : "<< endl;
        cout << "a. Gedung "<< endl
             << "b. Ruangan "<< endl
             << "c. lainnya" << endl;
        cout << "pilih : "; cin >> brg[i].loc;
        cin.ignore();
        cout << "Tanggal ditemukan : "; getline(cin, brg[i].tanggal);
        cout << endl;
    }
}

void tampilBarang(){
    if (n == 0) {
        cout << "Data kosong!" << endl << endl;
        return;
    }

    cout << "==============================\n";
    cout << "       DATA BARANG HILANG\n";
    cout << "==============================\n";

    cout << left << setw(15) << "NAMA BARANG"
         << setw(15) << "LOKASI TEMUAN"
         << setw(10) << "TANGGAL TEMUAN" << endl;

    cout << "------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << left << setw(15) << brg[i].nama
             << setw(15) << brg[i].loc
             << setw(10) << brg[i].tanggal << endl;
    }
    cout << endl;
}



int main(){
    int menu;
    cout << "===== MENU UTAMA =====" << endl;
    cout << "1. INPUT DATA BARANG" << endl
         << "2. SEARCH BARANG" << endl
         << "3. SORTING BARANG" << endl
         << "4. SAVE FILE BARANG" << endl
         << "5. TAMPIL BARANG" << endl
         << "=============================" << endl;
    cout << "Pilih Menu : ";
    cin >> menu;

    switch (menu){
    case 1:
        inputDataBarang();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        tampilBarang();
        break;
    
    default:
        break;
    }
 
}