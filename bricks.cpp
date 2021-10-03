#include "bricks.h"
#define PATH_IMG "../lab_5_2/images/ladrillo.PNG"
bricks::bricks(int X, int Y){
    posX = X;
    posY = Y;
}
QRectF bricks::boundingRect() const{
    return QRectF(posX,posY,30,30);
}

void bricks::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    //painter->setBrush(Qt::black);
    painter->setBrush(QImage(PATH_IMG));
    painter->drawRect(boundingRect());
}
