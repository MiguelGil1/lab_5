#include "mainwindow.h"
#include "ui_mainwindow.h"

#define PATH_WORLD "../lab_5_2/worlds/world.txt"
static int PosX = 0;
static int PosY = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();

    PJ = new mainCharacter(0,0,30,30);
    scene->addItem(PJ);
    readWorld();

    //Se inicia el TIMER//
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(OnTimeOut()));
    timer->start(1000);

    ui->Timer->display(Time);
    ui->Lives->display(PJ->getLives());
    ui->Score->display(PJ->getScore());

    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void MainWindow::loseLife(){
    int Lives = PJ->getLives();
    if(Lives != 0){
        Lives -= 1;
        Time = 300;
        PosX = 0;
        PosY = 0;
        ui->Lives->display(Lives);
        ui->Timer->display(Time);
        PJ->setPositionXmainCharacter(0);
        PJ->setPositionYmainCharacter(0);
        PJ->setPos(0,0);
        PJ->setLives(Lives);
    }else{
        timer->stop();
        timer->disconnect();
        scene->addText("Game Over!");
    }
}

void MainWindow::win(){
    timer->stop();
    timer->disconnect();
    scene->addText("Victory!");
}

void MainWindow::explosion(){
    activeBomb = false;
    int PosX = bomba->getPosX();
    int PosY = bomba->getPosY();
    bomba1 = new bomb(PosX-30,PosY);//Bomba un cuadro a la izquierda
    bomba2 = new bomb(PosX+30,PosY);//Bomba un cuadro a la derecha
    bomba3 = new bomb(PosX,PosY-30);//Bomba un cuadro arriba
    bomba4 = new bomb(PosX,PosY+30);//Bomba un cuadro abajo
    int Score = PJ->getScore();

    //Deteccion de colision de alguna bomba con un ladrillo
    if(bomba->collidesWithItem(PJ)){
        loseLife();
    }else if(bomba1->collidesWithItem(PJ)){
        loseLife();
    }else if(bomba2->collidesWithItem(PJ)){
        loseLife();
    }else if(bomba3->collidesWithItem(PJ)){
        loseLife();
    }else if(bomba4->collidesWithItem(PJ)){
        loseLife();
    }
    //Fin deteccion de colision con algun ladrillo


    //Deteccion de colisiones con ladrillos
    for(auto i = mBricks.begin(); i != mBricks.end(); i++){
        if(bomba1->collidesWithItem(*i)){
            cout << "Ladrillo eliminado: " << *i << endl;
            scene->removeItem(*i);
            delete *i;
            mBricks.remove(*i);
            Score += 50;
        }else if(bomba2->collidesWithItem(*i)){
            cout << "Ladrillo eliminado: " << *i << endl;
            scene->removeItem(*i);
            delete *i;
            mBricks.remove(*i);
            Score += 50;
        }else if(bomba3->collidesWithItem(*i)){
            cout << "Ladrillo eliminado: " << *i << endl;
            scene->removeItem(*i);
            delete *i;
            mBricks.remove(*i);
            Score += 50;
        }else if(bomba4->collidesWithItem(*i)){
            cout << "Ladrillo eliminado: " << *i << endl;
            scene->removeItem(*i);
            delete *i;
            mBricks.remove(*i);
            Score += 50;
        }
    }
    //Fin deteccion colisiones con ladrillos

    //Deteccion de colisiones con enemigos horizontales
    for(auto i = mH_Enemies.begin(); i != mH_Enemies.end(); i++){
        if(bomba1->collidesWithItem(*i)){
            cout << "Ladrillo eliminado: " << *i << endl;
            scene->removeItem(*i);
            delete *i;
            mH_Enemies.remove(*i);
            Score += 200;
        }else if(bomba2->collidesWithItem(*i)){
            cout << "Ladrillo eliminado: " << *i << endl;
            scene->removeItem(*i);
            delete *i;
            mH_Enemies.remove(*i);
            Score += 200;
        }else if(bomba3->collidesWithItem(*i)){
            cout << "Ladrillo eliminado: " << *i << endl;
            scene->removeItem(*i);
            delete *i;
            mH_Enemies.remove(*i);
            Score += 200;
        }else if(bomba4->collidesWithItem(*i)){
            cout << "Ladrillo eliminado: " << *i << endl;
            scene->removeItem(*i);
            delete *i;
            mH_Enemies.remove(*i);
            Score += 200;
        }
    }
    //Fin deteccion colisiones con enemigos horizontales

    //Deteccion de colisiones con enemigos verticales
    for(auto i = mV_Enemies.begin(); i != mV_Enemies.end(); i++){
        if(bomba1->collidesWithItem(*i)){
            cout << "Ladrillo eliminado: " << *i << endl;
            scene->removeItem(*i);
            delete *i;
            mV_Enemies.remove(*i);
            Score += 200;
        }else if(bomba2->collidesWithItem(*i)){
            cout << "Ladrillo eliminado: " << *i << endl;
            scene->removeItem(*i);
            delete *i;
            mV_Enemies.remove(*i);
            Score += 200;
        }else if(bomba3->collidesWithItem(*i)){
            cout << "Ladrillo eliminado: " << *i << endl;
            scene->removeItem(*i);
            delete *i;
            mV_Enemies.remove(*i);
            Score += 200;
        }else if(bomba4->collidesWithItem(*i)){
            cout << "Ladrillo eliminado: " << *i << endl;
            scene->removeItem(*i);
            delete *i;
            mV_Enemies.remove(*i);
            Score += 200;
        }
    }
    //Fin deteccion colisiones con enemigos verticales

    //Se evalua si se destapa la puerta
    if(bomba->collidesWithItem(puerta)){
        win();
    }else if(bomba1->collidesWithItem(puerta)){
        win();
    }else if(bomba2->collidesWithItem(puerta)){
        win();
    }else if(bomba3->collidesWithItem(puerta)){
        win();
    }else if(bomba4->collidesWithItem(puerta)){
        win();
    }
    //Fin de evaluacion si se destapa la puerta

    //Se actualiza el score en el LDC y en el objeto  PJ
    ui->Score->display(Score);
    PJ->setScore(Score);

    scene->removeItem(bomba);
    scene->removeItem(bomba1);
    scene->removeItem(bomba2);
    scene->removeItem(bomba3);
    scene->removeItem(bomba4);
    delete bomba;
    delete bomba1;
    delete bomba2;
    delete bomba3;
    delete bomba4;
}

