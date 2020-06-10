// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
    Rental( const Movie& movie, int daysRented );
    Rental();

    const Movie& getMovie() const;
    virtual int getDaysRented() const;
    virtual int getMoviePriceCode() const;
    virtual std::string getMovieTitle() const;



private:
    Movie _movie;
    int _daysRented;
};

inline Rental::Rental( const Movie& movie, int daysRented ) : _movie( movie ), _daysRented( daysRented ) {}

//CONSTRUCTOR FOR MOCK TEST
inline Rental::Rental() : _movie(Movie("DEFAULT")), _daysRented(0) { }

inline int Rental::getDaysRented() const {

    return _daysRented;
}

inline const Movie& Rental::getMovie() const {

    return _movie;
}

inline int Rental::getMoviePriceCode() const {

    return _movie.getPriceCode();
}

inline std::string Rental::getMovieTitle() const {

    return _movie.getTitle();
}


#endif // RENTAL_H