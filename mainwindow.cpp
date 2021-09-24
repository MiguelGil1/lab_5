#include "mainwindow.h"
#include "ui_mainwindow.h"

#define PATH_WORLD "../lab_5/worlds/world.txt"
#define PATH_IMG "../lab_5/images/world.txt"
#define tam 25
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    readWorld();

    int positionX = 0;
    int positionY = 0;

    QImage im(PATH_IMG);
    QColor color1("#2244aa");
    QBrush Brush1(color1);
    QPen pen1(Qt::blue, 3, Qt::SolidLine,Qt::RoundCap, Qt::RoundJoin);

    for(int rows = 0; rows < 13; rows++){
        positionX = 0;
        for(int columns = 0; columns < 31; columns++){
            if(world[rows][columns] != 0){
                scene->addRect(positionX,positionY,tam,tam,pen1,Brush1);
            }
            positionX += tam;
            /*if(world[rows][columns] == 1){
                //Se agregan cuadrados de hierro
            }else if(world[rows][columns] == 2){
                //Se agregan ladrillos
            }*/
        }
        positionY += tam;
    }
    ui->graphicsView->setScene(scene);
    //ui->graphicsView->setSceneRect();
    ui->graphicsView->show();
}

void MainWindow::readWorld(){
    string line = "";
    string valor = "";
    int contRow = 0;
    ifstream infile;
    infile.open(PATH_WORLD);
    while(!infile.eof()){
        infile >> line;
        for(int  i = 0; i < int(line.length()); i++){
            valor[0] = line[i];
            world[contRow][i] = stoi(valor);
        }
        contRow++;
    }
    //investigar SetSceneRect(4parametros);
}

MainWindow::~MainWindow(){
    delete ui;
}

