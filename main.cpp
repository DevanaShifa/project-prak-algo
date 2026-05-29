#include <iostream>
#include "display.hpp"
#include "barang.hpp"
#include "helper.hpp"
#include "setting.hpp"

using namespace std;

// debugging
int main() {
    loadSettingFromFile();
    loadBarangFromFile(setting.loadedFile);

    int menu;

    do
    {
        CLEAR_SCREEN;
        showTitle();

        showData();
        showHint();

        safeInput<int>("> ", menu);

        switch (menu)
        {
        case 1:
            pilihBarang();
            break;
        case 2:
            inputBarang();
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