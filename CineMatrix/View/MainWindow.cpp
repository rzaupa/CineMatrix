#include "MainWindow.h"

MainWindow::MainWindow(const Programming &p, QWidget *parent) : QMainWindow(parent)
{
    home=new Home(p);
    setWindowTitle("Cinema");
    //setStyleSheet("background-color: #001A31; color: white;");
    //setStyleSheet("background-color: #F0F0F0");
    //setStyleSheet("background-color: royalblue;");
    setStyleSheet("background-color: #EAF2F8");
    setCentralWidget(home);
}