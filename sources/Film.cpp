#include "Film.h"

Film::Film(const std::string title, const std::string director, const std::string cast, const unsigned int duration, const std::string description) : title(title), director(director), cast(cast), duration(duration), description(description) {}
const std::string &Film::getTitle() const
{
    return title;
}
const std::string &Film::getDirector() const
{
    return director;
}
const std::string &Film::getCast() const
{
    return cast;
}
unsigned int Film::getDuration() const
{
    return duration;
}
const std::string &Film::getDescription() const
{
    return description;
}
bool Film::operator==(const Film &film) const
{
    return title == film.title;
}