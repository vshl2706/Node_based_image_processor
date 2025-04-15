#pragma once

#include "BaseNode.hpp"
#include <QSlider>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class BrightnessContrastNode : public BaseNode {
    Q_OBJECT

public:
    BrightnessContrastNode();

    QWidget* getPropertiesWidget() override;
    cv::Mat process(const cv::Mat& input) override;

private slots:
    void onBrightnessChanged(int value);
    void onContrastChanged(int value);
    void resetBrightness();
    void resetContrast();

private:
    int brightness = 0;
    double contrast = 1.0;

    QSlider *brightnessSlider;
    QSlider *contrastSlider;
    QPushButton *resetBrightnessBtn;
    QPushButton *resetContrastBtn;
    QWidget *propertiesWidget;
};
