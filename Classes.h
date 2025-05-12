#ifndef CLASSES_H
#define CLASSES_H

#include <QPainter>

class Location {
protected:
    int x;
    int y;
public:
    virtual ~Location() = default;
    Location(int x = 0, int y = 0) : x(x), y(y) {}

    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
};

class Point : public Location {
protected:
    bool isVisible;
public:
    Point(int x = 0, int y = 0, bool visible = true);
    virtual ~Point() = default; // Виртуальный деструктор
    void moveTo(QPainter* painter,
                int newX, int newY);
    void Hide(QPainter* painter);
    void Show(QPainter* painter);
    bool getVisibility() const;
    void setVisibility(bool visible);
};

class Lamp : public Point {
public:
    Lamp(int x = 0, int y = 0, bool visible = true);
    void moveTo(QPainter* painter,
                int newX, int newY);
     void Show(QPainter* painter);
     void Hide(QPainter* painter);
};

#endif // CLASSES_H
