//
// Created by grigorijivanenko on 01.12.22.
//

#include "gtest/gtest.h"
#include "../code/TCargoShip.h"

TEST(TCargoShip, InitConstructorAndAssign) {
    TCapitanInfo emptyInfo;
    TCargoShip emptyShip(1, "", emptyInfo, 2, 3, 4, 5, 6, 7, 8, 9.0);
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

    TCargoShip otherShip(emptyShip);
    ASSERT_EQ(emptyShip, otherShip);

    TCapitanInfo notEmptyInfo("a", "b", "c", "d");
    TCargoShip notEmptyShip(11, "name", notEmptyInfo, 22, 33, 44, 55, 66, 77, 88, 99.0);
    otherShip = notEmptyShip;
    ASSERT_EQ(notEmptyShip, otherShip);
}

TEST(TCargoShip, Setters) {
    TCapitanInfo emptyInfo;
    TCargoShip notEmptyShip(11, "name", emptyInfo, 22, 33, 44, 55, 66, 77, 88, 9.0);

    ASSERT_EQ(notEmptyShip.GetShipType(), 11);
    notEmptyShip.SetShipType(100);
    ASSERT_EQ(notEmptyShip.GetShipType(), 100);

    ASSERT_EQ(notEmptyShip.GetShipName(), "name");
    notEmptyShip.SetShipName("");
    ASSERT_EQ(notEmptyShip.GetShipName(), "");

    ASSERT_EQ(notEmptyShip.GetCapitanInfo(), emptyInfo);
    TCapitanInfo notEmptyInfo("a", "b", "c", "d");
    notEmptyShip.SetCapitanInfo(notEmptyInfo);
    ASSERT_EQ(notEmptyShip.GetCapitanInfo(), notEmptyInfo);

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

    ASSERT_EQ(notEmptyShip.GetWeightTotal(), 77);
    notEmptyShip.SetWeightTotal(100);
    ASSERT_EQ(notEmptyShip.GetWeightTotal(), 100);

    ASSERT_EQ(notEmptyShip.GetWeightNow(), 88);
    notEmptyShip.SetWeightNow(100);
    ASSERT_EQ(notEmptyShip.GetWeightNow(), 100);

    ASSERT_EQ(notEmptyShip.GetSlowK(), 9.0);
    notEmptyShip.SetSlowK(10.0);
    ASSERT_EQ(notEmptyShip.GetSlowK(), 10.0);
}

TEST(TCargoShip, SpeedByWeight) {
    TCapitanInfo emptyInfo;
    TCargoShip notEmptyShip(0, "", emptyInfo, 100, 0, 100, 100, 100, 20, 0, 0.5);
    ASSERT_EQ(notEmptyShip.SpeedByWeight(21), -1);
    ASSERT_EQ(notEmptyShip.SpeedByWeight(20), 50);
    ASSERT_EQ(notEmptyShip.SpeedByWeight(10), 75);
    ASSERT_EQ(notEmptyShip.SpeedByWeight(0), 100);
}

TEST(TCargoShip, WeightMaxBySpeed) {
    TCapitanInfo emptyInfo;
    TCargoShip notEmptyShip(0, "", emptyInfo, 100, 0, 100, 100, 100, 20, 0, 0.5);
    ASSERT_EQ(notEmptyShip.WeightMaxBySpeed(101), -1);
    ASSERT_EQ(notEmptyShip.WeightMaxBySpeed(100), 0);
    ASSERT_EQ(notEmptyShip.WeightMaxBySpeed(75), 10);
    ASSERT_EQ(notEmptyShip.WeightMaxBySpeed(50), 20);
    ASSERT_EQ(notEmptyShip.WeightMaxBySpeed(49), 20);
}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

