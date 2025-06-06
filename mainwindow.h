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
    int CheckCollision(Lamp *l, Fig *f);
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

protected:
    Point* point; // Указатель на Point для полиморфизма
    const int step = 10;

    Lamp *lamp;
    BrokenLamp *brokenLamp;
    MagicLamp  *magicLamp;


    Energy *energy;
    Brick *brick;

    Lamp *BufLamp[3]; // 2
    Fig  *BufFig[2]; // 1

    Lamp *curLamp;
    Fig  *curFig;

};

#endif // MAINWINDOW_H
