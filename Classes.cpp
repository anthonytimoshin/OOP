#include "Classes.h"

Point::Point(int x, int y, bool visible)
    : Location(x, y), isVisible(visible) {}

void Point::moveTo(QPainter *painter,
                   int newX, int newY)
{
    Hide(painter);
    setX(newX);
    setY(newY);
    Show(painter);
}

void Point::Hide(QPainter* painter) {
    isVisible = false;
    if (painter) {
        painter->setBrush(Qt::white);
        painter->drawEllipse(x, y, 20, 20);
    }
}

void Point::Show(QPainter* painter) {
    isVisible = true;
    if (painter) {
        painter->setBrush(Qt::red);
        painter->drawEllipse(x, y, 20, 20);
    }
}

bool Point::getVisibility() const {
    return isVisible;
}

void Point::setVisibility(bool visible) {
    isVisible = visible;
}

Lamp::Lamp(int x, int y, bool visible)
    : Point(x, y, visible) {}

void Lamp::Show(QPainter* painter) {
    isVisible = true;
    if (painter) {
        // Основание лампы
        painter->setBrush(Qt::darkGray);
        painter->drawRect(x, y + 100, 60, 15);

        // Стойка лампы
        painter->setPen(QPen(Qt::gray, 8));
        painter->drawLine(x + 30, y + 40, x + 30, y + 100);

        // Абажур
        QPolygon lampshade;
        lampshade << QPoint(x, y + 40)
                  << QPoint(x + 60, y + 40)
                  << QPoint(x + 45, y)
                  << QPoint(x + 15, y);
        painter->setPen(Qt::NoPen);
        painter->setBrush(Qt::yellow);
        painter->drawPolygon(lampshade);

        // Лампочка
        painter->setBrush(Qt::white);
        painter->drawEllipse(x + 25, y + 30, 10, 10);
    }
}

void Lamp::Hide(QPainter* painter) {
    isVisible = false;
    if (painter) {
        // Стираем область, где находится лампа
        painter->setBrush(Qt::white);
        painter->drawRect(x, y, 60, 115);
    }
}

void Lamp::moveTo(QPainter *painter,
                   int newX, int newY)
{
    Hide(painter);
    setX(newX);
    setY(newY);
    Show(painter);
}
