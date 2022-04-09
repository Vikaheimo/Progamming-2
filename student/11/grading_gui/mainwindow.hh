#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <gradecounter.hh>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    const unsigned int MAX_N_POINTS = 760;
    const unsigned int MAX_G_POINTS = 120;
    const unsigned int MAX_P_POINTS = 250;
    const unsigned int MAX_E_POINTS = 5;
    const unsigned int MIN_POINTS = 0;

    void set_textBrowser();


};
#endif // MAINWINDOW_HH
