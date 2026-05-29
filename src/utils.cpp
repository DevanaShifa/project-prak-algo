#include <iostream>
#include <fstream>
#include "utils.hpp"
#include "barang.hpp"
#include "setting.hpp"

void overwriteAbove(int jump) {
    for (int i = 0; i < jump; i++) {
        std::cout << "\033[A";
        std::cout << "\033[2K";
    }

    std::cout << "\r";
}