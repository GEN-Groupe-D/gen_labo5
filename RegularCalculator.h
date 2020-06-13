//
// Created by thomas on 06.06.20.
//

#ifndef LABO5_REGULARCALCULATOR_H
#define LABO5_REGULARCALCULATOR_H

#include "PriceCalculator.h"

class RegularCalculator : public PriceCalculator {

public:

    RegularCalculator() { }

    virtual double getAmount(int daysRented);
};

inline double RegularCalculator::getAmount(int daysRented) {

    double result = 2;

    if ( daysRented > 2 )
        result += ( daysRented - 2 ) * 1.5 ;

    return result;
}


#endif //LABO5_REGULARCALCULATOR_H
