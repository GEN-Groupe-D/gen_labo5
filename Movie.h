// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include "PriceCalculator.h"
#include "RegularCalculator.h"

class Movie {

public:


    Movie( const std::string& title, PriceCalculator* calculator);
    Movie();
    ~Movie();

    virtual std::string getTitle() const;
    virtual double getPrice(int nbDays) const;
    virtual int getFrequentPoint(int nbDays) const;


private:
    std::string _title;
    PriceCalculator* priceCalculator;
};

inline Movie::Movie( const std::string& title, PriceCalculator *calculator) : _title( title ) {

    priceCalculator = calculator;
}

inline Movie::~Movie() {

    delete priceCalculator;
}

inline Movie::Movie() {
    _title = "";
    priceCalculator = new RegularCalculator();
}

inline std::string Movie::getTitle() const {

    return _title;
}

inline double Movie::getPrice(int nbDays) const{

    return priceCalculator->getAmount(nbDays);
}

inline int Movie::getFrequentPoint(int nbDays) const{

    return priceCalculator->getFrequentRenterPoints(nbDays);
}




#endif // MOVIE_H