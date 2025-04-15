#include "BlurNode.hpp"

BlurNode::BlurNode() {
    propertiesWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout();

    // Blur type combo
    blurTypeCombo = new QComboBox();
    blurTypeCombo->addItem("Uniform");
    blurTypeCombo->addItem("Directional (Horizontal)");
    blurTypeCombo->addItem("Directional (Vertical)");
    connect(blurTypeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &BlurNode::onBlurTypeChanged);
    layout->addWidget(blurTypeCombo);

    // Radius slider
    radiusSlider = new QSlider(Qt::Horizontal);
    radiusSlider->setRange(1, 20);
    radiusSlider->setValue(radius);
    connect(radiusSlider, &QSlider::valueChanged, this, &BlurNode::onRadiusChanged);
    layout->addWidget(radiusSlider);

    propertiesWidget->setLayout(layout);
}

QWidget* BlurNode::getPropertiesWidget() {
    return propertiesWidget;
}

void BlurNode::onRadiusChanged(int value) {
    radius = value;
    emit nodeChanged();
}

void BlurNode::onBlurTypeChanged(int index) {
    switch (index) {
        case 0: blurType = "Uniform"; break;
        case 1: blurType = "Horizontal"; break;
        case 2: blurType = "Vertical"; break;
    }
    emit nodeChanged();
}

cv::Mat BlurNode::process(const cv::Mat& input) {
    cv::Mat output;
    int ksize = 2 * radius + 1;

    if (blurType == "Uniform") {
        cv::GaussianBlur(input, output, cv::Size(ksize, ksize), 0);
    } else if (blurType == "Horizontal") {
        cv::GaussianBlur(input, output, cv::Size(ksize, 1), 0);
    } else if (blurType == "Vertical") {
        cv::GaussianBlur(input, output, cv::Size(1, ksize), 0);
    }

    return output;
}
