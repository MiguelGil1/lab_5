#include "horizontalenemies.h"

horizontalEnemies::horizontalEnemies(int X, int Y){
    posX = X;
    posY = Y;
    originalX = X;
    originalY = Y;
}

QRectF horizontalEnemies::boundingRect() const{
    return QRectF(posX,posY,30,30);
}

void horizontalEnemies::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

int horizontalEnemies::getPosX() const{
    return posX;
}

void horizontalEnemies::setPosX(int value){
    posX = value;
}

int horizontalEnemies::getPosY() const{
    return posY;
}

void horizontalEnemies::setPosY(int value){
    posY = value;
}

int horizontalEnemies::getMovimiento() const{
    return movimiento;
}

void horizontalEnemies::setMovimiento(int value){
    movimiento = value;
}

int horizontalEnemies::getOriginalX() const{
    return originalX;
}

void horizontalEnemies::setOriginalX(int value){
    originalX = value;
}

int horizontalEnemies::getOriginalY() const{
    return originalY;
}

void horizontalEnemies::setOriginalY(int value){
    originalY = value;
}
