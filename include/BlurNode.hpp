#pragma once

#include "BaseNode.hpp"
#include <QSlider>
#include <QComboBox>
#include <QVBoxLayout>
#include <QWidget>
#include <opencv2/opencv.hpp>

class BlurNode : public BaseNode {
    Q_OBJECT

public:
    BlurNode();

    QWidget* getPropertiesWidget() override;
    cv::Mat process(const cv::Mat& input) override;

private slots:
    void onRadiusChanged(int value);
    void onBlurTypeChanged(int index);

private:
    int radius = 5;
    QString blurType = "Uniform";

    QSlider* radiusSlider;
    QComboBox* blurTypeCombo;
    QWidget* propertiesWidget;
};
