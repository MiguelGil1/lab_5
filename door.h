#ifndef DOOR_H
#define DOOR_H

#include <QGraphicsItem>
#include <QPainter>

class door : public QGraphicsItem{
public:
    door(int X, int Y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    int posX;
    int posY;
};

#endif // DOOR_H
