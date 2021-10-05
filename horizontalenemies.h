#ifndef HORIZONTALENEMIES_H
#define HORIZONTALENEMIES_H

#include <QGraphicsItem>
#include <QPainter>

class horizontalEnemies : public QGraphicsItem{
public:
    horizontalEnemies(int X, int Y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    int movimiento = 1;
    int posX;
    int posY;
};

#endif // HORIZONTALENEMIES_H
