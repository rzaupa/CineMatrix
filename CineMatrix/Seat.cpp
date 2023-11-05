#include "Seat.h"

Seat::Seat(const unsigned int row, const unsigned int column) : row(row), column(column) {}

unsigned int Seat::getRow() const
{
    return row;
}

unsigned int Seat::getColumn() const
{
    return column;
}