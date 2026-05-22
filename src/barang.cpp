#include <iostream>
#include <iomanip>
#include "barang.h"
#include "display.h"
#include "helper.h"

using namespace std;

int totalBarang = 0;
Barang dataBarang[100];

void inputBarang() {
    CLEAR_SCREEN;

    int jumlah;

    cout << setfill('-') << setw(90) << "" << endl;
    cout << setfill(' ') << setw(50) << "INPUT DATA" << endl;
    cout << setfill('-') << setw(90) << "" << endl;

    safeInput<int>("Banyak data yang ingin diinput: ", jumlah);

    for (int i = 0; i < jumlah; i++)
    {
        
    }
}