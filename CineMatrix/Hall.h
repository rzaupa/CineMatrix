#ifndef HALL_H
#define HALL_H

#include "mySet.h"
#include "Seat.h"

class Hall
{
private:
    unsigned int id;
    unsigned int maxRow;
    unsigned int maxColumn;
    mySet<const Seat *> seats; // tutti i posti che non sono rimpiazzati con replace sono a prezzo intero

public:
    Hall(const unsigned int id, const unsigned int maxRow, const unsigned int maxColumn);
    unsigned int getId() const;
    unsigned int getMaxRow() const;
    unsigned int getMaxColumn() const;
    unsigned int getMaxSeats() const;
    const mySet<const Seat *> &getSeats() const;
    const Seat *getSeat(const unsigned int row, const unsigned int column) const;
    void replaceManySeats(const mySet<const Seat *> &s);
    void replaceSeat(const Seat &s);
    bool operator==(const Hall &hall) const;
};

#endif