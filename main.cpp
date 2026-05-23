#include <iostream>
#include "display.h"
#include "barang.h"
#include "helper.h"

using namespace std;

// debugging
int main() {
    // inputBarang();

    int menu;

    do
    {
        CLEAR_SCREEN;
        tampilData();
        tampilHint();

        safeInput<int>("> ", menu);

        switch (menu)
        {
        case 1:
            break;
        case 2:
            inputBarang();
            break;
        
        default:
            cout << "Menu tidak valid!" << endl;
            cin.ignore();
            cin.get();
            break;
        }
    } while (menu != 6);
}