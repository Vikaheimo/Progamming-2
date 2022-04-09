#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <string>
#include <fstream>
#include <set>
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
    void onFindCommand();

private:
    Ui::MainWindow *ui;

    std::string file_data_;
    bool match_case_;

    bool get_file_data(std::string file_name);
    bool check_data(std::string word_to_search, bool match_case);

    std::set<std::string> split(std::string text, char separator, bool skip=false);

};
#endif // MAINWINDOW_HH
