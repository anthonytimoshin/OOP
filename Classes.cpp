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
/////////////////////////////////////////////////
/// \brief Lamp::Lamp
/// \param x
/// \param y
/// \param visible
///
Lamp::Lamp(int x, int y, bool visible)
    : Point(x, y, visible){}

int Lamp::id() {
    return 1;
}

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
///////////////////////////////////////
/// \brief BrokenLamp::BrokenLamp
/// \param x
/// \param y
/// \param visible
///
BrokenLamp::BrokenLamp(int x, int y, bool visible)
    : Lamp(x, y, visible) {}

int BrokenLamp::id() {
    return 0;
}

void BrokenLamp::Show(QPainter* painter) {
    isVisible = true;
    if (painter) {
        // Основание лампы
        painter->setBrush(Qt::darkGray);
        painter->drawRect(x, y + 100, 60, 15);

        // Стойка лампы
        painter->setPen(QPen(Qt::gray, 8));
        painter->drawLine(x + 30, y + 40, x + 30, y + 100);
        painter->setPen(Qt::NoPen);

        // Лампочка
        painter->setBrush(Qt::red);
        painter->drawEllipse(x + 25, y + 30, 10, 10);
    }
}

void BrokenLamp::Hide(QPainter* painter) {
    isVisible = false;
    if (painter) {
        // Стираем область, где находится лампа
        painter->setBrush(Qt::white);
        painter->drawRect(x, y, 60, 115);
    }
}
///////////////////////////////////////
/// \brief MagicLamp::MagicLamp
/// \param x
/// \param y
/// \param visible
///
MagicLamp::MagicLamp(int x, int y, bool visible)
    : Lamp(x, y, visible) {}

int MagicLamp::id() {
    return 2;
}

void MagicLamp::Show(QPainter* painter)
{
    isVisible = true;
    if (painter) {
        // Основание лампы
        painter->setBrush(Qt::darkGray);
        painter->drawRect(x, y + 100, 60, 15);

        // Стойка лампы
        painter->setPen(QPen(Qt::gray, 8));
        painter->drawLine(x + 30, y + 40, x + 30, y + 100);

        // Лампочка
        painter->setBrush(Qt::white);
        painter->drawEllipse(x + 25, y + 30, 10, 10);

        // Абажур
        QPolygon lampshade;
        lampshade << QPoint(x, y + 40)
                  << QPoint(x + 60, y + 40)
                  << QPoint(x + 45, y)
                  << QPoint(x + 15, y);
        painter->setPen(Qt::NoPen);
        painter->setBrush(Qt::yellow);
        painter->drawPolygon(lampshade);

        // Абажур 2
        QPolygon lampshade2;
        lampshade2 << QPoint(x, y + 80)
                  << QPoint(x + 60, y + 80)
                  << QPoint(x + 45, y + 40)
                  << QPoint(x + 15, y + 40);
        painter->setPen(Qt::NoPen);
        painter->setBrush(Qt::red);
        painter->drawPolygon(lampshade2);
    }
}

void MagicLamp::Hide(QPainter* painter) {
    isVisible = false;
    if (painter) {
        // Стираем область, где находится лампа
        painter->setBrush(Qt::white);
        painter->drawRect(x, y, 60, 155);
    }
}



///////////////////////////////////////
/// \brief Fig::Fig
/// \param x
/// \param y
/// \param visible
///
Fig::Fig(int x, int y, bool visible)
    : Point(x, y, visible) {};

void Fig::Show(QPainter* painter) {
    isVisible = true;
    if (painter) {
        painter->setBrush(Qt::darkGray);
        painter->drawEllipse(x, y, 100, 100);
    }
}

void Fig::Hide(QPainter* painter) {
    isVisible = false;
    if (painter) {
        // Стираем область, где находится лампа
        painter->setBrush(Qt::white);
        painter->drawEllipse(x, y, 100, 100);
    }
}
/////////////////////////////////////
/// \brief Energy::Energy
/// \param x
/// \param y
/// \param visible
///
Energy::Energy(int x, int y, bool visible)
    : Fig(x, y, visible) {};

void Energy::Show(QPainter* painter) {
    isVisible = true;
    if (painter) {
        painter->setBrush(Qt::yellow);
        painter->drawEllipse(x, y, 75, 75);
        painter->setBrush(Qt::red);
        painter->drawEllipse(x+25, y+25, 25, 25);
    }
}

void Energy::Hide(QPainter* painter) {
    isVisible = false;
    if (painter) {
        painter->setBrush(Qt::white);
        painter->drawEllipse(x, y, 100, 100);
    }
}
/////////////////////////////////////////
/// \brief Brick::Brick
/// \param x
/// \param y
/// \param visible
///
Brick::Brick(int x, int y, bool visible)
    : Fig(x, y, visible) {};

void Brick::Show(QPainter* painter) {
    isVisible = true;
    if (painter) {
        painter->setBrush(Qt::black);
        painter->drawRect(x, y, 75, 20);
    }
};

void Brick::Hide(QPainter* painter) {
    isVisible = false;
    if (painter) {
        painter->setBrush(Qt::white);
        painter->drawRect(x, y, 75, 20);
    }
};
