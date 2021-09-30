#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <vector>
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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void readWorld();
    void loseLife();   
    ~MainWindow();
protected:
    bool detectColision();
    void  keyPressEvent(QKeyEvent *event);
public slots:
    void  OnTimeOut();
private:
    QGraphicsScene *scene;
    QTimer *timer;
    Ui::MainWindow *ui;
    int world[13][31];
    int Lives = 3;
    int Time = 300;  
    vector <QGraphicsEllipseItem *> characters;
    vector <QGraphicsRectItem *> worldRect;
    vector <QColor> Colors;
    vector <QPen> Pens;
    vector <QBrush> Brushes;
    int tam = 30;
    int movement = 10;
    int positionXmainCharacter = (tam/2)+5;
    int positionYmainCharacter = (tam/2)+5;
    QGraphicsEllipseItem *bomb;
};
#endif // MAINWINDOW_H
