//
// Created by santiagoabo on 9/5/26.
//

#include "ImageHandler.h"

ImageHandler::ImageHandler(char* fileName) {
    importImage(fileName);
}

int ImageHandler::importImage(const char* fileName) {
    std::cout<<fileName<<std::endl;
    this->image = cv::imread(fileName);

    if (!this->image.data) {
        std::cout<<"Could not open or find the image"<<std::endl;
        return -1;
    }

    return 0;
}

int* ImageHandler::frequencyData() {
    int* values = new int[256]{0}; // Allocated on the heap
    for (int i = 0; i < this->image.rows; i++) {
        for (int j = 0; j < this->image.cols; j++) {
            values[this->image.at<uchar>(i, j)]++;
        }
    }
    return values; // Safe to return
}

void ImageHandler::applyBinaryThreshold(cv::Mat outputImage, int p) {
    //Binary Threshold
    for (int j = 0; j < this->image.rows; j++) {
        for (int i = 0; i < this->image.cols; i++) {
            if (this->image.at<uchar>(j, i) > p) {
                outputImage.at<uchar>(j, i) = 255;
            } else {
                outputImage.at<uchar>(j, i) = 0 ;
            }
        }
    }
}

void ImageHandler::displayImage(const char* fileName, cv::Mat image) {
    cv::namedWindow(fileName, cv::WINDOW_NORMAL);
    cv::imshow(fileName, image);
}

cv::Mat ImageHandler::getImage() {
    return this->image;
}