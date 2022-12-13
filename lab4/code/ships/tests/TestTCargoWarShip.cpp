//
// Created by grigorijivanenko on 06.12.22.
//

#include "gtest/gtest.h"
#include "../code/TCargoWarShip.h"

TWeaponHolder makeWeaponHolder(int type) {
    TWeapon a(0, 100, 0, 20, 0, 3, 0);
    TWeapon b(0, 1000, 0, 10, 0, 1, 0);
    if (type == 1)
        return TWeaponHolder(nullptr, &a, &a, &b);
    else if (type == 2)
        return TWeaponHolder(nullptr, &a, &b, &b);
    else
        return TWeaponHolder(nullptr, nullptr, nullptr, nullptr);
}

TEST(TCargoWarShip, InitConstructorAndAssign) {
    TCapitanInfo emptyInfo;
    TCargoWarShip emptyShip(1, "", emptyInfo, 2, 3, 4, 5, 6, 7, 8, 9.0, makeWeaponHolder(1));
    ASSERT_EQ(emptyShip.GetShipType(), 1);
    ASSERT_EQ(emptyShip.GetShipName(), "");
    ASSERT_EQ(emptyShip.GetCapitanInfo(), emptyInfo);
    ASSERT_EQ(emptyShip.GetMaxSpeed(), 2);
    ASSERT_EQ(emptyShip.GetNowSpeed(), 3);
    ASSERT_EQ(emptyShip.GetHPTotal(), 4);
    ASSERT_EQ(emptyShip.GetHPNow(), 5);
    ASSERT_EQ(emptyShip.GetCost(), 6);
    ASSERT_EQ(emptyShip.GetWeightTotal(), 7);
    ASSERT_EQ(emptyShip.GetWeightNow(), 8);
    ASSERT_EQ(emptyShip.GetSlowK(), 9.0);
    ASSERT_EQ(emptyShip.GetHolder(), makeWeaponHolder(1));

    TCargoWarShip otherShip(emptyShip);
    ASSERT_EQ(emptyShip, otherShip);

    TCapitanInfo notEmptyInfo("a", "b", "c", "d");
    TCargoWarShip notEmptyShip(11, "name", notEmptyInfo, 22, 33, 44, 55, 66, 77, 88, 99.0, makeWeaponHolder(2) );
    otherShip = notEmptyShip;
    ASSERT_EQ(notEmptyShip, otherShip);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
