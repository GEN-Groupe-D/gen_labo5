//
// Created by thomas on 06.06.20.
//

#ifndef LABO5_RENTALCALCULATOR_H
#define LABO5_RENTALCALCULATOR_H

#include "Rental.h"

class RentalCalculator {

public:

    RentalCalculator(int moviePriceCode, int daysRented)
        : moviePriceCode(moviePriceCode)
        , daysRented(daysRented) { }


    double getAmount();
    int getFrequentRenterPoints();


private:

    int moviePriceCode;
    int daysRented;
};

inline double RentalCalculator::getAmount() {

    double result = 0;

    // determine amounts of the rental
    switch ( moviePriceCode ) {
        case Movie::REGULAR:
            result += 2;
            if ( daysRented > 2 )
                result += ( daysRented - 2 ) * 1.5 ;
            break;
        case Movie::NEW_RELEASE:
            result += daysRented * 3;
            break;
        case Movie::CHILDRENS:
            result += 1.5;
            if ( daysRented > 3 )
                result += ( daysRented - 3 ) * 1.5;
            break;
    }

    return result;
}

inline int RentalCalculator::getFrequentRenterPoints() {

    int result = 0;


    // add frequent renter points
    result++;

    // add bonus for a two day new release rental
    if ((moviePriceCode == Movie::NEW_RELEASE) && daysRented > 1 ){

        result++;
    }


    return result;
}


#endif //LABO5_RENTALCALCULATOR_H
