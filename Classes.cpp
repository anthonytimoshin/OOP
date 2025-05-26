#include "Classes.h"

Point::Point(int x, int y, bool visible)
    : Location(x, y), isVisible(visible) {}

void Point::moveTo(QPainter *painter, int newX, int newY) {
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
        painter->setBrush(Qt::darkGray);
        painter->drawRect(x, y + 100, size, 15);
        painter->setPen(QPen(Qt::gray, 8));
        painter->drawLine(x + size / 2, y + 40, x + size / 2, y + 100);
        QPolygon lampshade;
        lampshade << QPoint(x, y + 40)
                  << QPoint(x + size, y + 40)
                  << QPoint(x + size * 3 / 4, y)
                  << QPoint(x + size / 4, y);
        painter->setPen(Qt::NoPen);
        painter->setBrush(color);
        painter->drawPolygon(lampshade);
        painter->setBrush(Qt::white);
        painter->drawEllipse(x + size / 2 - 5, y + 30, 10, 10);
    }
}

void Lamp::Hide(QPainter* painter) {
    isVisible = false;
    if (painter) {
        painter->setBrush(Qt::white);
        painter->drawRect(x, y, size, 115);
    }
}

void Lamp::moveTo(QPainter *painter, int newX, int newY) {
    Hide(painter);
    setX(newX);
    setY(newY);
    Show(painter);
}

TableLamp::TableLamp(int x, int y, bool visible)
    : Lamp(x, y, visible) {
    color = Qt::green;
    size = 50;
}

void TableLamp::Show(QPainter* painter) {
    Lamp::Show(painter);
}

void TableLamp::Hide(QPainter* painter) {
    Lamp::Hide(painter);
}

FloorLamp::FloorLamp(int x, int y, bool visible)
    : Lamp(x, y, visible) {
    color = Qt::blue;
    size = 80;
}

void FloorLamp::Show(QPainter* painter) {
    Lamp::Show(painter);
}

void FloorLamp::Hide(QPainter* painter) {
    Lamp::Hide(painter);
}

WallLamp::WallLamp(int x, int y, bool visible)
    : FloorLamp(x, y, visible) {
    color = Qt::red;
    size = 40;
}

void WallLamp::Show(QPainter* painter) {
    FloorLamp::Show(painter);
}

void WallLamp::Hide(QPainter* painter) {
    FloorLamp::Hide(painter);
}

CeilingLamp::CeilingLamp(int x, int y, bool visible)
    : WallLamp(x, y, visible) {
    color = Qt::cyan;
    size = 70;
}

void CeilingLamp::Show(QPainter* painter) {
    WallLamp::Show(painter);
}

void CeilingLamp::Hide(QPainter* painter) {
    WallLamp::Hide(painter);
}

RedStar::RedStar(int x, int y) : x(x), y(y) {}

void RedStar::interactWithLamp(Lamp* lamp) {
    lamp->setColor(Qt::darkRed);
    if (dynamic_cast<TableLamp*>(lamp)) {
        lamp->setSize(55);
    } else if (dynamic_cast<FloorLamp*>(lamp)) {
        lamp->setSize(85);
    } else if (dynamic_cast<WallLamp*>(lamp)) {
        lamp->setSize(45);
    } else if (dynamic_cast<CeilingLamp*>(lamp)) {
        lamp->setSize(75);
    }
}

void RedStar::draw(QPainter* painter) {
    if (painter) {
        painter->setBrush(Qt::red);
        painter->drawEllipse(x, y, 30, 30);
    }
}

BlueStar::BlueStar(int x, int y) : x(x), y(y) {}

void BlueStar::interactWithLamp(Lamp* lamp) {
    lamp->setColor(Qt::darkBlue);
    if (dynamic_cast<TableLamp*>(lamp)) {
        lamp->setSize(60);
    } else if (dynamic_cast<FloorLamp*>(lamp)) {
        lamp->setSize(90);
    } else if (dynamic_cast<WallLamp*>(lamp)) {
        lamp->setSize(50);
    } else if (dynamic_cast<CeilingLamp*>(lamp)) {
        lamp->setSize(80);
    }
}

void BlueStar::draw(QPainter* painter) {
    if (painter) {
        painter->setBrush(Qt::blue);
        painter->drawEllipse(x, y, 30, 30);
    }
}

GreenStar::GreenStar(int x, int y) : x(x), y(y) {}

void GreenStar::interactWithLamp(Lamp* lamp) {
    lamp->setColor(Qt::darkGreen);
    if (dynamic_cast<TableLamp*>(lamp)) {
        lamp->setSize(50);
    } else if (dynamic_cast<FloorLamp*>(lamp)) {
        lamp->setSize(80);
    } else if (dynamic_cast<WallLamp*>(lamp)) {
        lamp->setSize(40);
    } else if (dynamic_cast<CeilingLamp*>(lamp)) {
        lamp->setSize(70);
    }
}

void GreenStar::draw(QPainter* painter) {
    if (painter) {
        painter->setBrush(Qt::green);
        painter->drawEllipse(x, y, 30, 30);
    }
}

YellowStar::YellowStar(int x, int y) : x(x), y(y) {}

void YellowStar::interactWithLamp(Lamp* lamp) {
    lamp->setColor(Qt::darkYellow);
    if (dynamic_cast<TableLamp*>(lamp)) {
        lamp->setSize(65);
    } else if (dynamic_cast<FloorLamp*>(lamp)) {
        lamp->setSize(95);
    } else if (dynamic_cast<WallLamp*>(lamp)) {
        lamp->setSize(55);
    } else if (dynamic_cast<CeilingLamp*>(lamp)) {
        lamp->setSize(85);
    }
}

void YellowStar::draw(QPainter* painter) {
    if (painter) {
        painter->setBrush(Qt::yellow);
        painter->drawEllipse(x, y, 30, 30);
    }
}
