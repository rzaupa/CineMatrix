#include "SeatsInfoWidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QFont>
#include "VisitorSeatView.h"

SeatsInfoWidget::SeatsInfoWidget(const std::vector<const FullPriceSeat *> &seats, QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *seatsLayout = new QVBoxLayout(this);
    seatsLayout->setSizeConstraint(QLayout::SetFixedSize);
    int i = 0;
    QFont font("Arial", 9, QFont::Bold);
    for (const auto seat : seats)
    {
        VisitorSeatView visitor;
        seat->accept(visitor);
        QLabel *seatLabel = new QLabel(QString("Seat %1").arg(i + 1), parent);
        seatLabel->setFont(font);
        QLabel *rowLabel = new QLabel(QString("<u>Row:</u> %1").arg(seat->getRow()), parent);
        QLabel *columnLabel = new QLabel(QString("<u>Column:</u> %1").arg(seat->getColumn()), parent);
        QLabel *descriptionLabel = new QLabel("<u>Description:</u>", parent);
        QLabel *descriptionText = new QLabel(*(visitor.getDescription()), parent);
        descriptionText->setStyleSheet("margin-left: 15px;");
        descriptionText->setWordWrap(true);
        descriptionText->setFixedWidth(250);
        QLabel* priceLabel = new QLabel(QString("<u>Price</u>: " + QString::number(seat->getPrice())));
        i++;

        seatsLayout->addWidget(seatLabel);
        seatsLayout->addWidget(rowLabel);
        seatsLayout->addWidget(columnLabel);
        seatsLayout->addWidget(priceLabel);
        seatsLayout->addWidget(descriptionLabel);
        seatsLayout->addWidget(descriptionText);
    }
    setLayout(seatsLayout);
}