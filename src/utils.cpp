#include "../include/utils.hpp"
#include "../include/barang.hpp"
#include "../include/setting.hpp"
#include <iostream>
#include <fstream>

void overwriteAbove(int jump) {
    for (int i = 0; i < jump; i++) {
        std::cout << "\033[A";
        std::cout << "\033[2K";
    }

    std::cout << "\r";
}