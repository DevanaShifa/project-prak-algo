#include <iostream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>

#define MKDIR_DATA system("mkdir -p .lnfdata")
#define MKDIR_PRINT system("mkdir -p print")
#define CLEAR_SCREEN system("clear")

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

enum SortAlg {
    Bubble,
    Selection,
    Insertion,
    Shell,
};

struct Setting {
    std::string loadedFile;
    SortAlg sortingAlgorithm;
};

int totalBarang = 0;
Barang dataBarang[256];
Setting setting;

void overwriteAbove(int jump) {
    for (int i = 0; i < jump; i++) {
        std::cout << "\033[A";
        std::cout << "\033[2K";
    }

    std::cout << "\r";
}

string toString(SortAlg alg) {
    switch (alg) {
        case Bubble:    return "Bubble Sort";
        case Selection: return "Selection Sort";
        case Insertion: return "Insertion Sort";
        case Shell:     return "Shell Sort";
        default:        return "Tidak diketahui";
    }
}


/**
 * validasi input agar program tidak error ketika tipe data tidak sesuai
 * @param msg pesan output yang ditampilkan
 * @param value variabel penyimpan input
 */
template<typename T>
void safeInput(const string& msg, T& value) {
    string input;

    while (true)
    {
        cout << msg;

        getline(cin, input);

        stringstream ss(input);

        if (ss >> value) {
            return;
        }

        cout << "Tipedata tidak valid!\n";
    }
}

/**
 * memastikan input harus berada di range tertentu
 * @param msg pesan output yang ditampilkan
 * @param value variabel penyimpan input
 * @param min nilai minimum
 * @param max nilai maksimum
 */
template<typename T>
void rangedInput(
    const string& msg,
    T& value,
    T min,
    T max
) {
    string input;

    while (true)
    {
        cout << msg;
        getline(cin, input);
        stringstream ss(input);

        if (!(ss >> value)) {
            cout << "Tipe data tidak valid!\n";
            continue;
        }

        if (value < min) {
            cout << "Nilai harus >= " << min << "!\n";
            continue;
        }
        if (value > max) {
            cout << "Nilai harus <= " << max << "!\n";
            continue;
        }
        return;
    }
}

typedef bool (*LCompare)(const Barang&, const Barang&);

void bubbleSort(Barang arr[], int size, LCompare cmp) {
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (cmp(arr[j], arr[j+1])) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

void selectionSort(Barang arr[], int size, LCompare cmp) {
    for (int i = 0; i < size - 1; i++) {
        int selected = i;

        for (int j = i + 1; j < size; j++) {
            if (cmp(arr[selected], arr[j])) {
                selected = j;
            }
        }

        if (selected != i) {
            std::swap(arr[i], arr[selected]);
        }
    }
}

void insertionSort(Barang arr[], int size, LCompare cmp) {
    for (int i = 1; i < size; i++) {
        Barang key = arr[i];
        int j = i - 1;

        while (j >= 0 && cmp(arr[j], key)) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void shellSort(Barang arr[], int size, LCompare cmp) {
    for (int gap = size/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            Barang temp = arr[i];
            int j;

            for (j = i; j <= gap && cmp(arr[j - gap], temp); j -= gap)
            {
                arr[j] = arr[j - gap];
            }            
        }        
    }    
}

void initSetting() {
    setting.loadedFile = "database";
    setting.sortingAlgorithm = SortAlg::Bubble;
}


void saveSettingAsFile() {
    ofstream File(".lnfdata/setting.txt");

    if (File.is_open()) {
        File << "loaded-file: " << setting.loadedFile << endl;
        File << "sorting-algorithm: " << setting.sortingAlgorithm;

        File.close();
    } else {
        cout << "Gagal membuat file." << endl;
    }
}

void loadSettingFromFile() {
    ifstream File(".lnfdata/setting.txt");

    if (File.is_open()) {
        string temp;

        getline(File, temp, ':');
        getline(File, setting.loadedFile);

        setting.loadedFile.erase(0, 1);

        getline(File, temp, ':');
        File >> (int&)setting.sortingAlgorithm;

        File.close();
    } else {
        initSetting();
        saveSettingAsFile();
    }
}

void handleSortData(Barang arr[], int size, LCompare cmp) {
    switch (setting.sortingAlgorithm) {
        case Bubble:
            bubbleSort(arr, size, cmp);
            break;

        case Selection:
            selectionSort(arr, size, cmp);
            break;

        case Insertion:
            insertionSort(arr, size, cmp);
            break;

        case Shell:
            shellSort(arr, size, cmp);
            break;
    }
}

void sequentialSearch(Barang targetArr[], Barang searchArr[], int targetSize, int& searchSize, char search[]) {
    for (int i = 0; i < targetSize; i++)
    {
        if (
            strcmp(targetArr[i].namaBarang, search) == 0 ||
            strcmp(targetArr[i].kategori, search) == 0 ||
            strcmp(targetArr[i].deskripsi, search) == 0 ||
            strcmp(targetArr[i].lokasi, search) == 0
        )
        {
            
            searchArr[searchSize++] = targetArr[i];
        }
    }
}

// HANDLE BARANG

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

// HANDLE DISPLAY

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

int main() {
    MKDIR_DATA;
    MKDIR_PRINT;
    loadSettingFromFile();
    loadBarangFromFile(setting.loadedFile);

    int menu;

    do
    {
        CLEAR_SCREEN;
        showTitle();

        showData(dataBarang, totalBarang);
        showHint();

        safeInput("> ", menu);

        switch (menu)
        {
        case 1:
            pilihBarang();
            break;
        case 2:
            inputBarang();
            break;
        case 3:
            showSort();
            break;
        case 4:
            showSearch();
            break;
        case 5:
            showSettings();
            break;
        
        case 0:
            cout << "Keluar..." << endl;
            break;

        default:
            cout << "Menu tidak valid!" << endl;
            cout << "> ";
            break;
        }
    } while (menu != 0);
}