#ifndef SEATSINFOWIDGET_H
#define SEATSINFOWIDGET_H

#include <QWidget>
#include "../FullPriceSeat.h"
#include <vector>

class SeatsInfoWidget : public QWidget
{
    Q_OBJECT
public:
    SeatsInfoWidget(const std::vector<const FullPriceSeat *> &seats, QWidget *parent = nullptr);
};

#endif