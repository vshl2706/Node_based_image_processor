#pragma once

#include "BaseNode.hpp"
#include <opencv2/opencv.hpp>
#include <string>

class OutputNode : public BaseNode {
public:
    OutputNode();

    void process() override;
    cv::Mat getOutputImage() const;
    void exportToFile(const std::string& filePath);

private:
    cv::Mat outputImage;
};
