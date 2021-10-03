#include "iron.h"

iron::iron(int X, int Y){
    posX = X;
    posY = Y;
}
QRectF iron::boundingRect() const{
    return QRectF(posX,posY,30,30);
}

void iron::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(QColor(187,187,187));
    painter->drawRect(boundingRect());
}
