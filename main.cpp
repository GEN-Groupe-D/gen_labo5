#include <iostream>

#include "gtest/gtest.h"

using namespace std;






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