#include<iostream>
#include<iomanip>
using namespace std;
//ppp
struct Barang{
    string nama;
    string loc;
    string tanggal;
    int id;
};

Barang brg[100];
int jumlahBarang = 0;

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
    cout << "\n===== INPUT DATA BARANG =====\n";
    cout << "Jumlah Barang : ";
    cin >> jumlahBarang; cout << endl;
    cin.ignore();

    for(int i=0; i<jumlahBarang; i++){
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
    if (jumlahBarang == 0) {
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

    for (int i = 0; i < jumlahBarang; i++) {
        cout << left << setw(15) << brg[i].nama
             << setw(15) << brg[i].loc
             << setw(10) << brg[i].tanggal << endl;
    }
    cout << endl;
}

//Searching
void binarySearch(){
    //data harus sudah terurut
    bubbleSort();

    string cari;
    cout << "\nMasukan nama barang yang dicari: ";
    cin.ignore();
    getline(cin, cari);

    int awal = 0;
    int akhir = jumlahBarang - 1;
    bool ditemukan = false;

    while(awal <= akhir){
        int tengah = (awal + akhir) / 2;

        if(brg[tengah].nama == cari){
            cout << "\nBarang ditemukan!\n";
            cout << "Nama Barang       : " << brg[tengah].nama << endl;
            cout << "Lokasi            : " << brg[tengah].loc << endl;
            cout << "Tanggal ditemukan : " << brg[tengah].tanggal << endl;
        
            ditemukan = true;
            break;
        }
        else if(brg[tengah].nama < cari){
            awal = tengah + 1;
        }
        else{
            akhir = tengah - 1;
        }
    }
}
// Sorting
void bubbleSort() {
    int i, j;

    // sorting process
    for (i = 0; i < jumlahBarang - 1; i++) {
        for (j = 0; j < jumlahBarang - 1 - i; j++) {
            if (brg[j].nama > brg[j+1].nama) {
                swap(brg[j], brg[j+1]);
            }
        }
    }
}

// Bubble sort nya dua, yang atas buat sorting sebelum binary search
void bubbleSortDisplay() {
    bubbleSort();
    cout << "\nData setelah Bubble Sort:\n";
}

void selectionSort() {
    int i, j;

    for (i = 0; i < jumlahBarang -1; i++)
    {
        int minIndex = i;
        for (j = i+1; j < jumlahBarang; j++)
        {
            if (brg[j].nama < brg[minIndex].nama) {
                minIndex = j;
            }
        }
        
        swap(brg[i], brg[minIndex]);
    }
    cout << "\nData setelah Selection Sort:\n";
    tampilBarang();
}

void sequentialSearch(int arr[], int n, int key) {
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

void menuSearch(){
    int pilih;

    cout << "\n====MENU SERACHING====\n";
    cout << "1. SEQUENTIAL SEARCH\n";
    cout << "2. BINARY SEARCH\n";
    cout << "========================\n";
    cout << "pilihan: ";
    cin >> pilih;

    switch(pilih){
    case 1:
        //sequen
        break;
    case 2:
        binarySearch();
        break;

        default:
            cout << "Pilihan Tidak Ada!\n";
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