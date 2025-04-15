#include "OutputNode.hpp"

OutputNode::OutputNode() {
    this->title = "Output Node";
    this->addInputSlot("Image");
}

void OutputNode::process() {
    if (hasInputConnection(0)) {
        auto* inputNode = getInputNode(0);
        if (inputNode) {
            outputImage = inputNode->getOutputImage();
        }
    }
}

cv::Mat OutputNode::getOutputImage() const {
    return outputImage;
}

void OutputNode::exportToFile(const std::string& filePath) {
    if (!outputImage.empty()) {
        cv::imwrite(filePath, outputImage);
    }
}
