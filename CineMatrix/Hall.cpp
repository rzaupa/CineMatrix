#include "Hall.h"
#include "FullPriceSeat.h"

bool seatEqual(const Seat *const &a, const Seat *const &b)
{
    return a->getRow() == b->getRow() && a->getColumn() == b->getColumn();
}

Hall::Hall(const unsigned int id, const unsigned int maxRow, const unsigned int maxColumn) : id(id), maxRow(maxRow), maxColumn(maxColumn), seats(seatEqual)
{
    for (unsigned int i = 1; i <= maxRow; i++)
    {
        for (unsigned int j = 1; j <= maxColumn; j++)
        {
            FullPriceSeat *fullPriceSeat = new FullPriceSeat(i, j);
            seats.push_back(fullPriceSeat);
        }
    }
}

unsigned int Hall::getId() const
{
    return id;
}
unsigned int Hall::getMaxRow() const
{
    return maxRow;
}
unsigned int Hall::getMaxColumn() const
{
    return maxColumn;
}
unsigned int Hall::getMaxSeats() const
{
    return maxRow * maxColumn;
}
const mySet<const Seat *> &Hall::getSeats() const
{
    return seats;
}

const Seat *Hall::getSeat(const unsigned int row, const unsigned int column) const
{
    const FullPriceSeat seat(row, column);
    auto it = seats.find((const Seat *)&seat);
    return *it;
}

void Hall::replaceManySeats(const mySet<const Seat *> &s)
{
    for (const auto &seat : s)
    {
        replaceSeat(*seat);
    }
}

void Hall::replaceSeat(const Seat &s)
{
    auto it = seats.find(&s);
    if (it != seats.end())
    {
        Seat *seat = s.clone();
        delete seats.remove(seat);
        seats.push_back(seat);
    }
}

bool Hall::operator==(const Hall &hall) const
{
    return id == hall.getId();
}