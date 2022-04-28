#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);


    // add a new scene to draw all the tiles
    scene_ = new QGraphicsScene(this);

    // add scene to graphicsView
    ui_->graphicsView->setScene(scene_);


    connect(ui_->restartGameButton, &QPushButton::clicked, this, &MainWindow::restart_game);


}
MainWindow::~MainWindow()
{
    delete ui_;
}

void MainWindow::restart_game()
{

}

