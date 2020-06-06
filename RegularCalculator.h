//
// Created by thomas on 06.06.20.
//

#ifndef LABO5_REGULARCALCULATOR_H
#define LABO5_REGULARCALCULATOR_H

#include "RentalCalculator.h"

class RegularCalculator : public RentalCalculator {

public:

    RegularCalculator(int moviePriceCode, int daysRented)
            : RentalCalculator(moviePriceCode, daysRented) { }

    virtual double getAmount();
};

inline double RegularCalculator::getAmount() {

    double result = 2;

    if ( daysRented > 2 )
        result += ( daysRented - 2 ) * 1.5 ;

    return result;
}


#endif //LABO5_REGULARCALCULATOR_H