void MainWindow::OnTimeOut(){
    Time -= 1;
    if(Time < 0){
        loseLife();
    }else{
      ui->Timer->display(Time);
    }
    if(activeBomb == true){
        int contador = bomba->getContador();
        if(contador == 3){
            explosion();
        }else{
            contador += 1;
            bomba->setContador(contador);
        }
    }
}

bool MainWindow::detectColision(){
    bool iron  = detectColisionWithIron();
    bool brick = detectColisionWithBricks();
    bool enemy = detectColisionWithEnemies();
    if(enemy == true){
        loseLife();
        return false;
    }else if(iron == true || brick == true){
        return true;
    }else{
        return false;
    }
}

bool MainWindow::detectColisionWithIron(){
    for(auto i = mIron.begin(); i != mIron.end(); i++){
        if(PJ->collidesWithItem(*i)){
            cout << "Colision con " << *i << endl;
            return true;
        }
    }
    return false;
}

bool MainWindow::detectColisionWithBricks(){
    for(auto i = mBricks.begin(); i != mBricks.end(); i++){
        if(PJ->collidesWithItem(*i)){
            cout << "Colision con " << *i << endl;
            return true;
        }
    }
    return false;
}
bool MainWindow::detectColisionWithEnemies(){
    for(auto i = mH_Enemies.begin(); i != mH_Enemies.end(); i++){
        if(PJ->collidesWithItem(*i)){
            cout << "Colision con " << *i << endl;
            return true;
        }
    }
    for(auto i = mV_Enemies.begin(); i != mV_Enemies.end(); i++){
        if(PJ->collidesWithItem(*i)){
            cout << "Colision con " << *i << endl;
            return true;
        }
    }
    return false;
}

