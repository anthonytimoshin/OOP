#include "mainwindow.h"
#include <QPainter>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setFixedSize(800, 600);
    setFocusPolicy(Qt::StrongFocus);
    point = new Point(100, 100, true);
    lamp = new TableLamp(200, 200, true); // Start with TableLamp
    redStar = new RedStar(300, 200); // RedStar at fixed position
    blueStar = new BlueStar(500, 200); // BlueStar at fixed position
    greenStar = new GreenStar(300, 400); // GreenStar at fixed position
    yellowStar = new YellowStar(500, 400); // YellowStar at fixed position
}

MainWindow::~MainWindow() {
    delete point;
    delete lamp;
    delete redStar;
    delete blueStar;
    delete greenStar;
    delete yellowStar;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(rect(), Qt::white);

    lamp->moveTo(&painter, lamp->getX(), lamp->getY());
    redStar->draw(&painter);
    blueStar->draw(&painter);
    greenStar->draw(&painter);
    yellowStar->draw(&painter);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(rect(), Qt::white);

    int newX = lamp->getX();
    int newY = lamp->getY();

    switch (event->key()) {
    case Qt::Key_W:
        newY -= step;
        break;
    case Qt::Key_S:
        newY += step;
        break;
    case Qt::Key_A:
        newX -= step;
        break;
    case Qt::Key_D:
        newX += step;
        break;
    case Qt::Key_1: // Switch to TableLamp
        delete lamp;
        lamp = new TableLamp(newX, newY, true);
        break;
    case Qt::Key_2: // Switch to FloorLamp
        delete lamp;
        lamp = new FloorLamp(newX, newY, true);
        break;
    case Qt::Key_3: // Switch to WallLamp
        delete lamp;
        lamp = new WallLamp(newX, newY, true);
        break;
    case Qt::Key_4: // Switch to CeilingLamp
        delete lamp;
        lamp = new CeilingLamp(newX, newY, true);
        break;
    default:
        QMainWindow::keyPressEvent(event);
        return;
    }

    // Check for collision with redStar
    int dx = lamp->getX() - redStar->getX();
    int dy = lamp->getY() - redStar->getY();
    if (dx * dx + dy * dy < 50 * 50) { // Collision with RedStar
        redStar->interactWithLamp(lamp);
    }

    // Check for collision with blueStar
    dx = lamp->getX() - blueStar->getX();
    dy = lamp->getY() - blueStar->getY();
    if (dx * dx + dy * dy < 50 * 50) { // Collision with BlueStar
        blueStar->interactWithLamp(lamp);
    }

    // Check for collision with greenStar
    dx = lamp->getX() - greenStar->getX();
    dy = lamp->getY() - greenStar->getY();
    if (dx * dx + dy * dy < 50 * 50) { // Collision with GreenStar
        greenStar->interactWithLamp(lamp);
    }

    // Check for collision with yellowStar
    dx = lamp->getX() - yellowStar->getX();
    dy = lamp->getY() - yellowStar->getY();
    if (dx * dx + dy * dy < 50 * 50) { // Collision with YellowStar
        yellowStar->interactWithLamp(lamp);
    }

    lamp->moveTo(&painter, newX, newY);
    redStar->draw(&painter);
    blueStar->draw(&painter);
    greenStar->draw(&painter);
    yellowStar->draw(&painter);
    update();
}
