//
// Created by thomas on 13.06.20.
//
#include <iostream>
#include "Customer.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;


class MockRental : public Rental {
public:
    MOCK_METHOD(int, getDaysRented, (), (const));
    MOCK_METHOD(string, getMovieTitle, (), (const));
    MOCK_METHOD(int, getMoviePriceCode, (), (const));
};


TEST(Customer, StatementIsCorrect) {

    MockRental rental1;
    MockRental rental2;
    MockRental rental3;


    EXPECT_CALL(rental1, getMovieTitle()).WillRepeatedly(testing::Return("Karate Kid"));
    EXPECT_CALL(rental1, getMoviePriceCode()).WillRepeatedly(testing::Return(Movie::REGULAR));
    EXPECT_CALL(rental1, getDaysRented()).WillRepeatedly(testing::Return(7));

    EXPECT_CALL(rental2, getMovieTitle()).WillRepeatedly(testing::Return("Avengers: Endgame"));
    EXPECT_CALL(rental2, getMoviePriceCode()).WillRepeatedly(testing::Return(Movie::NEW_RELEASE));
    EXPECT_CALL(rental2, getDaysRented()).WillRepeatedly(testing::Return(5));

    EXPECT_CALL(rental3, getMovieTitle()).WillRepeatedly(testing::Return("Snow White"));
    EXPECT_CALL(rental3, getMoviePriceCode()).WillRepeatedly(testing::Return(Movie::CHILDRENS));
    EXPECT_CALL(rental3, getDaysRented()).WillRepeatedly(testing::Return(3));

    //    Rental* r = &rental1;

    //    ASSERT_EQ(r->getMovieTitle(), "Karate Kid");

    Customer customer = Customer("Olivier");

    customer.addRental(&rental1);
    customer.addRental(&rental2);
    customer.addRental(&rental3);

    //    cout << customer.statement() << endl;

    ASSERT_EQ(customer.statement(), std::string("Rental Record for Olivier\n\tKarate Kid\t9.5\n\tAvengers: Endgame\t15\n\tSnow White\t1.5\nAmount owed is 26\nYou earned 4 frequent renter points"));

}