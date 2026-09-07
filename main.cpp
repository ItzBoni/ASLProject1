#include <iostream>
#include <string>
#include "ExportData.h"
#include "ImageHandler.h"

int main() {
    int imageCount = 0;

    std::cout << "How many images do you want to process" << std::endl;
    std::cin>>imageCount;

    for (int i = 0; i < imageCount; i++) {
        std::string imagePath;
        std::cout<<"Provide full path to the image"<<std::endl;
        std::cin>>imagePath;

        ImageHandler image(imagePath.data());
        const std::vector<int> frequencies = image.frequencyData();
        const std::string histogramFile = "histogram_" + std::to_string(i + 1) + ".csv";
        if (ExportData::exportToCSV(frequencies, histogramFile) != 0) {
            std::cerr << "Could not export histogram data to " << histogramFile << std::endl;
        }
        cv::Mat temp = image.applyBinaryThreshold(100);
        ImageHandler::displayImage("Original Image (Grayscale)", image.getImage());
        ImageHandler::displayImage("Binary threshold", temp);
    }

    return 0;
}
