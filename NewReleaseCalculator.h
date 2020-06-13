//
// Created by thomas on 06.06.20.
//

#ifndef LABO5_NEWRELEASECALCULATOR_H
#define LABO5_NEWRELEASECALCULATOR_H

#include "PriceCalculator.h"

class NewReleaseCalculator : public PriceCalculator {

public:

    NewReleaseCalculator() { }

    virtual double getAmount(int daysRented);
    virtual int getFrequentRenterPoints(int daysRented);
};

inline double NewReleaseCalculator::getAmount(int daysRented) {

    return daysRented * 3;
}

inline int NewReleaseCalculator::getFrequentRenterPoints(int daysRented) {

    int result = 1;

    // add bonus for a two day new release rental
    if (daysRented > 1 ){

        result++;
    }

    return result;
}
#endif //LABO5_NEWRELEASECALCULATOR_H
