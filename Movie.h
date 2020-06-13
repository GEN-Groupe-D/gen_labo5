// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include "PriceCalculator.h"

class Movie {

public:
    static const int CHILDRENS   = 2;
    static const int REGULAR     = 0;
    static const int NEW_RELEASE = 1;

    PriceCalculator* priceCalculator;

    Movie( const std::string& title, PriceCalculator* calculator, int priceCode = REGULAR );

    int getPriceCode() const;
    void setPriceCode( int arg );
    std::string getTitle() const;
    double getPrice(int nbDays) const;
    int getFrequentPoint(int nbDays) const;


private:
    std::string _title;
    int _priceCode;
};

inline Movie::Movie( const std::string& title, PriceCalculator *calculator, int priceCode) : _title( title ), _priceCode( priceCode ) {

    priceCalculator = calculator;
}

inline int Movie::getPriceCode() const {

    return _priceCode;
}

inline void Movie::setPriceCode( int arg ) {

    _priceCode = arg;
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