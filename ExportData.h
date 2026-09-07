//
// Created by santiagoabo on 9/5/26.
//
#pragma once
#ifndef ASLPROJECT1_EXPORT_H
#define ASLPROJECT1_EXPORT_H
#include <string>
#include <vector>


class ExportData {
public:
    static int exportToCSV(const std::vector<int>& exportContent, const std::string& fileName);
};


#endif //ASLPROJECT1_EXPORT_H
