#ifndef HOME_H
#define HOME_H

#include "FilmList.h"
#include "ReservationList.h"

class Home : public QWidget
{
    Q_OBJECT
public:
    Home(const Programming &p, QWidget *parent = nullptr);

private:
    FilmList *filmList;
    ReservationList *reservationList;
private slots:
    void handleReservationsButtonClicked();
    void handleHomeButtonClicked();
};

#endif