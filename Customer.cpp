// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"
#include "gtest/gtest.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement() {

    double totalAmount = 0;
    int frequentRenterPoints = 0;

    ostringstream result;

    result << "Rental Record for " << getName() << "\n";

    for (Rental eachRental : _rentals) {

        // add frequent renter points
        frequentRenterPoints++;

        // add bonus for a two day new release rental
        if ((eachRental.getMovie().getPriceCode() == Movie::NEW_RELEASE) && eachRental.getDaysRented() > 1 ){

            frequentRenterPoints++;
        }

        // show figures for this rental
        result << "\t" << eachRental.getMovie().getTitle() << "\t" << amountForRental(eachRental) << "\n";
        totalAmount += amountForRental(eachRental);
    }

    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";

    return result.str();
}

double Customer::amountForRental(Rental each) {

    double result = 0;

    // determine amounts for each line
    switch ( each.getMovie().getPriceCode() ) {
        case Movie::REGULAR:
            result += 2;
            if ( each.getDaysRented() > 2 )
                result += ( each.getDaysRented() - 2 ) * 1.5 ;
            break;
        case Movie::NEW_RELEASE:
            result += each.getDaysRented() * 3;
            break;
        case Movie::CHILDRENS:
            result += 1.5;
            if ( each.getDaysRented() > 3 )
                result += ( each.getDaysRented() - 3 ) * 1.5;
            break;
    }

    return result;
}
