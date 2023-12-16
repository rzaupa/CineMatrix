#include "FilmList.h"
#include <QVBoxLayout>
#include <QTabWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include "../ReservationManagement.h"
#include "ReservationList.h"
#include "SelectSeat.h"

FilmList::FilmList(const Programming &p, QWidget *parent) : QWidget(parent), p(p)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QTabWidget *tabWidget = new QTabWidget(this);
    mainLayout->addWidget(tabWidget);
    std::vector<tm> dates = p.getDates();
    for (const auto &date : dates)
    {
        QWidget *tab = new QWidget();
        QVBoxLayout *layoutScheda = new QVBoxLayout(tab);

        std::vector<Film> films = p.getFilmsByDate(date);
        for (const auto &f : films)
        {
            QWidget *filmWidget = new QWidget();
            filmWidget->setStyleSheet("background-color: #EAF2F8; color: #333333;border-radius: 6px;padding 8px"); 

            QVBoxLayout *filmLayout = new QVBoxLayout(filmWidget);
            QLabel *labelTitle = new QLabel(QString::fromStdString(f.getTitle()));
            labelTitle->setStyleSheet("font: bold 9pt Arial;margin-bottom: 5px ");
            QLabel *labelDurationCast = new QLabel("Duration: " + QString::number(f.getDuration()) + "\nCast: " + QString::fromStdString(f.getCast()));
            labelDurationCast->setStyleSheet("font-size: 10px; color: #666666;");
            QLabel *labelDescription = new QLabel(QString::fromStdString(f.getDescription()));
            labelDescription->setStyleSheet("font-size: 10px; color: #666666;");

            QVBoxLayout *titleDescriptionLayout = new QVBoxLayout();
            titleDescriptionLayout->addWidget(labelTitle);
            titleDescriptionLayout->setSpacing(0);
            titleDescriptionLayout->addWidget(labelDurationCast);
            titleDescriptionLayout->addWidget(labelDescription);
            QHBoxLayout *filmInfoLayout = new QHBoxLayout();
            filmInfoLayout->addLayout(titleDescriptionLayout);
            std::vector<tm> times = p.getTimesByFilmDate(f, date);
            for (const auto &t : times)
            {
                QString time = QString::fromStdString(Programming::createStringFromTm(t, "%H:%M"));
                QPushButton *buttonTime = new QPushButton(time);
                buttonTime->setFixedWidth(60);
                buttonTime->setCursor(Qt::PointingHandCursor);
                buttonTime->setStyleSheet("QPushButton { color: #333333; text-decoration: underline; }"
                                          "QPushButton:hover { text-decoration: underline; }");
                filmInfoLayout->addWidget(buttonTime);
                Hall h = p.getHall(f, t);
                connect(buttonTime, &QPushButton::clicked, [this, f, t, h]()
                        { openSelectSeat(f.getTitle(), t, h); });
            }
            filmLayout->addLayout(filmInfoLayout);
            layoutScheda->addWidget(filmWidget);
        }
        QString dateQString = QString::fromStdString(Programming::createStringFromTm(date, "%a %d/%m"));
        tabWidget->addTab(tab, dateQString);
        tabWidget->setStyleSheet("color:black");
    }
}

void FilmList::openSelectSeat(const std::string &filmTitle, const tm &time, const Hall &hall)
{
    ReservationManagement rm = ReservationList::readFromFile("reservations.txt", p);
    SelectSeat *selectSeat = new SelectSeat(filmTitle, time, hall, rm, this);
    selectSeat->show();
}