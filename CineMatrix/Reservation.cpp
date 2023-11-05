#include "Reservation.h"
#include "Programming.h"

Reservation::Reservation(const unsigned int reservationId, const unsigned int hallId, const std::vector<const FullPriceSeat *> &reservedSeats, const tm dateTime, const std::string filmTitle) : reservationId(reservationId), hallId(hallId), reservedSeats(reservedSeats), dateTime(dateTime), filmTitle(filmTitle) {}

unsigned int Reservation::getReservationId() const
{
    return reservationId;
}
unsigned int Reservation::getHallId() const
{
    return hallId;
}
const std::vector<const FullPriceSeat *> &Reservation::getReservedSeats() const
{
    return reservedSeats;
}
double Reservation::getTotalPrice() const
{
    double totalPrice = 0;
    for (const auto seat : reservedSeats)
    {
        totalPrice += seat->getPrice();
    }
    return totalPrice;
}
const tm &Reservation::getDateTime() const
{
    return dateTime;
}
const std::string &Reservation::getFilmTitle() const
{
    return filmTitle;
}
bool Reservation::seatIsReserved(const std::string &filmTitle, const tm &dateTime, const Seat *seat) const
{
    if (Programming::datesAreEqual(getDateTime(), dateTime) && Programming::timesAreEqual(getDateTime(), dateTime) && getFilmTitle() == filmTitle)
    {
        std::vector<const FullPriceSeat *> seats = getReservedSeats();
        for (const auto s : seats)
        {
            if (s->getColumn() == seat->getColumn() && s->getRow() == seat->getRow())
                return true;
        }
    }
    return false;
}
bool Reservation::operator==(const Reservation &reservation) const
{
    return reservationId == reservation.getReservationId();
}
