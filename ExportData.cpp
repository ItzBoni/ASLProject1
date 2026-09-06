//
// Created by santiagoabo on 9/5/26.
//
#include <fstream>
#include <iostream>
#include "ExportData.h"
using namespace std;

static int exportToCSV(const int* exportContent,  const char* fileName, const char* exportName,const int arraySize = 256) {
    ofstream histogram("histogram.csv");

    if (!histogram.is_open()) {
        std::cerr << "Error: Could not open or create the file!" << std::endl;
        return -1;
    }

    for (int i = 0; i < arraySize; i++) {
        histogram << exportContent[i] << ",\n";
    }

    histogram.close();
    return 0;
}
