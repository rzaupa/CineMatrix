#include "DiscountedPriceSeat.h"

DiscountedPriceSeat::DiscountedPriceSeat(const unsigned int row, const unsigned int column, const unsigned int p) : FullPriceSeat(row, column), percentage(p)
{
    if (!(1 <= percentage && percentage <= 100))
    {
        percentage = 1;
    }
}

unsigned int DiscountedPriceSeat::getDiscountPercentage() const
{
    return percentage;
}

double DiscountedPriceSeat::getPrice() const
{
    return FullPriceSeat::getPrice() * (1 - (((double)percentage) / 100));
}

void DiscountedPriceSeat::accept(VisitorSeatInterface &visitor) const
{
    visitor.visitDiscountedPrice(*this);
}

DiscountedPriceSeat *DiscountedPriceSeat::clone() const
{
    return new DiscountedPriceSeat(*this);
}
