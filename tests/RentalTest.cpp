//
// Created by thomas on 13.06.20.
//

#include "Rental.h"
#include "Movie.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;


class MockMovie : public Movie {
public:
    MOCK_METHOD(string, getTitle, (), (const));
    MOCK_METHOD(double, getPrice, (), (const));
    MOCK_METHOD(int, getFrequentPoint, (), (const));
};



TEST(Rental, RentalInfoShouldBeCorrect) {

    //default: getPrice, getFrequencePoint use RegularCalculator
    MockMovie movieMock;

    EXPECT_CALL(movieMock, getTitle()).WillRepeatedly(testing::Return("Karate Kid"));
    EXPECT_CALL(movieMock, getPrice()).WillRepeatedly(testing::Return(9.5));
    EXPECT_CALL(movieMock, getFrequentPoint()).WillRepeatedly(testing::Return(1));

    Rental rental = Rental(&movieMock, 7);

    EXPECT_EQ(rental.getMovieTitle(), "Karate Kid");
    EXPECT_EQ(rental.getMoviePrice(), 9.5);
    EXPECT_EQ(rental.getMovieFrequentPoint(), 1);

}