#include "mainwindow.h"
#include <QPainter>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setFixedSize(800, 600);
    setFocusPolicy(Qt::StrongFocus);
    point = new Point(100, 100, true); // Создаем Lamp, но храним как Point*

    lamp = new Lamp(400,250,1);
    magicLamp = new MagicLamp(100,100,1);
    brokenLamp = new BrokenLamp(50,50,1);
    BufLamp[0] = lamp;
    BufLamp[1] = magicLamp;
    BufLamp[2] = brokenLamp;

    energy = new Energy(100,250,1);
    brick = new Brick(600,275,1);
    BufFig[0] = energy;
    BufFig[1] = brick;

    curLamp = BufLamp[0];
    curFig = BufFig[0];
}

MainWindow::~MainWindow() {
    delete point; // Освобождаем память
    delete lamp;
    delete magicLamp;
    delete brokenLamp;
    delete energy;
    delete brick;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Очистка холста
    painter.fillRect(rect(), Qt::white);

    int newX = lamp->getX();
    int newY = lamp->getY();
    lamp->moveTo(&painter,newX,newY);

    for(int i = 0; i < 2; i++)
    {
        BufFig[i]->Show(&painter);
    }


}

int MainWindow::CheckCollision(Lamp *l, Fig *f)
{
    int dx = l->getX() - f->getX();
    int dy = l->getY() - f->getY();
    if (dx < 50 or dy < 50) { // Collision
        return 1;
    }
    return 0;
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
    case Qt::Key_W: // Ввsерх
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
    int res = 0;
    curLamp->moveTo(&painter, newX, newY); // Убираем передачу painter

    for(int i = 0; i < 2; i++)
    {
        int res = CheckCollision(lamp, BufFig[i]);
        if (res == 1)
        {
            break;
        }

        if(curLamp->id == 0) {
            BufFig[i]->id = 0;
        }

    }


    // {
    //      curLamp = BufLamp[1];
    // }
    //CheckCollision(lamp,
    //res =               BufFig[1]);

    update(); // Перерисовка окна


}
