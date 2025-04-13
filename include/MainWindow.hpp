#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
 
private slots:
    void openImage();

private:
    QGraphicsView *view;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_HPP
