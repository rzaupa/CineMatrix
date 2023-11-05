#include "ReservationManagement.h"

void ReservationManagement::addReservation(const Reservation &reservation)
{
    reservations.push_back(reservation);
}

void ReservationManagement::removeReservation(const Reservation &reservation)
{
    for (auto it = reservations.begin(); it != reservations.end(); ++it)
    {
        if (*(it) == reservation)
        {
            reservations.erase(it);
            break;
        }
    }
}

const std::vector<Reservation> &ReservationManagement::getReservations() const
{
    return reservations;
}

bool ReservationManagement::searchReservation(const std::string &filmTitle, const tm &dateTime, const Seat *seat) const
{
    for (const auto &r : reservations)
    {
        if (r.seatIsReserved(filmTitle, dateTime, seat))
            return true;
    }
    return false;
}

unsigned int ReservationManagement::getMaxId() const
{
    unsigned int maxId = 0;
    for (const auto &r : reservations)
    {
        if (r.getReservationId() > maxId)
            maxId = r.getReservationId();
    }
    return maxId;
}