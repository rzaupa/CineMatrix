#ifndef UNAVAILABLESEAT_H
#define UNAVAILABLESEAT_H

#include "Seat.h"

class UnavailableSeat : public Seat
{
public:
    UnavailableSeat(const unsigned int row, const unsigned int column);
    void accept(VisitorSeatInterface &visitor) const override;
    virtual UnavailableSeat* clone() const override;
};

#endif