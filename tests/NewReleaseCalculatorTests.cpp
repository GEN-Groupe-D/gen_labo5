//
// Created by thomas on 13.06.20.
//
#include "gtest/gtest.h"
#include "NewReleaseCalculator.h"

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