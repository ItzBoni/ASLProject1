//
// Created by santiagoabo on 9/5/26.
//
#include <fstream>
#include <iostream>
#include "ExportData.h"
using namespace std;

int ExportData::exportToCSV(const std::vector<int>& exportContent, const std::string& fileName) {
    ofstream histogram(fileName);

    if (!histogram.is_open()) {
        std::cerr << "Error: Could not open or create the file!" << std::endl;
        return -1;
    }

    histogram << "intensity,frequency\n";
    for (std::size_t intensity = 0; intensity < exportContent.size(); intensity++) {
        histogram << intensity << "," << exportContent[intensity] << "\n";
    }

    histogram.close();
    return 0;
}
