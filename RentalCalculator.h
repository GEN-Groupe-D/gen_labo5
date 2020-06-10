//
// Created by thomas on 06.06.20.
//

#ifndef LABO5_RENTALCALCULATOR_H
#define LABO5_RENTALCALCULATOR_H

#include "Rental.h"

class RentalCalculator {

public:

    RentalCalculator(int daysRented)
        : daysRented(daysRented) { }


    virtual double getAmount() = 0;

    virtual int getFrequentRenterPoints();


    int daysRented;
};


inline int RentalCalculator::getFrequentRenterPoints() {

    return 1;
}



#endif //LABO5_RENTALCALCULATOR_H
