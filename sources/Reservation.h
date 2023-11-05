#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <vector>
#include "FullPriceSeat.h"

class Reservation
{
private:
    unsigned int reservationId;
    unsigned int hallId;
    std::vector<const FullPriceSeat *> reservedSeats;
    tm dateTime;
    std::string filmTitle;

public:
    Reservation(const unsigned int reservationId, const unsigned int hallId, const std::vector<const FullPriceSeat *> &reservedSeats, const tm dateTime, const std::string filmTitle);
    unsigned int getReservationId() const;
    unsigned int getHallId() const;
    const std::vector<const FullPriceSeat *> &getReservedSeats() const;
    double getTotalPrice() const;
    const tm &getDateTime() const;
    const std::string &getFilmTitle() const;
    bool seatIsReserved(const std::string &filmTitle, const tm &datTime, const Seat *seat) const;
    bool operator==(const Reservation &reservation) const;
};

#endif