#ifndef FILM_H
#define FILM_H

#include <string>

class Film
{
private:
    std::string title;
    std::string director;
    std::string cast;
    unsigned int duration; // minutes
    std::string description;

public:
    Film(const std::string title, const std::string director, const std::string cast, const unsigned int duration, const std::string description);
    const std::string &getTitle() const;
    const std::string &getDirector() const;
    const std::string &getCast() const;
    const std::string &getDescription() const;
    unsigned int getDuration() const;
    bool operator==(const Film &film) const;
};

#endif