#ifndef RESERVATIONLIST_H
#define RESERVATIONLIST_H

#include <QWidget>
#include <QGridLayout>
#include "../Programming.h"
#include "../ReservationManagement.h"

class ReservationList : public QWidget
{
    Q_OBJECT
public:
    ReservationList(const Programming &p, QWidget *parent = nullptr);
    void createResLayout();
    void deleteAndRefresh(const Reservation &reservation);
    void refresh();
    void openSeatsInfo(const std::vector<const FullPriceSeat *> &seats);
    static ReservationManagement readFromFile(const std::string &fn, const Programming &p);
    static void deleteResFromFile(const std::string &fn, const Reservation &r, const Programming &p);
    static void saveResToFile(const std::string &fn, const Reservation &r);

private:
    QGridLayout *resLayout;
    Programming p;
};

#endif