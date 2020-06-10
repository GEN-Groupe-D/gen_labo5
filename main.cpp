#include <iostream>

#include "Customer.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "NewReleaseCalculator.h"
#include "RegularCalculator.h"
#include "ChildrensCalculator.h"

using namespace std;

class MockRental : public Rental {
public:
    MOCK_METHOD(int, getDaysRented, (), (const));
    MOCK_METHOD(string, getMovieTitle, (), (const));
    MOCK_METHOD(int, getMoviePriceCode, (), (const));
};


TEST(Customer, StatementIsCorrect) {

    MockRental rental1;


    EXPECT_CALL(rental1, getDaysRented()).WillRepeatedly(testing::Return(7));
    EXPECT_CALL(rental1, getMovieTitle()).WillRepeatedly(testing::Return("Karate Kid"));
    EXPECT_CALL(rental1, getMoviePriceCode()).WillRepeatedly(testing::Return(Movie::REGULAR));

//    Rental* r = &rental1;

//    ASSERT_EQ(r->getMovieTitle(), "Karate Kid");

    Customer customer = Customer("Olivier");

    customer.addRental(&rental1);

//    cout << customer.statement() << endl;

    ASSERT_EQ(customer.statement(), std::string("Rental Record for Olivier\n\tKarate Kid\t9.5\nAmount owed is 9.5\nYou earned 1 frequent renter points"));

}

//TEST(NewReleaseCalculator, AmountIsCorrect) {
//
//    NewReleaseCalculator newReleaseCalculator = NewReleaseCalculator(5);
//
//    ASSERT_EQ(newReleaseCalculator.getAmount(), 15);
//
//}
//
//TEST(NewReleaseCalculator, FrequentPointIsCorrect) {
//
//
//    NewReleaseCalculator newReleaseCalculator = NewReleaseCalculator(1);
//
//    EXPECT_EQ(newReleaseCalculator.getFrequentRenterPoints(), 1);
//
//
//    newReleaseCalculator = NewReleaseCalculator(5);
//
//    EXPECT_EQ(newReleaseCalculator.getFrequentRenterPoints(), 2);
//}
//
//
//TEST(ChildrensCalculator, AmountIsCorrect) {
//
//    ChildrensCalculator childrensCalculator = ChildrensCalculator(2);
//
//    EXPECT_EQ(childrensCalculator.getAmount(), 1.5);
//
//    childrensCalculator = ChildrensCalculator(5);
//
//    EXPECT_EQ(childrensCalculator.getAmount(), 4.5);
//
//}
//
//TEST(ChildrensCalculator, FrequentPointIsCorrect) {
//
//
//    ChildrensCalculator childrensCalculator = ChildrensCalculator(5);
//
//    ASSERT_EQ(childrensCalculator.getFrequentRenterPoints(), 1);
//}
//
//
//TEST(RegularCalculator, AmountIsCorrect) {
//
//    RegularCalculator regularCalculator = RegularCalculator(1);
//
//    EXPECT_EQ(regularCalculator.getAmount(), 2);
//
//    regularCalculator = RegularCalculator(5);
//
//    EXPECT_EQ(regularCalculator.getAmount(), 6.5);
//
//}
//
//TEST(RegularCalculator, FrequentPointIsCorrect) {
//
//
//    RegularCalculator regularCalculator = RegularCalculator(5);
//
//    ASSERT_EQ(regularCalculator.getFrequentRenterPoints(), 1);
//}
//
////TEST customer statement
//TEST(ConsumerTest, ConsumerStatementValue){
//
//    Customer customer = Customer("Olivier");
//    customer.addRental( Rental( Movie("Karate Kid"), 7));
//    customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
//    customer.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));
//
//    string expectedStatement = "Rental Record for Olivier\n\tKarate Kid\t9.5\n\tAvengers: Endgame\t15\n\tSnow White\t1.5\nAmount owed is 26\nYou earned 4 frequent renter points";
//
//    ASSERT_EQ(customer.statement(), expectedStatement);
//}


int main() {

    //Rental* rental1 = &Rental(Movie("Karate Kid"), 7);

//    unique_ptr<const Rental> rental1 (new Rental(Movie("Karate Kid"), 7));
//
//
//    Customer customer("Olivier");
//    customer.addRental( rental1.get());
////    customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
////    customer.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));
//
//    std::cout << customer.statement() << std::endl;
//
//
//    delete rental1;

    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}