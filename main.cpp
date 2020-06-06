#include <iostream>

#include "Customer.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;

struct ConsumerTest : testing::Test {

    Customer customer;

    ConsumerTest() {

        customer = Customer("Olivier");
        customer.addRental( Rental( Movie("Karate Kid"), 7));
        customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
        customer.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));

    }

    ~ConsumerTest() {

    }

};


//TEST customer statement
TEST_F(ConsumerTest, ConsumerStatementValue){

    string expectedStatement = "Rental Record for Olivier\n\tKarate Kid\t9.5\n\tAvengers: Endgame\t15\n\tSnow White\t1.5\nAmount owed is 26\nYou earned 4 frequent renter points";

    ASSERT_EQ(customer.statement(), expectedStatement);
}


int main() {

    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
    customer.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));

    std::cout << customer.statement() << std::endl;


    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}