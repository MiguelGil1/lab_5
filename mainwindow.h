#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//Inicio de importacion de Librerias

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QKeyEvent>

#include "mainCharacter.h"
#include "bomb.h"
#include "bricks.h"
#include "iron.h"
#include "door.h"
#include "horizontalenemies.h"
#include "verticalenemies.h"

#include <vector>
#include <list>
#include <array>

#include <stdlib.h>
#include <time.h>

#include <fstream>
#include <iostream>

//Fin de importacion de librerias
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void  OnTimeOut(); //Metodo que realiza el decremento de del tiempo
protected:
    void keyPressEvent(QKeyEvent *event); //Metodo que detecta que tecla fue presionada
    void win();                           //Metodoque se invoca cuando se gana
    void loseLife();                      //Metodo que merma la vida
    void readWorld();                     //Metodoq que se ecarga de montar el mundo
    void explosion();                     //Metodo que se encarga de explotar la bomba
    bool detectColision();                //Evalua colisiones con todo el mundo en general
    bool detectColisionWithIron();        //Detecta coliiones conbloques de Hierro
    bool detectColisionWithBricks();      //Detecta colisiones con los ladrillos
    bool detectColisionWithEnemies();     //Detecta colisiones con enemigos
private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;//Declaracion de la escena
    QTimer *timer;        //Timer dpara decrementar cada 1 segundo el tiempo

    //************************Declaracion de objetos de la escena************************//

    mainCharacter *PJ;                     //Jugador Principal
    bomb *bomba;                           //Bomba - Epicentro
    bomb *bomba1;                          //Bomba 1
    bomb *bomba2;                          //Bomba 2
    bomb *bomba3;                          //Bomba 3
    bomb *bomba4;                          //Bomba 4
    door *puerta;                          //Puerta
    bricks *ladrillo;                      //Ladrillo
    iron *hierro;                          //Hierro
    horizontalEnemies *hEnemy;             //Enemigo con movimiento horizontal
    verticalEnemies *vEnemy;               //Enemigo con movimiento vertical
    list <bricks *> mBricks;               //Lista de tipo objetos ladrillo
    vector <iron *> mIron;                 //Lista de objetos tipo Iron
    list <horizontalEnemies *> mH_Enemies; //Lista de enemigos con movimiento horizontal
    list <verticalEnemies *> mV_Enemies;   //Lista de enemigos con movimiento vertical

    //**************************Fin declaracion de objetos de la escena*********************//


    int Time = 300;          //Tiempo para cada vida
    bool activeBomb = false; //Boolenao que contiene falso si no hay bpbas activas en el mapa, de lo contrario almacena true

    array <array<int,31>,13> worldMatrix; //Arreglo de aareglos que contiene el mapa leido desde el .txt
};
#endif // MAINWINDOW_H
