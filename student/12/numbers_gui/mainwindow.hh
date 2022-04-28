#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <vector>
#include

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // restart the game
    void restart_game();

private:
    Ui::MainWindow *ui_;

    QGraphicsScene* scene_;
    //std::vector<std::vector<QGraphicsRectItem*>> tiles_;




};
#endif // MAINWINDOW_HH
