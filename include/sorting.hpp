#pragma once
#include <iostream>
#include "barang.hpp"

typedef bool (*LCompare)(const Barang&, const Barang&);

void bubbleSort(Barang arr[], int size, LCompare cmp);
void selectionSort(Barang arr[], int size, LCompare cmp);
void insertionSort(Barang arr[], int size, LCompare cmp);
void shellSort(Barang arr[], int size, LCompare cmp);