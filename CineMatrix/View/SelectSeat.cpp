#include "SelectSeat.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QLabel>
#include <QPushButton>
#include "TicketInfoWindow.h"
#include "VisitorSeatView.h"

SelectSeat::SelectSeat(const std::string &filmTitle, const tm &time, const Hall &hall, const ReservationManagement &rm, QWidget *parent) : QDialog(parent), filmTitle(filmTitle), time(time), hall(hall), rm(rm)
{
    setWindowTitle("Seat Selection");
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *descriptionLabel = new QLabel("Select the seats", this);
    QGridLayout *seatLayout = new QGridLayout();

    mySet<const Seat *> seats = hall.getSeats();
    int maxRow = hall.getMaxRow();
    int maxColumn = hall.getMaxColumn();

    for (int column = 0; column < maxColumn; ++column)
    {
        QLabel *columnLabel = new QLabel(QString::number(column + 1), this);
        seatLayout->addWidget(columnLabel, 0, column + 1);
    }

    for (int row = 0; row < maxRow; ++row)
    {
        QLabel *rowLabel = new QLabel(QString::number(row + 1), this);
        seatLayout->addWidget(rowLabel, row + 1, 0);
    }

    for (const auto seat : seats)
    {
        VisitorSeatView visitor;
        seat->accept(visitor);
        QCheckBox *seatWidget = visitor.getCheckBox();
        ckbls.emplace_back(seatWidget, seat);

        seatLayout->addWidget(seatWidget, seat->getRow(), seat->getColumn());
        if (rm.searchReservation(filmTitle, time, seat))
        {
            seatWidget->setDisabled(true);
        }
    }

    QPushButton *confirmButton = new QPushButton("Confirm", this);
    connect(confirmButton, &QPushButton::clicked, this, &SelectSeat::onConfirmButtonClicked);

    layout->addWidget(descriptionLabel);
    layout->addLayout(seatLayout);
    layout->addWidget(confirmButton);

    setLayout(layout);
}

void SelectSeat::onConfirmButtonClicked()
{
    std::vector<const FullPriceSeat *> selectedSeat;

    for (const auto &[ckb, seat] : ckbls)
    {
        const FullPriceSeat *fps = dynamic_cast<const FullPriceSeat *>(seat);
        if (ckb->isChecked() && fps)
        {
            selectedSeat.push_back(fps);
        }
    }
    if (selectedSeat.empty())
    {
        QMessageBox::warning(this, "Attention", "Please select at least one seat.");
        return;
    }
    hide();
    TicketInfoWindow *ticketInfoWindow = new TicketInfoWindow(rm.getMaxId() + 1, filmTitle, time, hall.getId(), selectedSeat, this);
    ticketInfoWindow->show();
}