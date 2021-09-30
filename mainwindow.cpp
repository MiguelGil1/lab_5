#include "mainwindow.h"
#include "ui_mainwindow.h"

#define PATH_WORLD "../lab_5/worlds/world.txt"
#define PATH_IMG "../lab_5/images/ladrillo.PNG"
//#define tam 30
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
    QColor color1(187,187,187);
    QColor color2(255,0,0);
    QBrush Brush1(color1);
    QBrush Brush2(im);
    QBrush Brush3(color2);
    QPen pen1(Qt::black, 3, Qt::SolidLine,Qt::RoundCap, Qt::RoundJoin);

    //Se inicia el TIMER//
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(OnTimeOut()));
    timer->start(1000);
    ui->time->display(Time);
    ui->lives->display(Lives);

    //Añadiendo el personaje principal al vector de personajes
    characters.push_back(scene->addEllipse(positionXcharacters,positionYcharacters,tam,tam,pen1,Brush3));
    //scene->addEllipse(positionX+tam,positionY+tam,tam,tam,pen1,Brush3);

    for(int rows = 0; rows < 13; rows++){
        positionX = 0;
        for(int columns = 0; columns < 31; columns++){
            if(world[rows][columns] == 1){
                //Se agregan cuadrados de hierro
                scene->addRect(positionX,positionY,tam,tam,pen1,Brush1);
            }else if(world[rows][columns] == 2){
                //Se agregan los ladrillos
                scene->addRect(positionX,positionY,tam,tam,pen1,Brush2);
            }
            positionX += tam;
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

void MainWindow::loseLife(){
    if(Lives != 0){
        Lives -= 1;
        Time = 300;
        ui->lives->display(Lives);
        ui->time->display(Time);
    }else{
        scene->clear();
        scene->addText("Game Over!");
    }
}

void MainWindow::KeyPressEvent(QKeyEvent *e){
    QString texto = "";
    //e->key devuelve entero, por eso hay que convertirlo a caracter
    texto += char(e->key());
    if(texto == "A"){
        //Movimiento a la izquierda
        //Hay movimiento en la direccion en la que decrece el eje X
        positionXcharacters -= tam;
    }else if(texto == "S"){
        //Movimiento abajo
        //Hay moviemiento en el la direccion en la que crece el eje Y
        positionYcharacters += tam;
    }else if(texto == "D"){
        //Movimiento a la derecha
        //Hay movimiento en la direccion en la que crece el eje X
        positionXcharacters += tam;
    }else if(texto == "W"){
        //Movimiento arriba
        //Hay movimiento en la direccion en la cual decrece el eje Y
        positionYcharacters -= tam;
    }
    characters.at(0)->setPos(positionXcharacters,positionYcharacters);
}

void MainWindow::OnTimeOut(){
    Time -= 1;
    if(Time < 0){
        loseLife();
    }else{
      ui->time->display(Time);
      positionXcharacters += tam;
      characters.at(0)->setPos(positionXcharacters,positionYcharacters);
    }
}

MainWindow::~MainWindow(){
    delete ui;
}

