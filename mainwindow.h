#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <vector>
#include <list>
#include <QGraphicsRectItem>
#include <fstream>
#include <iostream>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);      
    ~MainWindow();
protected:
    //Metodos que determinan colisiones
    bool detectColision();
    bool detectColisionWithIron();
    bool detectColisionWithBricks();
    bool detectColisionWithEnemies();
    //Fin metodos que determinan colisiones

    //Metodo que lee el mundo desde archivo
    void readWorld();
    //Fin metodo que lee mundo

    //Metodo que resta vidas
    void loseLife();
    //Fin metodo que resta vidas

    //Metodo que detecta tecla presionada
    void  keyPressEvent(QKeyEvent *event);
    //Fin metodo que detecta tecla presionada
public slots:
    //Metodo que realiza el decremento de del tiempo
    void  OnTimeOut();
    //Fin metodo que realiza el decremento de del tiempo

    //Metodo que realiza la explosion
    void explosion();
    //Fin metodo que realiza la explosion
private:
    Ui::MainWindow *ui;

    //Declaracion de la escena
    QGraphicsScene *scene;
    //Fin declaracion de la escena

    //Declaracion de Timers
    QTimer *timer;    //Timer dpara decrementar cada 1 segundo el tiempo
    QTimer *blastTime;//Timer para la explosion
    //Fin timers

    //Atributos de mundo
    int world[13][31];                          //Arreglo que almacena el mundo
    int Lives = 3;                              //Vidas
    int Time = 300;                             //Tiempo para completar el mundo
    int tam = 30;                               //Tamaño de cada cuadrado
    list <QGraphicsEllipseItem *> characters;   //Lista de personajes
    vector <QGraphicsRectItem *> iron;          //Lista de cuadrados de hierra
    list <QGraphicsRectItem *> bricks;          //Lista de ladrillos
    QGraphicsEllipseItem *bomb;                 //Bomba
    bool exploited = true;                       //Booleano que es true si se no hay bombas, false si hay bombas
    //Fin atributos de Mundo

    //Vectores de decorado
    vector <QColor> Colors;
    vector <QPen> Pens;
    vector <QBrush> Brushes;
    //Fin de vectores para decorado

    //Atributos de personaje principal
    int movement = 10;                      //Pixeles que se mueve
    int positionXmainCharacter = (tam/2)+5; //Posicion en el eje X del PJ
    int positionYmainCharacter = (tam/2)+5; //Posicion en el eje Y del PJ
    //Fin de atributos de perosnaje principal





};
#endif // MAINWINDOW_H
