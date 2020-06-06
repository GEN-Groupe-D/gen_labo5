// Customer.cpp
#include <sstream>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement() {

    ostringstream result;

    result << "Rental Record for " << getName() << "\n";

    for (Rental eachRental : _rentals) {

        // show figures for this rental
        result << "\t" << eachRental.getMovie().getTitle() << "\t" << eachRental.amount() << "\n";

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
        result += eachRental.amount();
    }

    return result;
}

