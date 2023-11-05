#ifndef FILMLIST_H
#define FILMLIST_H

#include <QWidget>
#include "../Programming.h"

class FilmList : public QWidget
{
    Q_OBJECT
private:
    Programming p;

public:
    FilmList(const Programming &p, QWidget *parent = nullptr);
private slots:
    void openSelectSeat(const std::string &filmTitle, const tm &time, const Hall &hall);
};

#endif