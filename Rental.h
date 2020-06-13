// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"
#include "ChildrensCalculator.h"
#include "RegularCalculator.h"

class Rental {
public:
    Rental( const Movie& movie, int daysRented );
    Rental();

    const Movie& getMovie() const;
    virtual int getDaysRented() const;
    virtual int getMoviePriceCode() const;
    virtual std::string getMovieTitle() const;
    virtual double getMoviePrice() const;
    virtual int getMovieFrequentPoint() const;

private:
    Movie _movie;
    int _daysRented;
};

inline Rental::Rental( const Movie& movie, int daysRented ) : _movie( movie ), _daysRented( daysRented ) {}

//CONSTRUCTOR FOR MOCK TEST
inline Rental::Rental() : _movie(Movie("DEFAULT", new RegularCalculator())), _daysRented(0) { }

inline int Rental::getDaysRented() const {

    return _daysRented;
}

inline const Movie& Rental::getMovie() const {

    return _movie;
}

//REMOVE MESSAGE CHAIN BETWEEN Customer and Movie
inline int Rental::getMoviePriceCode() const {

    return _movie.getPriceCode();
}

//REMOVE MESSAGE CHAIN BETWEEN Customer and Movie
inline std::string Rental::getMovieTitle() const {

    return _movie.getTitle();
}

inline double Rental::getMoviePrice() const{

    return _movie.getPrice(_daysRented);
}

inline int Rental::getMovieFrequentPoint() const{

    return _movie.getFrequentPoint(_daysRented);
}

#endif // RENTAL_H