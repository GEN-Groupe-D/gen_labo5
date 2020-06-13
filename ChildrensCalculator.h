//
// Created by thomas on 06.06.20.
//

#ifndef LABO5_CHILDRENSCALCULATOR_H
#define LABO5_CHILDRENSCALCULATOR_H

#include "PriceCalculator.h"

class ChildrensCalculator : public PriceCalculator {

public:

    ChildrensCalculator() { }


    virtual double getAmount(int daysRented);
};

inline double ChildrensCalculator::getAmount(int daysRented) {

    double result = 1.5;

    if ( daysRented > 3 )
        result += ( daysRented - 3 ) * 1.5;

    return result;
}


#endif //LABO5_CHILDRENSCALCULATOR_H
