//
// Created by thomas on 06.06.20.
//

#ifndef LABO5_PRICECALCULATOR_H
#define LABO5_PRICECALCULATOR_H

class PriceCalculator {

public:

    PriceCalculator() { }


    virtual double getAmount(int daysRented) = 0;

    virtual int getFrequentRenterPoints(int daysRented);
};


inline int PriceCalculator::getFrequentRenterPoints(int daysRented) {

    return 1;
}



#endif //LABO5_PRICECALCULATOR_H
