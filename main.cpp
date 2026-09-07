#include <iostream>
#include <string>
#include <filesystem> // Required for std::filesystem::path
#include "ExportData.h"
#include "ImageHandler.h"

int main() {
    int imageCount = 0;

    std::cout << "How many images do you want to process" << std::endl;
    std::cin >> imageCount;

    for (int i = 0; i < imageCount; i++) {
        std::string imagePath;
        int p;
        std::cout << "Provide full path to the image" << std::endl;
        std::cin >> imagePath;

        std::cout << "Provide p value for threshold" << std::endl;
        std::cin >> p;

        // Extract filename from full path (e.g., "/path/to/photo.jpg" -> "photo.jpg")
        std::string fileName = std::filesystem::path(imagePath).filename().string();

        ImageHandler image(imagePath.data());
        const std::vector<int> frequencies = image.frequencyData();
        const std::string histogramFile = "histogram_" + fileName + ".csv";
        if (ExportData::exportToCSV(frequencies, histogramFile) != 0) {
            std::cerr << "Could not export histogram data to " << histogramFile << std::endl;
        }
        std::cout << "Exported " << histogramFile << " for file: " << fileName << std::endl;

        cv::Mat temp = image.applyBinaryThreshold(p);
        ImageHandler::displayImage("Original Image (Grayscale)", image.getImage());
        ImageHandler::displayImage("Binary threshold", temp);
    }

    return 0;
}