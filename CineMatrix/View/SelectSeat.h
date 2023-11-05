#ifndef SELECTSEAT_H
#define SELECTSEAT_H

#include <QDialog>
#include <QCheckBox>
#include <utility>
#include "../Hall.h"
#include "../ReservationManagement.h"

class SelectSeat : public QDialog
{
    Q_OBJECT

public:
    SelectSeat(const std::string &filmTitle, const tm &time, const Hall &hall, const ReservationManagement &rm, QWidget *parent = nullptr);

private slots:
    void onConfirmButtonClicked();

private:
    std::string filmTitle;
    tm time;
    Hall hall;
    ReservationManagement rm;
    std::vector<std::pair<QCheckBox *, const Seat *>> ckbls;
};

#endif
