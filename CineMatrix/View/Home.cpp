#include "Home.h"
#include <QVBoxLayout>
#include <QSizePolicy>
#include "HeaderWidget.h"

Home::Home(const Programming &p, QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    HeaderWidget *headerWidget = new HeaderWidget();
    layout->addWidget(headerWidget);
    filmList = new FilmList(p);
    layout->addWidget(filmList);
    reservationList = new ReservationList(p);
    layout->addWidget(reservationList);
    reservationList->hide();
    connect(headerWidget, &HeaderWidget::reservationsButtonClicked, this, &Home::handleReservationsButtonClicked);
    connect(headerWidget, &HeaderWidget::homeButtonClicked, this, &Home::handleHomeButtonClicked);
}

void Home::handleReservationsButtonClicked()
{
    filmList->hide();
    QSizePolicy policy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    policy.setHorizontalStretch(1);
    policy.setVerticalStretch(1);
    reservationList->setSizePolicy(policy);
    reservationList->refresh();
    reservationList->show();
}

void Home::handleHomeButtonClicked()
{
    reservationList->hide();
    filmList->show();
}