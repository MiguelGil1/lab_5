#ifndef IRON_H
#define IRON_H

#include <QGraphicsItem>
#include <QPainter>

class iron : public QGraphicsItem{
public:
    iron(int X, int Y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    int posX;
    int posY;
};

#endif // IRON_H
