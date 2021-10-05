#include "horizontalenemies.h"

horizontalEnemies::horizontalEnemies(int X, int Y){
    posX = X;
    posY = Y;
}
QRectF horizontalEnemies::boundingRect() const{
    return QRectF(posX,posY,30,30);
}

void horizontalEnemies::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}
