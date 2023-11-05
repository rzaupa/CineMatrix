#ifndef RESERVATIONMANAGEMENT_H
#define RESERVATIONMANAGEMENT_H

#include "Reservation.h"

class ReservationManagement
{
private:
    std::vector<Reservation> reservations;

public:
    void addReservation(const Reservation &reservation);
    void removeReservation(const Reservation &reservation);
    const std::vector<Reservation> &getReservations() const;
    bool searchReservation(const std::string &filmTitle, const tm &dateTime, const Seat *seat) const;
    unsigned int getMaxId() const;
};

#endif