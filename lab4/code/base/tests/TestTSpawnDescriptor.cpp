//
// Created by grigorijivanenko on 16.12.22.
//

#include "gtest/gtest.h"
#include "../code/TSpawnDescriptor.h"

TWeaponHolder makeWeaponHolder(int type) {
    TWeapon a(0, 100, 1, 0, 20, 0, 3, 0);
    TWeapon b(0, 1000, 1, 0, 10, 0, 1, 0);
    if (type == 1)
        return TWeaponHolder(nullptr, &a, &a, &b);
    else if (type == 2)
        return TWeaponHolder(nullptr, &a, &b, &b);
    else
        return TWeaponHolder(nullptr, nullptr, nullptr, nullptr);
}

TEST(TShip, InitConstructorAndAssign) {
    TCapitanInfo emptyInfo;
    TWarShip notEmptyShip(0, 0, 11, "name", emptyInfo, 22, 33, 44, 55, 66, makeWeaponHolder(2));

    TSpawnDescriptor obj(notEmptyShip, 10, 10, 0);

    TSpawnDescriptor otherObj(obj);
    ASSERT_EQ(obj, otherObj);

    TSpawnDescriptor thirdObj(notEmptyShip, 1, 1, 1);
    otherObj = thirdObj;
    ASSERT_EQ(otherObj, thirdObj);
}

TEST(TShip, Spawn) {
    TCapitanInfo emptyInfo;
    TWarShip notEmptyShip(0, 0, 11, "name", emptyInfo, 22, 33, 44, 55, 66, makeWeaponHolder(2));
    TSpawnDescriptor obj(notEmptyShip, 10, 10, 0);

    MyList<TWarShip> l1 = obj.Spawn(1);
    ASSERT_EQ(l1.size(), 0);

    l1 = obj.Spawn(65);
    ASSERT_EQ(l1.size(), 6);
    for (const auto& ship : l1)
        ASSERT_EQ(ship, notEmptyShip);


    l1 = obj.Spawn(100);
    ASSERT_EQ(l1.size(), 4);
    for (const auto& ship : l1)
        ASSERT_EQ(ship, notEmptyShip);

    l1 = obj.Spawn(300);
    ASSERT_EQ(l1.size(), 0);
    for (const auto& ship : l1)
        ASSERT_EQ(ship, notEmptyShip);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

