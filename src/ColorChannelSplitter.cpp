#include "ColorChannelSplitterNode.hpp"

ColorChannelSplitterNode::ColorChannelSplitterNode() {
    propertiesWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout();

    channelSelector = new QComboBox();
    channelSelector->addItem("Red Channel");
    channelSelector->addItem("Green Channel");
    channelSelector->addItem("Blue Channel");

    connect(channelSelector, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &ColorChannelSplitterNode::onChannelChanged);

    layout->addWidget(channelSelector);
    propertiesWidget->setLayout(layout);
}

QWidget* ColorChannelSplitterNode::getPropertiesWidget() {
    return propertiesWidget;
}

void ColorChannelSplitterNode::onChannelChanged(int index) {
    currentChannel = index;
    emit nodeChanged(); // trigger re-processing
}

cv::Mat ColorChannelSplitterNode::process(const cv::Mat& input) {
    std::vector<cv::Mat> channels;
    cv::split(input, channels);

    cv::Mat singleChannel = channels[currentChannel];
    cv::Mat grayImage;
    cv::cvtColor(singleChannel, grayImage, cv::COLOR_GRAY2BGR); // For display consistency

    return grayImage;
}
