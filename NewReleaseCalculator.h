//
// Created by thomas on 06.06.20.
//

#ifndef LABO5_NEWRELEASECALCULATOR_H
#define LABO5_NEWRELEASECALCULATOR_H

#include "RentalCalculator.h"

class NewReleaseCalculator : public RentalCalculator {

public:

    NewReleaseCalculator(int daysRented)
            : RentalCalculator(daysRented) { }

    virtual double getAmount();
    virtual int getFrequentRenterPoints();
};

inline double NewReleaseCalculator::getAmount() {

    return daysRented * 3;
}

inline int NewReleaseCalculator::getFrequentRenterPoints() {

    int result = 1;

    // add bonus for a two day new release rental
    if (daysRented > 1 ){

        result++;
    }

    return result;
}
#endif //LABO5_NEWRELEASECALCULATOR_H
