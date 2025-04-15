#include "BrightnessContrastNode.hpp"
#include <opencv2/opencv.hpp>

BrightnessContrastNode::BrightnessContrastNode() {
    propertiesWidget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();

    // Brightness Slider
    QLabel *brightnessLabel = new QLabel("Brightness");
    brightnessSlider = new QSlider(Qt::Horizontal);
    brightnessSlider->setRange(-100, 100);
    brightnessSlider->setValue(0);
    connect(brightnessSlider, &QSlider::valueChanged, this, &BrightnessContrastNode::onBrightnessChanged);

    resetBrightnessBtn = new QPushButton("Reset Brightness");
    connect(resetBrightnessBtn, &QPushButton::clicked, this, &BrightnessContrastNode::resetBrightness);

    // Contrast Slider
    QLabel *contrastLabel = new QLabel("Contrast");
    contrastSlider = new QSlider(Qt::Horizontal);
    contrastSlider->setRange(0, 300); // Multiply by 100 to handle float
    contrastSlider->setValue(100);
    connect(contrastSlider, &QSlider::valueChanged, this, &BrightnessContrastNode::onContrastChanged);

    resetContrastBtn = new QPushButton("Reset Contrast");
    connect(resetContrastBtn, &QPushButton::clicked, this, &BrightnessContrastNode::resetContrast);

    layout->addWidget(brightnessLabel);
    layout->addWidget(brightnessSlider);
    layout->addWidget(resetBrightnessBtn);
    layout->addWidget(contrastLabel);
    layout->addWidget(contrastSlider);
    layout->addWidget(resetContrastBtn);

    propertiesWidget->setLayout(layout);
}

QWidget* BrightnessContrastNode::getPropertiesWidget() {
    return propertiesWidget;
}

void BrightnessContrastNode::onBrightnessChanged(int value) {
    brightness = value;
    emit nodeChanged();  // triggers re-processing
}

void BrightnessContrastNode::onContrastChanged(int value) {
    contrast = value / 100.0;
    emit nodeChanged();  // triggers re-processing
}

void BrightnessContrastNode::resetBrightness() {
    brightnessSlider->setValue(0);
}

void BrightnessContrastNode::resetContrast() {
    contrastSlider->setValue(100);
}

cv::Mat BrightnessContrastNode::process(const cv::Mat& input) {
    cv::Mat output;
    input.convertTo(output, -1, contrast, brightness);
    return output;
}
