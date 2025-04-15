#pragma once

#include "BaseNode.hpp"
#include <QComboBox>
#include <QVBoxLayout>
#include <QWidget>
#include <opencv2/opencv.hpp>

class ColorChannelSplitterNode : public BaseNode {
    Q_OBJECT

public:
    ColorChannelSplitterNode();

    QWidget* getPropertiesWidget() override;
    cv::Mat process(const cv::Mat& input) override;

private slots:
    void onChannelChanged(int index);

private:
    int currentChannel = 0; // 0 = R, 1 = G, 2 = B
    QComboBox* channelSelector;
    QWidget* propertiesWidget;
};
