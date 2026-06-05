#include "include/display.hpp"
#include "include/barang.hpp"
#include "include/utils.hpp"
#include "include/setting.hpp"
#include <iostream>

using namespace std;

// debugging
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
