#include "verticalenemies.h"
verticalEnemies::verticalEnemies(int X, int Y){
    posX = X;
    posY = Y;
    originalY = Y;
    originalX = X;
}
QRectF verticalEnemies::boundingRect() const{
    return QRectF(posX,posY,30,30);
}

void verticalEnemies::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

int verticalEnemies::getMovimiento() const{
    return movimiento;
}

void verticalEnemies::setMovimiento(int value){
    movimiento = value;
}

int verticalEnemies::getPosX() const{
    return posX;
}

void verticalEnemies::setPosX(int value){
    posX = value;
}

int verticalEnemies::getPosY() const{
    return posY;
}

void verticalEnemies::setPosY(int value){
    posY = value;
}

int verticalEnemies::getOriginalY() const{
    return originalY;
}

void verticalEnemies::setOriginalY(int value){
    originalY = value;
}

int verticalEnemies::getOriginalX() const{
    return originalX;
}

void verticalEnemies::setOriginalX(int value){
    originalX = value;
}
