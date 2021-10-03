#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H
//IMPORTACION DE LIBRERIAS

#include <QGraphicsItem>
#include <QPainter>

//FIN IMPORTACION DE LIBRERIAS

class mainCharacter: public QGraphicsItem{
public:
    mainCharacter(int posX,int posY, int mov, int tam); //Constructor

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void changePosition();

    int getMovement() const;
    void setMovement(int value);

    int getPositionXmainCharacter() const;
    void setPositionXmainCharacter(int value);

    int getPositionYmainCharacter() const;
    void setPositionYmainCharacter(int value);

    int getSize() const;
    void setSize(int value);

    int getLives() const;
    void setLives(int value);

private:
    int size;                   //Tamaño del personaje principal
    int movement;               //Pixeles que se mueve
    int positionXmainCharacter; //Posicion en el eje X del PJ
    int positionYmainCharacter; //Posicion en el eje Y del PJ
    int Lives = 3;              //Vidas del personaje principal

};
#endif // MAINCHARACTER_H