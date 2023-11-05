#include "VipPriceSeat.h"

VipPriceSeat::VipPriceSeat(const unsigned int row, const unsigned int column, const std::set<Supplement> &supplements) : FullPriceSeat(row, column), supplements(supplements) {}

double VipPriceSeat::getPrice() const
{
    double vipPrice = FullPriceSeat::getPrice();
    for (const auto &sup : supplements)
    {
        vipPrice += sup.second;
    }
    return vipPrice;
}

const std::set<Supplement> &VipPriceSeat::getSupplements() const
{
    return supplements;
}

void VipPriceSeat::accept(VisitorSeatInterface &visitor) const
{
    visitor.visitVipPrice(*this);
}

void VipPriceSeat::addSupplement(const Supplement &s)
{
    supplements.insert(s);
}

VipPriceSeat *VipPriceSeat::clone() const
{
    return new VipPriceSeat(getRow(), getColumn(), supplements);
}