#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H
//IMPORTACION DE LIBRERIAS

#include <QGraphicsEllipseItem>

//FIN IMPORTACION DE LIBRERIAS

class mainCharacter{
public:
    mainCharacter(int posX,int posY, int mov, int tam); //Constructor
    //~mainCharacter();                                   //Destructor

    int getMovement() const;
    void setMovement(int value);

    int getPositionXmainCharacter() const;
    void setPositionXmainCharacter(int value);

    int getPositionYmainCharacter() const;
    void setPositionYmainCharacter(int value);

    int getSize() const;
    void setSize(int value);

private:
    int size;                   //Tamaño del personaje principal
    int movement;               //Pixeles que se mueve
    int positionXmainCharacter; //Posicion en el eje X del PJ
    int positionYmainCharacter; //Posicion en el eje Y del PJ

};
#endif // MAINCHARACTER_H
