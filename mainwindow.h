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
    int tam = 30;
    int positionXcharacters = tam;
    int positionYcharacters = tam;
};
#endif // MAINWINDOW_H
