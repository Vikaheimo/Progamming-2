<<<<<<< HEAD
/*
 * COMP.CS.110 Ohjelmointi 2: Rakenteet / Programming 2: Structures
 * Project4:  Peli nimeltä 2048 / Game called 2048
 * File: main.cpp
 *
 * Description:
 * The progam is a game called 2048, in which the idea is to stack
 * tiles to get a high socre. The stacking can be done with the use of
 * arrow keys or wasd. Same numbers can only be stacked. The game ends
 *  when you cannot stack more titles, eg the pieces get "stuck".
 *
 *
 * Progmam author:
 *      Name: Vili Ikäheimo
 *      Student number: 150286761
 *      UserID: csviik
 *      E-Mail: vili.ikaheimo@tuni.fi
 *
 * Notes about the progam and it's implementation:
*/

=======
>>>>>>> e6336a74326f1c906720abf7916c97777fadd926
#include "mainwindow.hh"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
