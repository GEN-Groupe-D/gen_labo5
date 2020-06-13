// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"
#include "ChildrensCalculator.h"
#include "RegularCalculator.h"

class Rental {
public:
    Rental( Movie* movie, int daysRented );
    Rental();
    ~Rental();

    virtual int getDaysRented() const;
    virtual std::string getMovieTitle() const;
    virtual double getMoviePrice() const;
    virtual int getMovieFrequentPoint() const;

private:
    Movie* _movie;
    int _daysRented;
};

inline Rental::Rental( Movie* movie, int daysRented ) : _daysRented( daysRented ) {

    _movie = movie;
}

//CONSTRUCTOR FOR MOCK TEST
inline Rental::Rental() : _daysRented(0) {

    _movie = new Movie("DEFAULT", new RegularCalculator());
}

inline Rental::~Rental() {

    //delete _movie;
}

inline int Rental::getDaysRented() const {

    return _daysRented;
}


//REMOVE MESSAGE CHAIN BETWEEN Customer and Movie
inline std::string Rental::getMovieTitle() const {

    return _movie->getTitle();
}

inline double Rental::getMoviePrice() const{

    return _movie->getPrice(_daysRented);
}

inline int Rental::getMovieFrequentPoint() const{

    return _movie->getFrequentPoint(_daysRented);
}

#endif // RENTAL_H