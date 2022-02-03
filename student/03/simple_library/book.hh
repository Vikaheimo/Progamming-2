#ifndef BOOK_HH
#define BOOK_HH
#include "date.hh"
#include <string>


class Book
{
public:
    Book(std::string nimi, std::string kirjoittaja);

    void print() const;

    void loan(Date loaning_day);

    void renew();

    void give_back();

private:
    std::string nimi_;
    std::string kirjoittaja_;
    bool lainassa_;
    Date palautus_pvm_;
    Date lainaus_pvm_;

};

#endif // BOOK_HH
