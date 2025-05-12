#include "mainwindow.h"
#include <QPainter>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setFixedSize(800, 600);
    setFocusPolicy(Qt::StrongFocus);
    point = new Point(100, 100, true); // Создаем Lamp, но храним как Point*
    lamp = new Lamp(200,200,1);
}

MainWindow::~MainWindow() {
    delete point; // Освобождаем память
}

void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Очистка холста
    painter.fillRect(rect(), Qt::white);

   // point->moveTo(&painter, newX, newY); // Убираем передачу painter

    // Рисование объекта через указатель
    // if (point->getVisibility()) {
        // lamp->Show(&painter);
    // } else {
    //     point->Hide(&painter);
    // }
    int newX = lamp->getX();
    int newY = lamp->getY();
    lamp->moveTo(&painter,newX,newY);

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    // Очистка холста
    painter.fillRect(rect(), Qt::white);


    int newX = lamp->getX();
    int newY = lamp->getY();

    switch (event->key()) {
    case Qt::Key_W: // Вверх
        newY -= step;
        break;
    case Qt::Key_S: // Вниз
        newY += step;
        break;
    case Qt::Key_A: // Влево
        newX -= step;
        break;
    case Qt::Key_D: // Вправо
        newX += step;
        break;
    default:
        QMainWindow::keyPressEvent(event);
        return;
    }
  //  point->Show(&painter);
    lamp->moveTo(&painter, newX, newY); // Убираем передачу painter
    update(); // Перерисовка окна
}
