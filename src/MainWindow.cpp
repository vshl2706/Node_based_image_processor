#include "MainWindow.hpp"
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include <QMenuBar>
#include <opencv2/opencv.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      view(new QGraphicsView(this)),
      scene(new QGraphicsScene(this)) {
    setWindowTitle("Node-Based Image Processor");

    // Set up central canvas
    view->setScene(scene);
    setCentralWidget(view);

    // Menu for opening images
    QMenu *fileMenu = menuBar()->addMenu("File");
    QAction *openAction = fileMenu->addAction("Open Image");
    connect(openAction, &QAction::triggered, this, &MainWindow::openImage);
     
    std::shared_ptr<ImageInputNode> inputNode;

}

MainWindow::~MainWindow() {
    delete view;
    delete scene;
}

void MainWindow::openImage() {
    QString filename = QFileDialog::getOpenFileName(this, "Open Image", "", "Images (*.png *.jpg *.bmp)");
    if (!filename.isEmpty()) {
        // Load image using OpenCV
        cv::Mat image = cv::imread(filename.toStdString());
        if (!image.empty()) {
            cv::cvtColor(image, image, cv::COLOR_BGR2RGB); // Convert to RGB for Qt
            QImage qimg(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
            QPixmap pixmap = QPixmap::fromImage(qimg);
            scene->clear();
            scene->addPixmap(pixmap);
        }
    }

    QString filename = QFileDialog::getOpenFileName(this, "Open Image", "", "Images (*.png *.jpg *.bmp)");
    if (!filename.isEmpty()) {
        inputNode = std::make_shared<ImageInputNode>("Image Input");
        inputNode->loadImage(filename);

    QImage img = inputNode->process({});
    if (!img.isNull()) {
        scene->clear();
        scene->addPixmap(QPixmap::fromImage(img));
    }
}

}
