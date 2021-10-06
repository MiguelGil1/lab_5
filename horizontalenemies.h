#ifndef HORIZONTALENEMIES_H
#define HORIZONTALENEMIES_H

#include <QGraphicsItem>
#include <QPainter>

#include <vector>
#include <list>

#include "bricks.h"
#include "iron.h"

class horizontalEnemies : public QGraphicsItem{
public:
    horizontalEnemies(int X, int Y);
    //horizontalEnemies(int X, int Y, QGraphicsScene *scene);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //void moveEnemy(std::list <bricks *> mBricks, std::vector <iron *> mIron);

    int getPosX() const;
    void setPosX(int value);

    int getPosY() const;
    void setPosY(int value);

    int getMovimiento() const;
    void setMovimiento(int value);

    int getOriginalX() const;
    void setOriginalX(int value);

    int getOriginalY() const;
    void setOriginalY(int value);

private:
    //QGraphicsScene *mScene;
    int movimiento = 1;
    int posX;
    int posY;
    int  originalX;
    int  originalY;
};

#endif // HORIZONTALENEMIES_H
