#ifndef HEADERWIDGET_H
#define HEADERWIDGET_H

#include <QWidget>

class HeaderWidget : public QWidget
{
    Q_OBJECT
public:
    HeaderWidget(QWidget *parent = nullptr);

signals:
    void homeButtonClicked();
    void reservationsButtonClicked();
};

#endif