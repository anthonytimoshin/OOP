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

class Identifiable {
public:
    virtual ~Identifiable() = default;
    virtual int id() = 0; // Чисто виртуальный метод
};

class Point : public Location {
protected:
    bool isVisible;
public:
    Point(int x = 0, int y = 0, bool visible = true);
    virtual ~Point() = default;
    void moveTo(QPainter* painter,
                int newX, int newY);
    virtual void Hide(QPainter* painter) = 0;
    virtual void Show(QPainter* painter) = 0;
    bool getVisibility() const;
    void setVisibility(bool visible);
};

//////////////////////////////////////
/// \brief The Lamp class
///
class Lamp : public Point, public Identifiable {
public:
    int id();
    Lamp(int x = 0, int y = 0, bool visible = true);
    virtual void Show(QPainter* painter);
    virtual void Hide(QPainter* painter);
};

class BrokenLamp: public Lamp {
public:
    int id();
    BrokenLamp(int x = 0, int y = 0, bool visible = true);
    virtual void Show(QPainter* painter);
    virtual void Hide(QPainter* painter);
};

class MagicLamp:public Lamp
{
public:
    int id();
    MagicLamp(int x = 0, int y = 0, bool visible = true);
    virtual void Show(QPainter* painter);
    virtual void Hide(QPainter* painter);

};

///////////////////////////////////////
/// \brief The Fig class
///
class Fig : public Point {
public:
    Fig(int x = 0, int y = 0, bool visible = true);
    virtual void Show(QPainter* painter);
    virtual void Hide(QPainter* painter);
};

class Energy : public Fig {
public:
    Energy(int x = 0, int y = 0, bool visible = true);
    virtual void Show(QPainter* painter);
    virtual void Hide(QPainter* painter);
};

class Brick : public Fig {
public:
    Brick(int x = 0, int y = 0, bool visible = true);
    virtual void Show(QPainter* painter);
    virtual void Hide(QPainter* painter);
};




#endif // CLASSES_H
