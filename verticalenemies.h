#ifndef VERTICALENEMIES_H
#define VERTICALENEMIES_H

#include <QGraphicsItem>
#include <QPainter>

class verticalEnemies : public QGraphicsItem{
public:
    verticalEnemies(int X, int Y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getMovimiento() const;
    void setMovimiento(int value);

    int getPosX() const;
    void setPosX(int value);

    int getPosY() const;
    void setPosY(int value);

    int getOriginalY() const;
    void setOriginalY(int value);

    int getOriginalX() const;
    void setOriginalX(int value);
private:
    int movimiento = 1;
    int posX;
    int posY;
    int  originalY;
    int  originalX;
};

#endif // VERTICALENEMIES_H
