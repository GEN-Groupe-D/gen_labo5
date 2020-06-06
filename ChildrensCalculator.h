//
// Created by thomas on 06.06.20.
//

#ifndef LABO5_CHILDRENSCALCULATOR_H
#define LABO5_CHILDRENSCALCULATOR_H

#include "RentalCalculator.h"

class ChildrensCalculator : public RentalCalculator {

public:

    ChildrensCalculator(int moviePriceCode, int daysRented)
            : RentalCalculator(moviePriceCode, daysRented) { }

    virtual double getAmount();
};

inline double ChildrensCalculator::getAmount() {

    double result = 1.5;

    if ( daysRented > 3 )
        result += ( daysRented - 3 ) * 1.5;

    return result;
}


#endif //LABO5_CHILDRENSCALCULATOR_H
