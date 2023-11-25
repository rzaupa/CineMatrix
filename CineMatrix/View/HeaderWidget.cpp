#include "HeaderWidget.h"
#include <QHBoxLayout>
#include <QPushButton>

HeaderWidget::HeaderWidget(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->setAlignment(Qt::AlignTop);

    QPushButton *buttonCinema = new QPushButton("CineMatrix");
    buttonCinema->setFont(QFont("Arial", 30, 300));
    // buttonCinema->setStyleSheet("font-size: 35px; font-weight:500;background-color: transparent;");
    buttonCinema->setStyleSheet("font-size: 35px; font-weight: 500; background-color: white; color: black;");
    buttonCinema->setFlat(true);
    buttonCinema->setStyleSheet("padding: 0px;");

    QPushButton *buttonHome = new QPushButton("Home");
    QPushButton *buttonReservations = new QPushButton("Reservations");

    topLayout->addWidget(buttonCinema);
    topLayout->addWidget(buttonHome);
    topLayout->addWidget(buttonReservations);
    setLayout(topLayout);

    connect(buttonCinema, &QPushButton::clicked, this, &HeaderWidget::homeButtonClicked);
    connect(buttonHome, &QPushButton::clicked, this, &HeaderWidget::homeButtonClicked);
    connect(buttonReservations, &QPushButton::clicked, this, &HeaderWidget::reservationsButtonClicked);
}
