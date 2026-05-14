#include<iostream>
#include<iomanip>
using namespace std;

struct Barang{
    string nama;
    string loc;
    string tanggal;
    int id;
};

Barang brg[100];
int n = 0;

bool konfirmasi(string pesan){
    char jawab;
    cout << pesan << " (y/t): ";
    cin >> jawab;
    cout << endl;
    return (jawab == 'y' || jawab == 'Y');
}

bool kembali(){
    return konfirmasi("Kembali ke Menu Utama?");
}

void inputDataBarang(){
    int n;
    cout << "\n===== INPUT DATA BARANG =====\n";
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

void sequentialSearch(int arr[], int n, int key){
    bool found = false;

    for(int i = 0; i<n; i++){
        if(arr[i]==key){
            cout << "Data ditemukan!";
            found = true;
            break;
        }
    }
    if(!found){
        cout << "Data Tidak ditemukan!"<< endl;
    }
}

void shellsort(int arr[], int n){
    for(int gap = n/2; gap>0; gap /=2){
        for(int i = gap; i<n; i++){
            int temp = arr[i];
            int j;
            
            for(int j = i; j >=gap && arr[j-gap] > temp; j-= gap){
                arr[j]=arr[j-gap];
            }
            arr[j] = temp;
        }
    }
}

void insertionSort(int arr[], int n){
    int temp, i, j;
    for(i=1; i<n; i++){
        temp = arr[i];
        j=i-1;
        while ((j >= 0) && (arr[j]> temp)){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void listsorting(){
    int menu;
    cout << "===== MENU SORTING =====";
    cout << "1. Bubble Sort\n"
         << "2. Insertion Sort\n"
         << "3. Selection Sort\n"
         << "4. Shell Sort\n"
         << "5. Quick Sort\n"
         << "6. Merge Sort\n"
         << "--------------------\n"
         << "Pilih : "; cin >> menu;
    cout << endl;

    switch(menu){
        case 1:
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        
        case 5:
    }
}

int main(){
    int menu;
    bool lanjut = true;

    while(lanjut){
    cout << "===== MENU UTAMA =====" << endl;
    cout << "1. INPUT DATA BARANG" << endl
         << "2. TAMPIL BARANG" << endl
         << "3. SEARCH BARANG" << endl
         << "4. SORTING BARANG" << endl
         << "5. SAVE FILE BARANG" << endl
         << "=============================" << endl;
    cout << "Pilih Menu : ";
    cin >> menu;

    switch (menu){
    case 1:
        inputDataBarang();
        lanjut = kembali();
        break;
    case 2:
        tampilBarang();
        lanjut = kembali();
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
    
        break;
    
    default:
        break;
    }
}
cout << "Program selesai." << endl;
}