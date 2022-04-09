#include "mainwindow.hh"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    seconds_ = 0;
    minutes_ = 0;
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->setInterval(1000);

    ui->lcdNumberMin->setStyleSheet("background-color:magenta;");
    ui->lcdNumberSec->setStyleSheet("background-color:cyan;");
    ui->centralWidget->setStyleSheet("background-color:grey;");

    connect(timer, SIGNAL(timeout()), this, SLOT(change_time()));
    connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::on_startButton_clicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::reset_timer);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::stop_timer);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::change_time()
{
    seconds_ += 1;
    if (seconds_ == 60){
        minutes_ += 1;
        seconds_ = 0;
    }
    ui->lcdNumberMin->display(minutes_);
    ui->lcdNumberSec->display(seconds_);
}



void MainWindow::on_startButton_clicked()
{
    timer->start();
}

void MainWindow::stop_timer()
{
    timer->stop();
}

void MainWindow::reset_timer()
{
    timer->stop();
    seconds_ = 0;
    minutes_ = 0;
    ui->lcdNumberMin->display(minutes_);
    ui->lcdNumberSec->display(seconds_);
}

