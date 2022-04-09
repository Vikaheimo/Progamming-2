#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // max and min values for spinboxes
    ui->spinBoxN->setRange(MIN_POINTS, MAX_N_POINTS);
    ui->spinBoxG->setRange(MIN_POINTS, MAX_G_POINTS);
    ui->spinBoxP->setRange(MIN_POINTS, MAX_P_POINTS);
    ui->spinBoxE->setRange(MIN_POINTS, MAX_E_POINTS);

    connect(ui->countPushButton, &QPushButton::clicked, this, &MainWindow::set_textBrowser);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_textBrowser()
{
    int e = ui->spinBoxE->value();
    int g = ui->spinBoxG->value();
    int n = ui->spinBoxN->value();
    int p = ui->spinBoxP->value();

    unsigned int grade = count_final_grade(n, g, p, e);

    ui->textBrowser->setText("Total grade: " + QString::number(grade));
}



