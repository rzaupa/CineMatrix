#ifndef FULLPRICESEAT_H
#define FULLPRICESEAT_H

#include "Seat.h"

class FullPriceSeat : public Seat
{
private:
    static double fullPrice;

public:
    FullPriceSeat(const unsigned int row, const unsigned int column);
    virtual double getPrice() const;
    void accept(VisitorSeatInterface &visitor) const override;
    void setFullPrice(const double price);
    virtual FullPriceSeat *clone() const override;
};

#endif