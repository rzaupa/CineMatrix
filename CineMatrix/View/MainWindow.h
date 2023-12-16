#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Home.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(const Programming &p, QWidget *parent = nullptr);

private:
    Home *home;
};

#endif