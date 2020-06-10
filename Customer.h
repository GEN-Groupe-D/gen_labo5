// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "Rental.h"
#include "RentalCalculator.h"

class Customer {
public:
    Customer();
    explicit Customer( const std::string& name );

    void addRental(  Rental* arg );

    std::string getName() const;
    std::string statement();

private:

    std::string _name;

    std::vector< Rental* > _rentals;

    struct StatementData {

        std::string customerName;

        //contains movie title, amount of this movie rent
        std::vector<std::pair<std::string, double>> rentalsInfos;

        double totalAmount;
        int frequentRenterPoints;

    };

    double totalAmount();


    std::string renderPlainText(StatementData data);

    std::vector<std::pair<std::string, double>> enrichRental();

    StatementData CreateStatementData();

    RentalCalculator * createRentalCalculator(int moviePriceCode, int daysRented);
};

inline Customer::Customer() {}

inline Customer::Customer( const std::string& name ) : _name( name ) {}

inline void Customer::addRental(  Rental* arg ) {

    _rentals.push_back( arg );
}

inline std::string Customer::getName() const {
    return _name;
}

#endif // CUSTOMER_H