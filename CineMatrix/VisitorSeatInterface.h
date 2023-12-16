#ifndef VISITORSEATINTERFACE_H
#define VISITORSEATINTERFACE_H

class VipPriceSeat;
class FullPriceSeat;
class DiscountedPriceSeat;
class UnavailableSeat;

class VisitorSeatInterface
{
public:
    virtual void visitVipPrice(const VipPriceSeat &) = 0;
    virtual void visitFullPrice(const FullPriceSeat &) = 0;
    virtual void visitDiscountedPrice(const DiscountedPriceSeat &) = 0;
    virtual void visitUnavailable(const UnavailableSeat &) = 0;
    virtual ~VisitorSeatInterface() = default;
};

#endif