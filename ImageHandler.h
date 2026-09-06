//
// Created by santiagoabo on 9/5/26.
//
#pragma once
#ifndef ASLPROJECT1_IMAGEHANDLER_H
#define ASLPROJECT1_IMAGEHANDLER_H
#include <opencv2/opencv.hpp>

class ImageHandler {
    private:
        cv::Mat image;
    public:
        ImageHandler(char* fileName);
        int importImage(const char* fileName);
        int* frequencyData();
        void applyBinaryThreshold(cv::Mat image, int p);
};


#endif //ASLPROJECT1_IMAGEHANDLER_H
