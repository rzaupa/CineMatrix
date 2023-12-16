#include "FullPriceSeat.h"

double FullPriceSeat::fullPrice = 8.5;

FullPriceSeat::FullPriceSeat(const unsigned int row, const unsigned int column) : Seat(row, column) {}

double FullPriceSeat::getPrice() const
{
    return fullPrice;
}

void FullPriceSeat::accept(VisitorSeatInterface &visitor) const
{
    visitor.visitFullPrice(*this);
}

void FullPriceSeat::setFullPrice(const double price)
{
    fullPrice = price;
}

FullPriceSeat *FullPriceSeat::clone() const
{
    return new FullPriceSeat(*this);
}
