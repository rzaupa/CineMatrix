#ifndef VISITORSEATVIEW_H
#define VISITORSEATVIEW_H

#include "../VisitorSeatInterface.h"
#include <QCheckBox>
#include <QString>

class VisitorSeatView : public VisitorSeatInterface
{
private:
    QCheckBox *widget;
    QString *description;

public:
    QCheckBox *getCheckBox() const;
    QString *getDescription() const;
    virtual void visitVipPrice(const VipPriceSeat &) override;
    virtual void visitFullPrice(const FullPriceSeat &) override;
    virtual void visitDiscountedPrice(const DiscountedPriceSeat &) override;
    virtual void visitUnavailable(const UnavailableSeat &) override;
};

#endif