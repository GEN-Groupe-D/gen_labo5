//
// Created by thomas on 13.06.20.
//
#include "gtest/gtest.h"
#include "NewReleaseCalculator.h"

TEST(NewReleaseCalculator, AmountIsCorrect) {

    NewReleaseCalculator newReleaseCalculator = NewReleaseCalculator();

    ASSERT_EQ(newReleaseCalculator.getAmount(5), 15);

}

TEST(NewReleaseCalculator, FrequentPointIsCorrect) {


    NewReleaseCalculator newReleaseCalculator = NewReleaseCalculator();

    EXPECT_EQ(newReleaseCalculator.getFrequentRenterPoints(1), 1);


    newReleaseCalculator = NewReleaseCalculator();

    EXPECT_EQ(newReleaseCalculator.getFrequentRenterPoints(5), 2);
}