#include "Programming.h"
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <algorithm>

Programming::Screening::Screening(const Film &film, const tm &dateTime, const Hall &hall) : film(film), dateTime(dateTime), hall(hall) {}

void Programming::addSchedule(const Film &film, const tm &dateTime, const Hall &hall)
{
    Screening screening(film, dateTime, hall);
    screenings.push_back(screening);
}

void Programming::removeSchedule(const Film &film, const tm &dateTime)
{
    for (auto it = screenings.begin(); it != screenings.end(); ++it)
    {
        if (it->film == film && datesAreEqual(it->dateTime, dateTime) && timesAreEqual(it->dateTime, dateTime))
        {
            screenings.erase(it);
            break;
        }
    }
}

const std::vector<Film> Programming::getFilms() const
{
    std::vector<Film> filmList;

    for (const auto &s : screenings)
    {
        bool filmFound = false;
        for (const auto &film : filmList)
        {
            if (film == s.film)
            {
                filmFound = true;
                break;
            }
        }
        if (!filmFound)
        {
            filmList.push_back(s.film);
        }
    }

    return filmList;
}

const std::vector<tm> Programming::getDates() const
{
    std::vector<tm> dateList;

    for (const auto &s : screenings)
    {
        bool dateFound = false;
        for (const auto &date : dateList)
        {
            if (datesAreEqual(s.dateTime, date))
            {
                dateFound = true;
                break;
            }
        }
        if (!dateFound)
        {
            dateList.push_back(s.dateTime);
        }
    }
    std::sort(dateList.begin(), dateList.end(), compareDates);

    return dateList;
}

const std::vector<Hall> Programming::getHalls() const
{
    std::vector<Hall> halls;
    for (const auto &s : screenings)
    {
        bool hallFound = false;
        for (const auto &hall : halls)
        {
            if (hall == s.hall)
            {
                hallFound = true;
                break;
            }
        }
        if (!hallFound)
        {
            halls.push_back(s.hall);
        }
    }
    return halls;
}
const Hall &Programming::getHall(const Film &film, const tm &date) const
{
    for (const auto &s : screenings)
    {
        if (s.film == film && datesAreEqual(s.dateTime, date) && timesAreEqual(s.dateTime, date))
        {
            return s.hall;
        }
    }
    throw std::runtime_error("Hall not found for the given film and date");
}
const std::vector<Film> Programming::getFilmsByDate(const tm &date) const
{
    std::vector<Film> filmsByDate;

    for (const auto &screening : screenings)
    {
        if (datesAreEqual(screening.dateTime, date))
        {
            bool filmFound = false;
            for (const auto &film : filmsByDate)
            {
                if (film == screening.film)
                {
                    filmFound = true;
                    break;
                }
            }
            if (!filmFound)
            {
                filmsByDate.push_back(screening.film);
            }
        }
    }

    return filmsByDate;
}
const std::vector<tm> Programming::getTimesByFilmDate(const Film &film, const tm &date) const
{
    std::vector<tm> timeList;

    for (const auto &s : screenings)
    {
        if (s.film == film && datesAreEqual(date, s.dateTime))
        {
            timeList.push_back(s.dateTime);
        }
    }

    return timeList;
}

bool Programming::datesAreEqual(const tm &tm1, const tm &tm2)
{
    return tm1.tm_mday == tm2.tm_mday && tm1.tm_mon == tm2.tm_mon && tm1.tm_year == tm2.tm_year;
}

bool Programming::timesAreEqual(const tm &tm1, const tm &tm2)
{
    return tm1.tm_hour == tm2.tm_hour && tm1.tm_min == tm2.tm_min;
}

bool Programming::compareDates(const tm &tm1, const tm &tm2)
{
    if (tm1.tm_year != tm2.tm_year)
        return tm1.tm_year < tm2.tm_year;
    if (tm1.tm_mon != tm2.tm_mon)
        return tm1.tm_mon < tm2.tm_mon;
    if (tm1.tm_mday != tm2.tm_mday)
        return tm1.tm_mday < tm2.tm_mday;
    if (tm1.tm_hour != tm2.tm_hour)
        return tm1.tm_hour < tm2.tm_hour;
    return tm1.tm_min < tm2.tm_min;
}
tm Programming::createTmFromString(const std::string &dateString, const std::string &format)
{
    tm dateTm = {};
    std::istringstream iss(dateString);
    iss >> std::get_time(&dateTm, format.c_str());
    if (iss.fail())
    {
        throw std::runtime_error("Error in date conversion.");
    }
    return dateTm;
}

std::string Programming::createStringFromTm(const tm &dateTm, const std::string &format)
{
    std::ostringstream oss;
    oss << std::put_time(&dateTm, format.c_str());
    if (oss.fail())
    {
        throw std::runtime_error("Error in date conversion.");
    }
    return oss.str();
}