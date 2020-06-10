// Customer.cpp
#include <sstream>
#include "Customer.h"
#include "RentalCalculator.h"
#include "RegularCalculator.h"
#include "NewReleaseCalculator.h"
#include "ChildrensCalculator.h"


using std::ostringstream;
using std::vector;

using namespace std;


string Customer::statement() {

    return renderPlainText(CreateStatementData());
}

Customer::StatementData Customer::CreateStatementData(){

    StatementData statementData = StatementData();


    statementData.customerName = getName();
    statementData.rentalsInfos = enrichRental();
    statementData.totalAmount = totalAmount();

    statementData.frequentRenterPoints = 0;

    for (const Rental* eachRental : _rentals) {

        RentalCalculator* calculator = createRentalCalculator(eachRental->getMoviePriceCode(), eachRental->getDaysRented());

        statementData.frequentRenterPoints += calculator->getFrequentRenterPoints();

        delete calculator;
    }


    return statementData;
}

RentalCalculator * Customer::createRentalCalculator(int moviePriceCode, int daysRented) {

    switch ( moviePriceCode ) {
        case Movie::REGULAR:
            return new RegularCalculator(daysRented);
            break;
        case Movie::NEW_RELEASE:
            return new NewReleaseCalculator(daysRented);
            break;
        case Movie::CHILDRENS:
            return new ChildrensCalculator(daysRented);

            break;
    }
}

vector<pair<string, double>> Customer::enrichRental() {

    vector<pair<string, double>> result;

    for (const Rental* eachRental : _rentals) {

        RentalCalculator* calculator = createRentalCalculator(eachRental->getMoviePriceCode(), eachRental->getDaysRented());

        result.emplace_back(eachRental->getMovieTitle(), calculator->getAmount());

        delete calculator;
    }

    return result;
}

string Customer::renderPlainText(StatementData data) {

    ostringstream result;

    result << "Rental Record for " << data.customerName << "\n";

    for (auto rentalInfo: data.rentalsInfos) {

        // show figures for this rental
        result << "\t" << rentalInfo.first << "\t" << rentalInfo.second << "\n";

    }

    // add footer lines
    result << "Amount owed is " << data.totalAmount << "\n";
    result << "You earned " << data.frequentRenterPoints
           << " frequent renter points";

    return result.str();
}

double Customer::totalAmount() {

    double result = 0;

    for (const Rental* eachRental : _rentals) {

        RentalCalculator* calculator = createRentalCalculator(eachRental->getMoviePriceCode(), eachRental->getDaysRented());

        result += calculator->getAmount();

        delete calculator;
    }

    return result;
}

