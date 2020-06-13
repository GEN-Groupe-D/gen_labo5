//
// Created by thomas on 13.06.20.
//
#include "ChildrensCalculator.h"
#include "gtest/gtest.h"

TEST(ChildrensCalculator, AmountIsCorrect) {

    ChildrensCalculator childrensCalculator = ChildrensCalculator();

    EXPECT_EQ(childrensCalculator.getAmount(2), 1.5);

    childrensCalculator = ChildrensCalculator();

    EXPECT_EQ(childrensCalculator.getAmount(5), 4.5);

}

TEST(ChildrensCalculator, FrequentPointIsCorrect) {


    ChildrensCalculator childrensCalculator = ChildrensCalculator();

    ASSERT_EQ(childrensCalculator.getFrequentRenterPoints(5), 1);
}