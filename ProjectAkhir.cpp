#include<iostream>
#include<iomanip>
using namespace std;
//ppp
struct Barang{
    string nama;
    string loc;
    string tanggal;
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

// Sorting
void bubbleSort() {
    int i, j;

    // sorting process
    for (i = 0; i < jumlahBarang - 1; i++) {
        for (j = 0; j < jumlahBarang - 1 - i; j++) {
            if (listAnggotaSorted[j].noAnggota > listAnggotaSorted[j+1].noAnggota) {
                swap(listAnggotaSorted[j], listAnggotaSorted[j+1]);
            }
        }
    }
}

// Bubble sort nya dua, yang atas buat sorting sebelum binary search
void bubbleSortDisplay() {
    bubbleSort();
    tampilData(listAnggotaSorted);
}

void selectionSort() {
    int i, j;

    for (i = 0; i < jumlahBarang -1; i++)
    {
        int minIndex = i;
        for (j = i+1; j < jumlahBarang; j++)
        {
            if (listAnggotaSorted[j].noAnggota < listAnggotaSorted[minIndex].noAnggota) {
                minIndex = j;
            }
        }
        
        swap(listAnggotaSorted[i], listAnggotaSorted[minIndex]);
    }

    tampilData(listAnggotaSorted);
}

void insertionShort(){
    int i, j;

    for(i = 1; i < jumlahBarang; i++){
        eBox[i] = listAnggotaSorted[i];
        j = i - 1;
        while ((j >= 0) && (listAnggotaSorted[j].noAnggota > eBox[i].noAnggota)){
            listAnggotaSorted[j+1] = listAnggotaSorted[j];
            j--;
        }
        listAnggotaSorted[j+1] = eBox[i];
    }
    tampilData(listAnggotaSorted);
};

void shellSort() {
    int i, j, k;

    for (i = jumlahBarang / 2; i > 0; i = i / 2) {
        for (j = i; j < jumlahBarang; j++) {
            for (k = j - i; k >= 0; k = k - i) {
                if (listAnggotaSorted[k + i].noAnggota < listAnggotaSorted[k].noAnggota) {
                    swap(listAnggotaSorted[k], listAnggotaSorted[k + i]);
                }
            }
        }
    }

    cout << "Data Setelah Shell Sort:" << endl;
    tampilData(listAnggotaSorted);
}

int partition(int low, int high){
    int pivot = listAnggotaSorted[high].noAnggota;
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(listAnggotaSorted[j].noAnggota <= pivot){
            i++;
            swap(listAnggotaSorted[i], listAnggotaSorted[j]);
        }
    }

    swap(listAnggotaSorted[i + 1], listAnggotaSorted[high]);
    return i + 1;
}

void quickSort(int low, int high){
    if(low < high){
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void quickSortDisplay() 
    quickSort(0, jumlahBarang - 1);
    tampilData(listAnggotaSorted);
}

void merge(int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right){
        if(listAnggotaSorted[i].noAnggota < listAnggotaSorted[j].noAnggota){
            eBox[k] = listAnggotaSorted[i]; 
            i++;
        } else {
            eBox[k] = listAnggotaSorted[j];
            j++;
        }
        k++;
    }

    while(i <= mid){
        eBox[k] = listAnggotaSorted[i];
        i++; 
        k++;
    }
    
    while(j <= right){
        eBox[k] = listAnggotaSorted[j];
        j++; 
        k++;
    }
    
    for(int x = left; x <= right; x++){
        listAnggotaSorted[x] = eBox[x];
    }
}

void mergeSort(int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

void mergeSortDisplay()
    mergeSort(0, jumlahBarang - 1);
    tampilData(listAnggotaSorted);
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