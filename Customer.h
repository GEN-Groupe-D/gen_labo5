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

    void addRental( const Rental& arg );
    std::string getName() const;
    std::string statement();

private:
    std::string _name;
    std::vector< Rental > _rentals;

    struct StatementData {

        std::string customerName;

        //contains movie title, amount of this movie rent
        std::vector<std::pair<std::string, double>> rentalsInfos;

        double totalAmount;
        int frequentRenterPoints;

    };

    double totalAmount();

    int calculateFrequentRenterPoints(Rental eachRental);

    std::string renderPlainText(StatementData data);

    std::vector<std::pair<std::string, double>> enrichRental();

    StatementData CreateStatementData();

};

inline Customer::
Customer() {}

inline Customer::
Customer( const std::string& name )
        : _name( name ) {}

inline void Customer::
addRental( const Rental& arg ) { _rentals.push_back( arg ); }

inline std::string Customer::
getName() const { return _name; }

#endif // CUSTOMER_H