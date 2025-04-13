#include "ImageInputNode.hpp"
#include <QImageReader>

ImageInputNode::ImageInputNode(const QString& name)
    : BaseNode(name) {
    inputCount = 0;   // No inputs
    outputCount = 1;
}

void ImageInputNode::loadImage(const QString& path) {
    filePath = path;
    QImageReader reader(path);
    image = reader.read();
}

QImage ImageInputNode::getImage() const {
    return image;
}

QImage ImageInputNode::process(const std::vector<QImage>&) {
    return image;  // Just return the loaded image
}
