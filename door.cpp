#include "door.h"
#define PATH_IMG "../lab_5_2/images/door.PNG"

door::door(int X, int Y){
    posX = X;
    posY = Y;
}

QRectF door::boundingRect() const{
    return QRectF(posX,posY,30,30);
}

void door::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(QImage(PATH_IMG));
    painter->drawRect(boundingRect());
}
