#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <vector>
#include <QGraphicsRectItem>
#include <fstream>
#include <iostream>

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
    ~MainWindow();

private:
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
    int world[13][31];
};
#endif // MAINWINDOW_H
