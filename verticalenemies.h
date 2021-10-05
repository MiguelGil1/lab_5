#ifndef VERTICALENEMIES_H
#define VERTICALENEMIES_H

#include <QGraphicsItem>
#include <QPainter>

class verticalEnemies : public QGraphicsItem{
public:
    verticalEnemies(int X, int Y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    int movimiento = 1;
    int posX;
    int posY;
};

#endif // VERTICALENEMIES_H
