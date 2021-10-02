#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//Inicio de importacion de Librerias

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QKeyEvent>

#include <mainCharacter.h>
#include <world.h>

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
protected:
    void keyPressEvent(QKeyEvent *event); //Metodo que detecta que tecla fue presionada
    void showWorld(array <array<int,31>,13>);
private:
    Ui::MainWindow *ui;

    //Declaracion de la escena
    QGraphicsScene *scene;
    //Fin declaracion de la escena

    //Vectores de decorado
    vector <QColor> Colors;  //Vector de Colores
    vector <QPen> Pens;      //Vector de Lapices
    vector <QBrush> Brushes; //Vector de Brushes
    //Fin de vectores para decorado

    QGraphicsEllipseItem *PJ;                   //Jugador Principal
    list <QGraphicsEllipseItem *> enemies;      //Lista de enemigos
    vector <QGraphicsRectItem *> iron;          //Lista de cuadrados de hierra
    list <QGraphicsRectItem *> bricks;          //Lista de ladrillos
    QGraphicsEllipseItem *bomb;                 //Bomba
};
#endif // MAINWINDOW_H
