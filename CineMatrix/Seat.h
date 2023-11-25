#ifndef SEAT_H
#define SEAT_H

#include "VisitorSeatInterface.h"

class Seat
{
private:
    const unsigned int row;
    const unsigned int column;

public:
    Seat(const unsigned int row, const unsigned int column);
    unsigned int getRow() const;
    unsigned int getColumn() const;
    virtual void accept(VisitorSeatInterface &visitor) const = 0;
    virtual Seat *clone() const = 0;
    virtual ~Seat() = default;
};

#endif