void MainWindow::keyPressEvent(QKeyEvent *event){

    switch (event->key()) {
        case Qt::Key_A:{
            //Movimiento a la izquierda
            //Hay movimiento en la direccion en la que decrece el eje X
            int posX = PJ->getPositionXmainCharacter();
            posX -= 15;
            PosX -= 30;
            PJ->setPositionXmainCharacter(posX);
            PJ->changePosition();
            if(detectColision()){
                //Si hay colision. se devuelve al presonaje en la psicion en la que estaba
                posX += 15;
                PosX += 30;
                PJ->setPositionXmainCharacter(posX);
                PJ->changePosition();
            }
            break;
        }
        case Qt::Key_S:{
            //Movimiento abajo
            //Hay moviemiento en el la direccion en la que crece el eje Y
            int posY = PJ->getPositionYmainCharacter();
            posY += 15;
            PosY += 30;
            PJ->setPositionYmainCharacter(posY);
            PJ->changePosition();
            if(detectColision()){
                //Si hay colision. se devuelve al presonaje en la psicion en la que estaba
                posY -= 15;
                PosY -= 30;
                PJ->setPositionYmainCharacter(posY);
                PJ->changePosition();
            }
            break;
        }
        case Qt::Key_D:{
            //Movimiento a la derecha
            //Hay movimiento en la direccion en la que crece el eje X
            int posX = PJ->getPositionXmainCharacter();
            posX += 15;
            PosX += 30;
            PJ->setPositionXmainCharacter(posX);
            PJ->changePosition();
            if(detectColision()){
                //Si hay colision. se devuelve al presonaje en la psicion en la que estaba
                posX -= 15;
                PosX -= 30;
                PJ->setPositionXmainCharacter(posX);
                PJ->changePosition();
            }
            break;
        }
        case Qt::Key_W:{
            //Movimiento arriba
            //Hay movimiento en la direccion en la cual decrece el eje Y
            int posY = PJ->getPositionYmainCharacter();
            posY -= 15;
            PosY -= 30;
            PJ->setPositionYmainCharacter(posY);
            PJ->changePosition();
            if(detectColision()){
                //Si hay colision. se devuelve al presonaje en la psicion en la que estaba
                posY += 15;
                PosY += 30;
                PJ->setPositionYmainCharacter(posY);
                PJ->changePosition();
            }
            break;
        }
        case Qt::Key_Space:{
            if(activeBomb == false){
                activeBomb = true;
                bomba = new bomb(PosX,PosY);
                scene->addItem(bomba);
            }
            break;
        }
    }
}

void MainWindow::readWorld(){
    string line = "";
    string valor = "";
    int contRow = 0;
    ifstream infile;
    infile.open(PATH_WORLD);
    int contBriks = 0;

    while(!infile.eof()){
        infile >> line;
        for(int  i = 0; i < int(line.length()); i++){
            valor[0] = line[i];
            worldMatrix[contRow][i] = (stoi(valor));
            if(stoi(valor) == 2){
                contBriks += 1;
            }
        }
        contRow++;
    }
    infile.close();

    //Posicion inicial del primer bloque en los ejes X e Y
    int positionX = -30;
    int positionY = -30;

    //Generando numero aleatorio para la puerta
    srand(time(NULL));
    int num = 1+rand()%(contBriks);
    //Fin de generacio de numero aleatorio

    contBriks = 0;
    for(int rows = 0; rows != 13; rows++){
        positionX = -30;
        for(int columns = 0; columns < 31; columns++){
            if(worldMatrix[rows][columns] == 1){
               //Se agregan cuadrados de hierro
                hierro = new iron(positionX,positionY);
                scene->addItem(hierro);
                mIron.push_back(hierro);
            }else if(worldMatrix[rows][columns] == 2){
                //Se agregan los ladrillos
                contBriks += 1;
                if(contBriks == num){
                    puerta = new door(positionX,positionY);
                    scene->addItem(puerta);
                }
               ladrillo = new bricks(positionX,positionY);
               scene->addItem(ladrillo);
               mBricks.push_back(ladrillo);           
            }else if(worldMatrix[rows][columns] == 3){
                //Se agregan enemigos con movimiento horizontal
                hEnemy = new horizontalEnemies(positionX,positionY);
                scene->addItem(hEnemy);
                mH_Enemies.push_back(hEnemy);
            }else if(worldMatrix[rows][columns] == 3){
                //Se agregan enemigos con movimiento vertical
                vEnemy = new verticalEnemies(positionX,positionY);
                scene->addItem(vEnemy);
                mV_Enemies.push_back(vEnemy);
            }
            positionX += 30;
        }
        positionY += 30;
    }

}

MainWindow::~MainWindow(){
    //Destruimos al personaje principal
    scene->removeItem(PJ);
    delete PJ;
    //Fin de eliminacion del personaje principal

    //Destruimos los ladrillos restantes
    for(auto i = mBricks.begin(); i != mBricks.end(); i++){
        scene->removeItem(*i);
        delete *i;
    }

    //Se vacía el contenedor de Ladrillos
    for(auto i = mBricks.begin(); i != mBricks.end(); i++){
        mBricks.pop_front();
    }
    //Finalizacion de vaciado

    //Destruimos los hierros
    for(auto i = mIron.begin(); i != mIron.end(); i++){
        scene->removeItem(*i);
        delete *i;
    }
    //Fin de destruccion de hierros

    //Se vacía el contenedor de Ladrillos
    for(auto i = mIron.end(); i != mIron.begin(); i++){
        mIron.pop_back();
    }
    //Finalizacion de vaciado

    scene->removeItem(puerta);//Se elimina la puerta
    delete puerta;

    scene->destroyed();
    delete scene;
    delete ui;
}
