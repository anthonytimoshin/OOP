#include "mainwindow.h"
#include <QPainter>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setFixedSize(800, 600);
    setFocusPolicy(Qt::StrongFocus);
    // point = new Point(100, 100, 1); // коммент, так как Point - abc

    // Инициализация ламп
    brokenLamp = new BrokenLamp(400,250,1);
    lamp = new Lamp(400,250,1);
    magicLamp = new MagicLamp(400,250,1);

    BufLamp[0] = brokenLamp;
    BufLamp[1] = lamp;
    BufLamp[2] = magicLamp;

    // Инициализация препятствий
    energy = new Energy(100,250,1);
    brick = new Brick(600,275,1);

    BufFig[0] = energy;
    BufFig[1] = brick;

    curLamp = BufLamp[1]; // сначала обычная лампа
}

MainWindow::~MainWindow() {
    delete point;
    delete lamp;
    delete magicLamp;
    delete brokenLamp;
    delete energy;
    delete brick;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int newX = curLamp->getX();
    int newY = curLamp->getY();

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
    default:
        QMainWindow::keyPressEvent(event);
        return;
    }

    int tempX = newX;
    int tempY = newY;
    bool collisionDetected = false;

    for (int i = 0; i < 2; i++) {
        curLamp->moveTo(nullptr, tempX, tempY);
        if (CheckCollision(curLamp, BufFig[i])) {
            collisionDetected = true;

            // Матрица переходов: [текущая лампа][объект] -> новая лампа
            // Индексы ламп: 0 - brokenLamp, 1 - lamp, 2 - magicLamp
            // ИНдексы препятствий: 0 - energy, 1 - brick
            Lamp* transitionMatrix[3][2] = {
                /* brokenLamp */ {BufLamp[1], BufLamp[0]},  // energy -> lamp, brick -> brokenLamp
                /* lamp */      {BufLamp[2], BufLamp[0]},  // energy -> magicLamp, brick -> brokenLamp
                /* magicLamp */ {BufLamp[2], BufLamp[1]}   // energy -> magicLamp, brick -> lamp
            };

            int currentType = curLamp->id(); // текущий тип лампы, полиморфный вызов

            // Определяем тип объекта (0 - energy, 1 - brick)
            int objectType;
            if (i == 0) {
                objectType = 0; // energy
            } else {
                objectType = 1; // brick
            }

            // Получаем новую лампу из матрицы переходов
            curLamp = transitionMatrix[currentType][objectType];

            // Перемещаем лампу в "безопасное" место
            tempX = 400;
            tempY = 250;
            curLamp->moveTo(nullptr, tempX, tempY);

            break;
        }
    }

    if (!collisionDetected) {
        curLamp->moveTo(nullptr, newX, newY);
    }

    update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.fillRect(rect(), Qt::white);
    curLamp->moveTo(&painter, curLamp->getX(), curLamp->getY());

    for (int i = 0; i < 2; i++) {
        BufFig[i]->Show(&painter);
    }
}

int MainWindow::CheckCollision(Lamp *l, Fig *f)
{
    int dx = abs(l->getX() - f->getX());
    int dy = abs(l->getY() - f->getY());

    if (dx < 50 && dy < 50) {
        return 1; // есть столкновение
    } else {
        return 0; // нет столкновения
    }
}
