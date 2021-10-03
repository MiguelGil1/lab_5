#ifndef BOMB_H
#define BOMB_H

#include <QGraphicsItem>
#include <QPainter>

class bomb : public QGraphicsItem{
public:
    bomb(int X, int Y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void explosion();
    int getContador() const;
    void setContador(int value);

private:
    int posX;
    int posY;
    int contador = 0;
};

#endif // BOMB_H
