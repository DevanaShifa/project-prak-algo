#include <iostream>
#include "display.h"
#include "barang.h"
#include "helper.h"
using namespace std;

#define CLEAR_SCREEN system("clear")

void tampilMenu() {
    int menu;

    do
    {
        switch (menu)
        {
        case 1:
            break;
        
        default:
            cout << "Menu tidak valid!" << endl;
            cin.ignore();
            cin.get();
            break;
        }
    } while (menu != 6);
    
}

