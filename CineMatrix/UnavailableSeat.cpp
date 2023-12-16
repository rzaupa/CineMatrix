#include "UnavailableSeat.h"

UnavailableSeat::UnavailableSeat(const unsigned int row, const unsigned int column) : Seat(row, column) {}

void UnavailableSeat::accept(VisitorSeatInterface &visitor) const
{
    visitor.visitUnavailable(*this);
}

UnavailableSeat *UnavailableSeat::clone() const
{
    return new UnavailableSeat(*this);
}
