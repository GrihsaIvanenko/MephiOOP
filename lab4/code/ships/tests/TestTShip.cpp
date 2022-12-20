//
// Created by grigorijivanenko on 29.11.22.
//

#include "gtest/gtest.h"
#include "../code/TShip.h"

TEST(TShip, InitConstructorAndAssign) {
    TCapitanInfo emptyInfo;
    TShip emptyShip(0, 0, 1, "", emptyInfo, 2, 3, 4, 5, 6);
    ASSERT_EQ(emptyShip.GetShipType(), 1);
    ASSERT_EQ(emptyShip.GetShipName(), "");
    ASSERT_EQ(emptyShip.GetCapitanInfo(), emptyInfo);
    ASSERT_EQ(emptyShip.GetMaxSpeed(), 2);
    ASSERT_EQ(emptyShip.GetNowSpeed(), 3);
    ASSERT_EQ(emptyShip.GetHPTotal(), 4);
    ASSERT_EQ(emptyShip.GetHPNow(), 5);
    ASSERT_EQ(emptyShip.GetCost(), 6);

    TShip otherShip(emptyShip);
    ASSERT_EQ(otherShip, emptyShip);

    TCapitanInfo notEmptyInfo("a", "b", "c", "d");
    TShip notEmptyShip(0, 0, 11, "name", notEmptyInfo, 22, 33, 44, 55, 66);
    otherShip = notEmptyShip;
    ASSERT_EQ(otherShip, notEmptyShip);

    auto it = emptyShip.Clone();
    ASSERT_EQ(*(it.get()), emptyShip);
}

TEST(TShip, Setters) {
    TCapitanInfo notEmptyInfo("a", "b", "c", "d");
    TShip notEmptyShip(0, 0, 11, "name", notEmptyInfo, 22, 33, 44, 55, 66);
    TCapitanInfo emptyInfo;

    ASSERT_EQ(notEmptyShip.GetShipType(), 11);
    notEmptyShip.SetShipType(100);
    ASSERT_EQ(notEmptyShip.GetShipType(), 100);

    ASSERT_EQ(notEmptyShip.GetShipName(), "name");
    notEmptyShip.SetShipName("");
    ASSERT_EQ(notEmptyShip.GetShipName(), "");

    ASSERT_EQ(notEmptyShip.GetCapitanInfo(), notEmptyInfo);
    notEmptyShip.SetCapitanInfo(emptyInfo);
    ASSERT_EQ(notEmptyShip.GetCapitanInfo(), emptyInfo);

    ASSERT_EQ(notEmptyShip.GetMaxSpeed(), 22);
    notEmptyShip.SetMaxSpeed(100);
    ASSERT_EQ(notEmptyShip.GetMaxSpeed(), 100);

    ASSERT_EQ(notEmptyShip.GetNowSpeed(), 33);
    notEmptyShip.SetNowSpeed(100);
    ASSERT_EQ(notEmptyShip.GetNowSpeed(), 100);

    ASSERT_EQ(notEmptyShip.GetHPTotal(), 44);
    notEmptyShip.SetHPTotal(100);
    ASSERT_EQ(notEmptyShip.GetHPTotal(), 100);

    ASSERT_EQ(notEmptyShip.GetHPNow(), 55);
    notEmptyShip.SetHPNow(100);
    ASSERT_EQ(notEmptyShip.GetHPNow(), 100);

    ASSERT_EQ(notEmptyShip.GetCost(), 66);
    notEmptyShip.SetCost(100);
    ASSERT_EQ(notEmptyShip.GetCost(), 100);
}

TEST(TShip, MakeDamage) {
    TCapitanInfo notEmptyInfo("a", "b", "c", "d");
    TShip notEmptyShip(0, 0, 11, "name", notEmptyInfo, 22, 33, 44, 55, 66);

    notEmptyShip.BeDamaged(10);
    ASSERT_EQ(notEmptyShip.GetHPNow(), 45);

    notEmptyShip.BeDamaged(100);
    ASSERT_EQ(notEmptyShip.GetHPNow(), 0);
}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

