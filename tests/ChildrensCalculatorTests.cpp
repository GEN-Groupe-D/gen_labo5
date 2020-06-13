//
// Created by thomas on 13.06.20.
//
#include "ChildrensCalculator.h"
#include "gtest/gtest.h"

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