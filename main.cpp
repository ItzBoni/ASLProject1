#include <iostream>
#include <string>
#include "ExportData.h"
#include "ImageHandler.h"

int main() {
    int imageCount = 0;

    std::cout << "How many images do you want to process" << std::endl;
    std::cin>>imageCount;

    for (int i = 0; i < imageCount; i++) {
        std::pmr::string imagePath;
        std::cout<<"Provide full path to the image"<<std::endl;
        std::cin>>imagePath;

        ImageHandler image((imagePath.data()));
        cv::Mat temp(image.getImage().rows, image.getImage().cols, CV_8UC1);

        image.applyBinaryThreshold(temp, 128);
        ImageHandler::displayImage("nigger", temp);
    }

    return 0;
}
