#ifndef TICKETINFOWINDOW_H
#define TICKETINFOWINDOW_H

#include <QDialog>
#include "../Reservation.h"

class TicketInfoWindow : public QDialog
{
    Q_OBJECT

public:
    TicketInfoWindow(const unsigned int resId, const std::string &filmTitle, const tm &time, const unsigned int hallId, const std::vector<const FullPriceSeat *> &selectedSeats, QWidget *parent = nullptr);

private slots:
    void onConfirmButtonClicked();

private:
    Reservation reservation;
};

#endif