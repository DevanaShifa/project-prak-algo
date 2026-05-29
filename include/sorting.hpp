#pragma once
#include <iostream>

/**
 * @tparam T tipe data elemen array
 * @tparam N ukuran array
 * @tparam Compare tipe function comparator
 * 
 * @param arr array yang akan di sort
 * @param cmp callback function untuk menentukan aturan sorting
 */
template<typename T, int N, typename Compare>
void bubbleSort(T (&arr)[N], Compare cmp) {
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (cmp(arr[j], arr[j+1])) {
                std::swap(arr[j], arr[j+1]);
            }
        }        
    }
}