#include "verticalenemies.h"
verticalEnemies::verticalEnemies(int X, int Y){
    posX = X;
    posY = Y;
}
QRectF verticalEnemies::boundingRect() const{
    return QRectF(posX,posY,30,30);
}

void verticalEnemies::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}
