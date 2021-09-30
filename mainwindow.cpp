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
    //Agregando colores
    Colors.push_back(QColor(187,187,187));
    Colors.push_back(QColor(255,0,0));
    //Fin de agregar colores

    //Agregando brochas
    Brushes.push_back(QBrush(Colors.at(0)));
    Brushes.push_back(QBrush(im));
    Brushes.push_back(QBrush(Colors.at(1)));
    //Fin de agregar brochas

    QPen pen1(Qt::black, 3, Qt::SolidLine,Qt::RoundCap, Qt::RoundJoin);

    //Se inicia el TIMER//
    timer = new QTimer();
    //Se conecta con el Slot OntimeOut
    connect(timer, SIGNAL(timeout()), this, SLOT(OnTimeOut()));
    timer->start(1000);
    ui->time->display(Time);
    ui->lives->display(Lives);

    //Añadiendo el personaje principal al vector de personajes
    characters.push_back(scene->addEllipse(positionXmainCharacter,positionYmainCharacter,tam,tam,pen1,Brushes.at(2)));
    cout << "[" << positionXmainCharacter << " , " << positionYmainCharacter << "]" << endl;
    //scene->addEllipse(positionX+tam,positionY+tam,tam,tam,pen1,Brush3);

    for(int rows = 0; rows < 13; rows++){
        positionX = 0;
        for(int columns = 0; columns < 31; columns++){
            if(world[rows][columns] == 1){
                //Se agregan cuadrados de hierro
                worldRect.push_back(scene->addRect(positionX,positionY,tam,tam,pen1,Brushes.at(0)));
                //scene->addRect(positionX,positionY,tam,tam,pen1,Brush1);
            }else if(world[rows][columns] == 2){
                //Se agregan los ladrillos
                worldRect.push_back(scene->addRect(positionX,positionY,tam,tam,pen1,Brushes.at(1)));
                //scene->addRect(positionX,positionY,tam,tam,pen1,Brush2);
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
void MainWindow::OnTimeOut(){
    Time -= 1;
    if(Time < 0){
        loseLife();
    }else{
      ui->time->display(Time);
    }
}

MainWindow::~MainWindow(){
    delete ui;
}

bool MainWindow::detectColision(){
    characters.at(0)->setPos(positionXmainCharacter,positionYmainCharacter);
    for(auto i = worldRect.begin(); i != worldRect.end(); i++){
        if(characters.at(0)->collidesWithItem(*i)){
            cout << "Colision con " << *i << endl;
            return true;
        }else{
            characters.at(0)->setBrush(Brushes.at(2));
        }
    }
    return false;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
        case Qt::Key_A:{
            //Movimiento a la izquierda
            //Hay movimiento en la direccion en la que decrece el eje X
            positionXmainCharacter -= tam;
            cout << "[" << positionXmainCharacter << " , " << positionYmainCharacter << "]" << endl;
            //Se verifica si hay colision
            if(detectColision()){
                //Si hay colision. se devuelve al presonaje en la psicion en la que estaba
                positionXmainCharacter += tam;
            }
            break;
        }
        case Qt::Key_S:{
            //Movimiento abajo
            //Hay moviemiento en el la direccion en la que crece el eje Y
            positionYmainCharacter += tam;
            cout << "[" << positionXmainCharacter << " , " << positionYmainCharacter << "]" << endl;
            //Se verifica si hay colision
            if(detectColision()){
                //Si hay colision. se devuelve al presonaje en la psicion en la que estaba
                positionYmainCharacter -= tam;
            }
            break;
        }
        case Qt::Key_D:{
            //Movimiento a la derecha
            //Hay movimiento en la direccion en la que crece el eje X
            positionXmainCharacter += tam;
            cout << "[" << positionXmainCharacter << " , " << positionYmainCharacter << "]" << endl;
            //Se verifica si hay colision
            if(detectColision()){
                //Si hay colision. se devuelve al presonaje en la psicion en la que estaba
                positionXmainCharacter -= tam;
            }
            break;
        }
        case Qt::Key_W:{
            //Movimiento arriba
            //Hay movimiento en la direccion en la cual decrece el eje Y
            positionYmainCharacter -= tam;
            cout << "[" << positionXmainCharacter << " , " << positionYmainCharacter << "]" << endl;
            //Se verifica si hay colision
            if(detectColision()){
                //Si hay colision. se devuelve al presonaje en la psicion en la que estaba
                positionYmainCharacter += tam;
            }
            break;
        }
    }
    cout << "[" << positionXmainCharacter << " , " << positionYmainCharacter << "]" << endl;
    characters.at(0)->setPos(positionXmainCharacter,positionYmainCharacter);
}

