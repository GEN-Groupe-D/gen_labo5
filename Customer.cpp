// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"
#include "gtest/gtest.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement() {

    ostringstream result;

    result << "Rental Record for " << getName() << "\n";

    for (Rental eachRental : _rentals) {

        // show figures for this rental
        result << "\t" << eachRental.getMovie().getTitle() << "\t" << amountForRental(eachRental) << "\n";

    }

    // add footer lines
    result << "Amount owed is " << totalAmount() << "\n";
    result << "You earned " << calculateFrequentRenterPoints()
           << " frequent renter points";

    return result.str();
}

int Customer::calculateFrequentRenterPoints() {

    int result = 0;

    for (Rental eachRental : _rentals) {

        // add frequent renter points
        result++;

        // add bonus for a two day new release rental
        if ((eachRental.getMovie().getPriceCode() == Movie::NEW_RELEASE) && eachRental.getDaysRented() > 1 ){

            result++;
        }
    }

    return result;
}

double Customer::totalAmount() {

    double result = 0;

    for (Rental eachRental : _rentals) {
        result += amountForRental(eachRental);
    }

    return result;
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
