#include <iostream>

#include "Customer.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"


// Simple test, does not use gmock
TEST(Dummy, foobar)
{
    EXPECT_EQ(1, 1);
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