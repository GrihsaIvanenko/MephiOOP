//
// Created by grigorijivanenko on 16.12.22.
//

#include "gtest/gtest.h"
#include "../code/TObjectOnMap.h"

TEST(TShip, InitConstructorAndAssign) {
    TObjectOnMap obj(0, 0);

    TObjectOnMap otherObj(obj);
    ASSERT_EQ(obj, otherObj);

    TObjectOnMap thirdObj(1, 1);
    otherObj = thirdObj;
    ASSERT_EQ(otherObj, thirdObj);
}

TEST(TShip, Setters) {
    TObjectOnMap obj(0, 0);

    ASSERT_EQ(obj.GetX(), 0);
    obj.SetX(1);
    ASSERT_EQ(obj.GetX(), 1);

    ASSERT_EQ(obj.GetY(), 0);
    obj.SetY(1);
    ASSERT_EQ(obj.GetY(), 1);
}

TEST(TShip, DistTo) {
    TObjectOnMap obj1(-5, -5);
    TObjectOnMap obj2(5, 5);
    ASSERT_EQ(obj1.DistTo(obj2), 200);
}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

