//
// Created by thomas on 13.06.20.
//
#include "RegularCalculator.h"
#include "gtest/gtest.h"

TEST(RegularCalculator, AmountIsCorrect) {

    RegularCalculator regularCalculator = RegularCalculator();

    EXPECT_EQ(regularCalculator.getAmount(1), 2);

    regularCalculator = RegularCalculator();

    EXPECT_EQ(regularCalculator.getAmount(5), 6.5);

}

TEST(RegularCalculator, FrequentPointIsCorrect) {


    RegularCalculator regularCalculator = RegularCalculator();

    ASSERT_EQ(regularCalculator.getFrequentRenterPoints(5), 1);
}