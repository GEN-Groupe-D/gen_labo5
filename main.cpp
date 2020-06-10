#include <iostream>

#include "Customer.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "NewReleaseCalculator.h"
#include "RegularCalculator.h"
#include "ChildrensCalculator.h"

using namespace std;

struct ConsumerTest : testing::Test {

    Customer customer;

    ConsumerTest() {

        customer = Customer("Olivier");
        customer.addRental( Rental( Movie("Karate Kid"), 7));
        customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
        customer.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));

    }
};


TEST(NewReleaseCalculator, AmountIsCorrect) {

    NewReleaseCalculator newReleaseCalculator = NewReleaseCalculator(5);

    ASSERT_EQ(newReleaseCalculator.getAmount(), 15);

}

TEST(NewReleaseCalculator, FrequentPointIsCorrect) {


    NewReleaseCalculator newReleaseCalculator = NewReleaseCalculator(1);

    EXPECT_EQ(newReleaseCalculator.getFrequentRenterPoints(), 1);


    newReleaseCalculator = NewReleaseCalculator(5);

    EXPECT_EQ(newReleaseCalculator.getFrequentRenterPoints(), 2);
}


TEST(ChildrensCalculator, AmountIsCorrect) {

    ChildrensCalculator childrensCalculator = ChildrensCalculator(2);

    EXPECT_EQ(childrensCalculator.getAmount(), 1.5);

    childrensCalculator = ChildrensCalculator(5);

    EXPECT_EQ(childrensCalculator.getAmount(), 4.5);

}

TEST(ChildrensCalculator, FrequentPointIsCorrect) {


    ChildrensCalculator childrensCalculator = ChildrensCalculator(5);

    ASSERT_EQ(childrensCalculator.getFrequentRenterPoints(), 1);
}


TEST(RegularCalculator, AmountIsCorrect) {

    RegularCalculator regularCalculator = RegularCalculator(1);

    EXPECT_EQ(regularCalculator.getAmount(), 2);

    regularCalculator = RegularCalculator(5);

    EXPECT_EQ(regularCalculator.getAmount(), 6.5);

}

TEST(RegularCalculator, FrequentPointIsCorrect) {


    RegularCalculator regularCalculator = RegularCalculator(5);

    ASSERT_EQ(regularCalculator.getFrequentRenterPoints(), 1);
}

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