//
// Created by grigorijivanenko on 16.12.22.
//

#include "gtest/gtest.h"
#include "../code/TBase.h"

TEST(TShip, InitConstructorAndAssign) {
    TBase obj(0, 0, BASE_A);

    TBase otherObj(obj);
    ASSERT_EQ(obj, otherObj);

    TBase thirdObj(0, 0, BASE_B);
    otherObj = thirdObj;
    ASSERT_EQ(otherObj, thirdObj);
}

TEST(TShip, Setters) {
    TBase obj(0, 0, BASE_B);

    ASSERT_EQ(obj.GetBaseType(), BASE_B);
    obj.SetBaseType(BASE_P);
    ASSERT_EQ(obj.GetBaseType(), BASE_P);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

