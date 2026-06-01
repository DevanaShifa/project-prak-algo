#pragma once
#include <iostream>
#include "setting.hpp"

/**
 * @tparam T tipe data elemen array
 * @tparam Compare tipe function comparator
 * 
 * @param arr array yang akan di sort
 * @param size ukuran array
 * @param cmp callback function untuk menentukan aturan sorting
 */
template<typename T, typename Compare>
void bubbleSort(T arr[], int size, Compare cmp) {
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

/**
 * @tparam T tipe data elemen array
 * @tparam Compare tipe function comparator
 * 
 * @param arr array yang akan di sort
 * @param size ukuran array
 * @param cmp callback function untuk menentukan aturan sorting
 */
template<typename T, typename Compare>
void selectionSort(T arr[], int size, Compare cmp) {
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