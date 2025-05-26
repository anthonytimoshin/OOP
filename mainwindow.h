#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Classes.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    Point* point; // for polymorphism
    Lamp* lamp;
    Star* redStar;
    Star* blueStar;
    Star* greenStar;
    Star* yellowStar;
    const int step = 10;
};

#endif // MAINWINDOW_H
