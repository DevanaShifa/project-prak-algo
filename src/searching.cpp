#include "../include/searching.hpp"
#include "../include/barang.hpp"
#include <iostream>
#include <string.h>

using namespace std;

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