#include <iostream>
#include "../include/display.h"
#include "../include/barang.h"
#include "../include/helper.h"
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

