//
// Created by thomas on 13.06.20.
//

#include <PriceCalculator.h>
#include <Movie.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class MockPriceCalculator : public PriceCalculator {
public:
    MOCK_METHOD(double, getAmount, (int nbDays));
    MOCK_METHOD(int, getFrequentRenterPoints, (int nbDays));
};

TEST(Movie, MovieInfosShouldBeCorrect) {

    MockPriceCalculator priceMock;

    EXPECT_CALL(priceMock, getAmount(3)).WillRepeatedly(testing::Return(1.5));
    EXPECT_CALL(priceMock, getFrequentRenterPoints(3)).WillRepeatedly(testing::Return(1));

    Movie movie = Movie("Snow white", &priceMock);

    EXPECT_EQ(movie.getPrice(3), 1.5);
    EXPECT_EQ(movie.getFrequentPoint(3), 1);
    EXPECT_EQ(movie.getTitle(), "Snow white");

}