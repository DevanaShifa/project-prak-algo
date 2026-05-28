#pragma once

enum SortAlg {
    Bubble,
    Insertion
};

enum SearchAlg {
    Selection,
    Binary
};

struct Setting {
    char loadedFile[50];
    SortAlg sortingAlgorithm;
    SearchAlg searchAlgorithm;
};

extern Setting setting;