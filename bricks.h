#ifndef BRICKS_H
#define BRICKS_H

#include <QGraphicsItem>
#include <QPainter>


class bricks : public QGraphicsItem{
public:
    bricks(int X, int Y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    int posX;
    int posY;
};

#endif // BRICKS_H
