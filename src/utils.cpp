#include "../include/utils.hpp"
#include "../include/setting.hpp"
#include <iostream>

void overwriteAbove(int jump) {
    for (int i = 0; i < jump; i++) {
        std::cout << "\033[A";
        std::cout << "\033[2K";
    }

    std::cout << "\r";
}

string toString(SortAlg alg) {
    switch (alg) {
        case Bubble:    return "Bubble Sort";
        case Selection: return "Selection Sort";
        case Insertion: return "Insertion Sort";
        case Shell:     return "Shell Sort";
        default:        return "Tidak diketahui";
    }
}