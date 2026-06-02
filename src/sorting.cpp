#include "barang.hpp"
#include "setting.hpp"
#include "sorting.hpp"
#include <iostream>

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

