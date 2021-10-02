#include <mainCharacter.h>

mainCharacter::mainCharacter(int posX, int posY, int mov, int tam){
    positionXmainCharacter = posX;
    positionYmainCharacter = posY;
    movement = mov;
    size = tam;
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
