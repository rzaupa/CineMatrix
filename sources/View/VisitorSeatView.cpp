#include <sstream>
#include "VisitorSeatView.h"
#include "../DiscountedPriceSeat.h"
#include "../VipPriceSeat.h"

QCheckBox *VisitorSeatView::getCheckBox() const
{
    return widget;
}

QString *VisitorSeatView::getDescription() const
{
    return description;
}

void VisitorSeatView::visitDiscountedPrice(const DiscountedPriceSeat &s)
{
    widget = new QCheckBox("");
    widget->setStyleSheet("QCheckBox::indicator { background-color: white; border: 2px solid green; width: 8px; height: 8px; }"
                          "QCheckBox::indicator:checked { background-color: green;}"
                          "QCheckBox::indicator:disabled { background-color: black; }");
    std::ostringstream os;
    os << "A discounted seat offers affordable cinema experience with reduced prices." << std::endl;
    os << "Price without discount : " << s.FullPriceSeat::getPrice() << std::endl;
    os << "Discount : " << s.getDiscountPercentage() << " % " << std::endl;
    description = new QString(os.str().c_str());
}
void VisitorSeatView::visitVipPrice(const VipPriceSeat &s)
{
    widget = new QCheckBox("");
    widget->setStyleSheet("QCheckBox::indicator { background-color: white; border: 2px solid red; width: 8px; height: 8px; }"
                          "QCheckBox::indicator:checked { background-color: red;}"
                          "QCheckBox::indicator:disabled { background-color: black; }");
    std::ostringstream os;
    os << "The Maxi VIP Seat is a large, luxurious seat designed for premium moviegoers seeking ultimate comfort and luxury." << std::endl
       << std::endl;
    os << "Price without supplements: " << s.FullPriceSeat::getPrice() << std::endl;
    os << "Supplement given by extras: " << std::endl;
    for (const auto &extra : s.getSupplements())
    {
        os << "\t" << extra.first << " : " << extra.second << std::endl;
    }
    description = new QString(os.str().c_str());
}
void VisitorSeatView::visitFullPrice(const FullPriceSeat &)
{
    widget = new QCheckBox("");
    widget->setStyleSheet("QCheckBox::indicator { background-color: white; border: 2px solid blue; width: 8px; height: 8px; }"
                          "QCheckBox::indicator:checked { background-color: #6699CC;}"
                          "QCheckBox::indicator:disabled { background-color: black; }");
    std::ostringstream os;
    os << "A full-price Comfort seat provides a premium cinema experience at regular prices with enhanced comfort features." << std::endl;
    description = new QString(os.str().c_str());
}

void VisitorSeatView::visitUnavailable(const UnavailableSeat &)
{
    widget = new QCheckBox("");
    widget->setEnabled(false);
    widget->setStyleSheet("QCheckBox::indicator { background-color: grey; border: 2px solid grey; width: 8px; height: 8px; }"
                          "QCheckBox::indicator:disabled { background-color: grey; }");
    description = nullptr;
}