#ifndef DISCOUNTEDPRICESEAT_H
#define DISCOUNTEDPRICESEAT_H

#include "FullPriceSeat.h"

class DiscountedPriceSeat : public FullPriceSeat
{
private:
    unsigned int percentage;

public:
    DiscountedPriceSeat(const unsigned int row, const unsigned int column, const unsigned int p = 20);
    unsigned int getDiscountPercentage() const;
    virtual double getPrice() const override;
    void accept(VisitorSeatInterface &visitor) const override;
    virtual DiscountedPriceSeat *clone() const override;
};

#endif