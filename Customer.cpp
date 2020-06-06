// Customer.cpp
#include <sstream>
#include "Customer.h"
#include "RentalCalculator.h"


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

    for (const Rental& eachRental : _rentals) {

        RentalCalculator calculator = RentalCalculator(eachRental.getMovie().getPriceCode(), eachRental.getDaysRented());

        statementData.frequentRenterPoints += calculator.getFrequentRenterPoints();
    }


    return statementData;
}

vector<pair<string, double>> Customer::enrichRental() {

    vector<pair<string, double>> result;

    for (const Rental& eachRental : _rentals) {

        RentalCalculator calculator = RentalCalculator(eachRental.getMovie().getPriceCode(), eachRental.getDaysRented());

        result.emplace_back(eachRental.getMovie().getTitle(), calculator.getAmount());
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

int Customer::calculateFrequentRenterPoints(Rental eachRental) {

    int result = 0;

    //for (Rental eachRental : _rentals) {

        // add frequent renter points
        result++;

        // add bonus for a two day new release rental
        if ((eachRental.getMovie().getPriceCode() == Movie::NEW_RELEASE) && eachRental.getDaysRented() > 1 ){

            result++;
        }
    //}

    return result;
}

double Customer::totalAmount() {

    double result = 0;

    for (Rental eachRental : _rentals) {
        result += eachRental.amount();
    }

    return result;
}

