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
    virtual ~Point() = default;
    virtual void moveTo(QPainter* painter, int newX, int newY);
    virtual void Hide(QPainter* painter);
    virtual void Show(QPainter* painter);
    bool getVisibility() const;
    void setVisibility(bool visible);
};

class Lamp : public Point {
protected:
    Qt::GlobalColor color = Qt::yellow; // Default color
    int size = 60; // Default size (width of lamp base)
public:
    Lamp(int x = 0, int y = 0, bool visible = true);
    virtual void moveTo(QPainter* painter, int newX, int newY);
    virtual void Show(QPainter* painter);
    virtual void Hide(QPainter* painter);
    Qt::GlobalColor getColor() const { return color; }
    void setColor(Qt::GlobalColor c) { color = c; }
    int getSize() const { return size; }
    void setSize(int s) { size = s; }
};

class TableLamp : public Lamp {
public:
    TableLamp(int x = 0, int y = 0, bool visible = true);
    virtual void Show(QPainter* painter);
    virtual void Hide(QPainter* painter);
};

class FloorLamp : public Lamp {
public:
    FloorLamp(int x = 0, int y = 0, bool visible = true);
    virtual void Show(QPainter* painter);
    virtual void Hide(QPainter* painter);
};

class WallLamp : public FloorLamp {
public:
    WallLamp(int x = 0, int y = 0, bool visible = true);
    virtual void Show(QPainter* painter);
    virtual void Hide(QPainter* painter) ;
};

class CeilingLamp : public WallLamp {
public:
    CeilingLamp(int x = 0, int y = 0, bool visible = true);
    virtual void Show(QPainter* painter);
    virtual void Hide(QPainter* painter);
};

class Lamp; // Forward declaration

class Star {
public:
    virtual ~Star() = default;
    virtual void interactWithLamp(Lamp* lamp) = 0;
    virtual void draw(QPainter* painter) = 0;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
};

class RedStar : public Star {
private:
    int x, y;
public:
    RedStar(int x = 300, int y = 200);
    void interactWithLamp(Lamp* lamp) override;
    void draw(QPainter* painter) override;
    int getX() const override { return x; }
    int getY() const override { return y; }
};

class BlueStar : public Star {
private:
    int x, y;
public:
    BlueStar(int x = 500, int y = 200);
    void interactWithLamp(Lamp* lamp) override;
    void draw(QPainter* painter) override;
    int getX() const override { return x; }
    int getY() const override { return y; }
};

class GreenStar : public Star {
private:
    int x, y;
public:
    GreenStar(int x = 300, int y = 400);
    void interactWithLamp(Lamp* lamp) override;
    void draw(QPainter* painter) override;
    int getX() const override { return x; }
    int getY() const override { return y; }
};

class YellowStar : public Star {
private:
    int x, y;
public:
    YellowStar(int x = 500, int y = 400);
    void interactWithLamp(Lamp* lamp) override;
    void draw(QPainter* painter) override;
    int getX() const override { return x; }
    int getY() const override { return y; }
};

#endif // CLASSES_H
