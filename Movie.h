// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include "PriceCalculator.h"

class Movie {

public:

    PriceCalculator* priceCalculator;

    Movie( const std::string& title, PriceCalculator* calculator);

    void setPriceCode( int arg );
    std::string getTitle() const;
    double getPrice(int nbDays) const;
    int getFrequentPoint(int nbDays) const;


private:
    std::string _title;
};

inline Movie::Movie( const std::string& title, PriceCalculator *calculator) : _title( title ) {

    priceCalculator = calculator;
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