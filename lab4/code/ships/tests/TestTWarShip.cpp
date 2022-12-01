//
// Created by grigorijivanenko on 02.12.22.
//

#include "gtest/gtest.h"
#include "../code/TWarShip.h"

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

TEST(TWarShip, InitConstructorAndAssign) {
    TCapitanInfo emptyInfo;
    TWarShip emptyShip(1, "", emptyInfo, 2, 3, 4, 5, 6, makeWeaponHolder(1));
    ASSERT_EQ(emptyShip.GetShipType(), 1);
    ASSERT_EQ(emptyShip.GetShipName(), "");
    ASSERT_EQ(emptyShip.GetCapitanInfo(), emptyInfo);
    ASSERT_EQ(emptyShip.GetMaxSpeed(), 2);
    ASSERT_EQ(emptyShip.GetNowSpeed(), 3);
    ASSERT_EQ(emptyShip.GetHPTotal(), 4);
    ASSERT_EQ(emptyShip.GetHPNow(), 5);
    ASSERT_EQ(emptyShip.GetCost(), 6);
    ASSERT_EQ(emptyShip.GetHolder(), makeWeaponHolder(1));

    TWarShip otherShip(emptyShip);
    ASSERT_EQ(emptyShip, otherShip);

    TCapitanInfo notEmptyInfo("a", "b", "c", "d");
    TWarShip notEmptyShip(11, "name", notEmptyInfo, 22, 33, 44, 55, 66, makeWeaponHolder(2) );
    otherShip = notEmptyShip;
    ASSERT_EQ(notEmptyShip, otherShip);
}

TEST(TWarShip, Setters) {
    TCapitanInfo emptyInfo;
    TWarShip notEmptyShip(11, "name", emptyInfo, 22, 33, 44, 55, 66, makeWeaponHolder(2));

    ASSERT_EQ(notEmptyShip.GetHolder(), makeWeaponHolder(2));
    notEmptyShip.SetHolder(makeWeaponHolder(1));
    ASSERT_EQ(notEmptyShip.GetHolder(), makeWeaponHolder(1));
}

TEST(TWarShip, MakeShot) {
    TCapitanInfo emptyInfo;
    TWarShip notEmptyShip(11, "name", emptyInfo, 22, 33, 44, 55, 66, makeWeaponHolder(2));
    ASSERT_EQ(notEmptyShip.MakeShot(20 * 20), 100);
    ASSERT_EQ(notEmptyShip.MakeShot(20 * 20), 100);
    ASSERT_EQ(notEmptyShip.MakeShot(20 * 20), 100);
    ASSERT_EQ(notEmptyShip.MakeShot(20 * 20), 0);
    ASSERT_EQ(notEmptyShip.MakeShot(10 * 10), 1000 + 1000);
    ASSERT_EQ(notEmptyShip.MakeShot(10 * 10), 0);

    TWarShip emptyShip(11, "name", emptyInfo, 22, 33, 44, 55, 66, makeWeaponHolder(0));
    ASSERT_EQ(emptyShip.MakeShot(0), 0);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

