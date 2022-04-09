#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->countButton, &QPushButton::clicked, this, &MainWindow::count_bmi);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::count_bmi()
{
     std::string weight_str = ui->weightLineEdit->text().toUtf8().constData();
     std::string height_str = ui->heightLineEdit->text().toUtf8().constData();
     std::string text;
     if (weight_str.length() == 0 or height_str.length() == 0 or height_str == "0"){
         ui->infoTextBrowser->setText("Cannot count");
         ui->resultLabel->setText("");
         return;
     }
     int height = std::stoi(height_str);
     int weight = std::stoi(weight_str);
     double bmi = calculate_bmi(weight, height);

     if (bmi < 18.5){
         text = "You are underweight.";
     }else if (bmi > 25){
         text = "You are overweight.";
     } else {
         text = "Your weight is normal.";
     }

     ui->infoTextBrowser->setText(QString::fromStdString(text));
     ui->resultLabel->setText(QString::number(bmi));
}

double MainWindow::calculate_bmi(double weight, double height)
{
    double height_m = height / 100;
    return weight/(height_m * height_m);
}

