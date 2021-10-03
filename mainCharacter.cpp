#include <mainCharacter.h>

mainCharacter::mainCharacter(int posX, int posY, int mov, int tam){
    positionXmainCharacter = posX;
    positionYmainCharacter = posY;
    movement = mov;
    size = tam;
}

QRectF mainCharacter::boundingRect() const{
    return QRectF(positionXmainCharacter,positionYmainCharacter,size,size);
}

void mainCharacter::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}

void mainCharacter::changePosition(){
    setPos(positionXmainCharacter,positionYmainCharacter);
}

int mainCharacter::getMovement() const{
    return movement;
}

void mainCharacter::setMovement(int value){
    movement = value;
}

int mainCharacter::getPositionXmainCharacter() const{
    return positionXmainCharacter;
}

void mainCharacter::setPositionXmainCharacter(int value){
    positionXmainCharacter = value;
}

int mainCharacter::getPositionYmainCharacter() const{
    return positionYmainCharacter;
}

void mainCharacter::setPositionYmainCharacter(int value){
    positionYmainCharacter = value;
}

int mainCharacter::getSize() const{
    return size;
}

void mainCharacter::setSize(int value){
    size = value;
}

int mainCharacter::getLives() const{
    return Lives;
}

void mainCharacter::setLives(int value){
    Lives = value;
}
