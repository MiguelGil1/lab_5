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

#include <vector>
#include <list>

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
    void loseLife();                      //Metodo que merma la vida
    void readWorld();                     //Metodoq que se ecarga de montar el mundo
    void explosion();                     //Metodo que se encarga de explotar la bomba
    bool detectColision();                //Evalua colisiones con todo el mundo en general
    bool detectColisionWithIron();        //Detecta coliiones conbloques de Hierro
    bool detectColisionWithBricks();      //Detecta colisiones con los ladrillos
    //bool detectColisionWithEnemies();     //Detecta colisiones con enemigos
private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;//Declaracion de la escena
    QTimer *timer;        //Timer dpara decrementar cada 1 segundo el tiempo

    mainCharacter *PJ;           //Jugador Principal
    bomb *bomba;                 //Bomba
    bomb *bomba1;
    bomb *bomba2;
    bomb *bomba3;
    bomb *bomba4;
    bricks *ladrillo;            //Ladrillo
    iron *hierro;                //Hierro
    list <bricks *> mBricks;     //Lista de tipo objetos ladrillo
    vector <iron *> mIron;       //Lista de objetos tipo Iron


    int Time = 300;
    bool activeBomb = false;

    array <array<int,31>,13> worldMatrix;
};
#endif // MAINWINDOW_H
