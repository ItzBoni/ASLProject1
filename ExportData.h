//
// Created by santiagoabo on 9/5/26.
//
#pragma once
#ifndef ASLPROJECT1_EXPORT_H
#define ASLPROJECT1_EXPORT_H


class ExportData {
public:
    static int exportToCSV(const int *exportContent, const char *fileName, const char *exportName, int arraySize);
};


#endif //ASLPROJECT1_EXPORT_H
