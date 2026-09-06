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
        cv::Mat getImage();
        int importImage(const char* fileName);
        int* frequencyData();
        cv::Mat applyBinaryThreshold(int p);
        static void displayImage(const char* fileName, const cv::Mat& image);
};


#endif //ASLPROJECT1_IMAGEHANDLER_H
