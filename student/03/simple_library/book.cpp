#include "book.hh"
#include "date.hh"
#include "iostream"

Book::Book(std::string nimi, std::string kirjoittaja):
    nimi_(nimi), kirjoittaja_(kirjoittaja)
{
    lainassa_ = false;

}
void Book::print() const{
    std::cout << nimi_ << " : " << kirjoittaja_ << std::endl;
    if (lainassa_){
        std::cout << "- loaned: ";
        lainaus_pvm_.print();
        std::cout << "- to be returned: ";
        palautus_pvm_.print();
    } else {
        std::cout << "- available" << std::endl;
    }
}

void Book::loan(Date loaning_day){
    if (lainassa_){
        std::cout << "Already loaned: cannot be loaned" << std::endl;
    } else {
        lainassa_ = true;
        lainaus_pvm_ = loaning_day;
        loaning_day.advance(28);
        palautus_pvm_ = loaning_day;
    }

}

void Book::give_back(){
    if (lainassa_){
        lainassa_ = false;
    }
}

void Book::renew(){
    if (lainassa_){
        palautus_pvm_.advance(28);
    } else {
        std::cout << "Not loaned: cannot be renewed" << std::endl;
    }
}
