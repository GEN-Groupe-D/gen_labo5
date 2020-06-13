//
// Created by thomas on 13.06.20.
//
#include "RegularCalculator.h"
#include "gtest/gtest.h"

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