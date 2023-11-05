#ifndef PROGRAMMING_H
#define PROGRAMMING_H

#include <vector>
#include "Film.h"
#include "Hall.h"

class Programming
{
private:
    class Screening
    {
    public:
        Film film;
        tm dateTime;
        Hall hall;
        Screening(const Film &film, const tm &dateTime, const Hall &hall);
    };

    std::vector<Screening> screenings;

public:
    void addSchedule(const Film &film, const tm &dateTime, const Hall &hall);
    void removeSchedule(const Film &film, const tm &dateTime);
    const std::vector<Film> getFilms() const;
    const std::vector<tm> getDates() const;
    const std::vector<Hall> getHalls() const;
    const Hall &getHall(const Film &film, const tm &date) const;
    const std::vector<Film> getFilmsByDate(const tm &date) const;
    const std::vector<tm> getTimesByFilmDate(const Film &film, const tm &date) const;

    // funzionalità utili per tm
    static bool datesAreEqual(const tm &tm1, const tm &tm2);
    static bool timesAreEqual(const tm &tm1, const tm &tm2);
    static bool compareDates(const tm &tm1, const tm &tm2);
    static tm createTmFromString(const std::string &dateString, const std::string &format);
    static std::string createStringFromTm(const tm &dateTm, const std::string &format);
};

#endif