#ifndef VIPPRICESEAT_H
#define VIPPRICESEAT_H

#include <set>
#include <string>
#include "FullPriceSeat.h"

using Supplement = std::pair<std::string, double>;

const Supplement Reclinig = {"Reclinig", 1.6};
const Supplement Food = {"Food", 3.5};
const Supplement Beverages = {"Beverages", 2.5};
const Supplement Footrest = {"Footrest", 1.6};

class VipPriceSeat : public FullPriceSeat
{
private:
    std::set<Supplement> supplements;

public:
    VipPriceSeat(const unsigned int row, const unsigned int column, const std::set<Supplement> &supplements);
    virtual double getPrice() const override;
    void accept(VisitorSeatInterface &visitor) const override;
    const std::set<Supplement> &getSupplements() const;
    void addSupplement(const Supplement &s);
    virtual VipPriceSeat *clone() const override;
};

#endif