#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->closePushButton, &QPushButton::clicked, this, &MainWindow::close);

    connect(ui->findPushButton, &QPushButton::clicked, this, &MainWindow::onFindCommand);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onFindCommand()
{
    std::string file_name = ui->fileLineEdit->text().toUtf8().constData();
    std::string etsi_string = ui->keyLineEdit->text().toUtf8().constData();

    std::string text;
    if (!get_file_data(file_name)){
        text = "File not found";

    } else if (etsi_string.length() == 0) {
        text = "File found";

    }else if (!check_data(etsi_string, ui->matchCheckBox->isChecked())) {
        text = "Word not found";

    } else {
        text = "Word found";
    }
    ui->textBrowser->setText(QString::fromStdString(text));
}

bool MainWindow::get_file_data(std::string file_name)
{
    std::ifstream file;
    file.open(file_name);

    if (!file){
        return false;
        file.close();
    }
    std::string line;
    while(getline(file, line)){
        file_data_.append(" "+line);
    }
    file.close();
    return true;
}


bool MainWindow::check_data(std::string word_to_search, bool match_case)
{
    if (!match_case){
        std::for_each(word_to_search.begin(), word_to_search.end(), [](char & c){
            c = std::toupper(c);
        });
        std::for_each(file_data_.begin(), file_data_.end(), [](char & c){
            c = std::toupper(c);
        });
    }
    if (file_data_.find(word_to_search) != std::string::npos){
        return true;
    }
    return false;
}

