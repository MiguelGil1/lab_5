#include "bomb.h"

bomb::bomb(int X, int Y){
    posX = X;
    posY = Y;
}

QRectF bomb::boundingRect() const{
    return QRectF(posX,posY,30,30);
}

void bomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect());
}

int bomb::getContador() const{
    return contador;
}

void bomb::setContador(int value){
    contador = value;
}
