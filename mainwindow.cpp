#include "mainwindow.h"
#include "ui_mainwindow.h"

#define PATH_WORLD "../lab_5_2/worlds/world.txt"
#define PATH_IMG "../lab_5/images/ladrillo.PNG"

mainCharacter mainChr(0,0,30,30);
world world;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();

    QImage im(PATH_IMG);
    //QImage imBomb(PATH_BOMB);
    //Agregando colores
    Colors.push_back(QColor(187,187,187));
    Colors.push_back(QColor(255,0,0));
    Colors.push_back(QColor(0,0,0));
    //Fin de agregar colores

    //Agregando brochas
    Brushes.push_back(QBrush(Colors.at(0)));
    Brushes.push_back(QBrush(im));
    Brushes.push_back(QBrush(Colors.at(1)));
    Brushes.push_back(QBrush(Colors.at(2)));
    //Brushes.push_back(QBrush(imBomb));
    //Fin de agregar brochas

    //Agregando lapices
    Pens.push_back( QPen (Qt::black, 0, Qt::SolidLine,Qt::RoundCap, Qt::RoundJoin));
    //Fin agregar lapices

    int *worldMatrix = world.readWorld(PATH_WORLD);

    PJ = scene->addEllipse(mainChr.getPositionXmainCharacter(), mainChr.getPositionYmainCharacter(),mainChr.getSize(),mainChr.getSize(),Pens.at(0),Brushes.at(2));

    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

MainWindow::~MainWindow(){
    //mainChr.~mainCharacter();
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
        case Qt::Key_A:{
            //Movimiento a la izquierda
            //Hay movimiento en la direccion en la que decrece el eje X
            int posX = mainChr.getPositionXmainCharacter();
            posX -= 30;
            mainChr.setPositionXmainCharacter(posX);
            PJ->setPos(mainChr.getPositionXmainCharacter(),mainChr.getPositionYmainCharacter());
            break;
        }
        case Qt::Key_S:{
            //Movimiento abajo
            //Hay moviemiento en el la direccion en la que crece el eje Y
            int posY = mainChr.getPositionYmainCharacter();
            posY += 30;
            mainChr.setPositionYmainCharacter(posY);
            PJ->setPos(mainChr.getPositionXmainCharacter(),mainChr.getPositionYmainCharacter());
            break;
        }
        case Qt::Key_D:{
            //Movimiento a la derecha
            //Hay movimiento en la direccion en la que crece el eje X
            int posX = mainChr.getPositionXmainCharacter();
            posX += 30;
            mainChr.setPositionXmainCharacter(posX);
            PJ->setPos(mainChr.getPositionXmainCharacter(),mainChr.getPositionYmainCharacter());
            break;
        }
        case Qt::Key_W:{
            //Movimiento arriba
            //Hay movimiento en la direccion en la cual decrece el eje Y
            int posY = mainChr.getPositionYmainCharacter();
            posY -= 30;
            mainChr.setPositionYmainCharacter(posY);
            PJ->setPos(mainChr.getPositionXmainCharacter(),mainChr.getPositionYmainCharacter());
            break;
        }
    }
}

