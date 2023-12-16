#include "TicketInfoWindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>
#include "ReservationList.h"
#include "SeatsInfoWidget.h"

TicketInfoWindow::TicketInfoWindow(const unsigned int resId, const std::string &filmTitle, const tm &time, const unsigned int hallId, const std::vector<const FullPriceSeat *> &selectedSeats, QWidget *parent) : QDialog(parent), reservation(resId, hallId, selectedSeats, time, filmTitle)
{
    setWindowTitle("Ticket Info");

    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);

    QWidget *contentWidget = new QWidget(scrollArea);
    QVBoxLayout *layout = new QVBoxLayout(contentWidget);

    setFixedSize(400, 300);

    QFont font("Arial", 10, QFont::Bold);

    QLabel *filmDateLabel = new QLabel(QString::fromStdString(filmTitle) + "\n" + QString::fromStdString(Programming::createStringFromTm(time, "%d/%m/%Y %H:%M")));
    filmDateLabel->setFont(font);

    layout->addWidget(filmDateLabel);
    layout->addSpacing(10);
    SeatsInfoWidget *seatsInfoWidget = new SeatsInfoWidget(selectedSeats, contentWidget);
    seatsInfoWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    layout->addWidget(seatsInfoWidget);
    
    layout->addSpacing(10);
    QLabel *priceLabel = new QLabel(QString("Total Price: %1").arg(reservation.getTotalPrice()));
    priceLabel->setFont(font);
    layout->addWidget(priceLabel);
    scrollArea->setWidget(contentWidget);

    QPushButton *confirmButton = new QPushButton("Confirm", contentWidget);
    connect(confirmButton, &QPushButton::clicked, this, &TicketInfoWindow::onConfirmButtonClicked);

    layout->addWidget(confirmButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea);
    mainLayout->setContentsMargins(10, 10, 10, 10);
    setLayout(mainLayout);
}

void TicketInfoWindow::onConfirmButtonClicked()
{
    ReservationList::saveResToFile("reservations.txt", reservation);
    close();
}