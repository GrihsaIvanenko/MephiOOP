//
// Created by grigorijivanenko on 29.11.22.
//

#include "gtest/gtest.h"
#include "TShip.h"

bool CapitanInfoEqual(const TCapitanInfo& lhs, const TCapitanInfo& rhs) {
    return
        lhs.GetName() == rhs.GetName() &&
        lhs.GetSurname() == rhs.GetSurname() &&
        lhs.GetPatronymic() == rhs.GetPatronymic() &&
        lhs.GetRank() == rhs.GetRank();
}

TEST(TShip, InitConstructorAndAssign) {
    TCapitanInfo emptyInfo;
    TShip emptyShip(1, "", emptyInfo, 2, 3, 4, 5, 6);
    ASSERT_EQ(emptyShip.GetShipType(), 1);
    ASSERT_EQ(emptyShip.GetShipName(), "");
    ASSERT_EQ(CapitanInfoEqual(emptyShip.GetCapitanInfo(), emptyInfo), true);
    ASSERT_EQ(emptyShip.GetMaxSpeed(), 2);
    ASSERT_EQ(emptyShip.GetNowSpeed(), 3);
    ASSERT_EQ(emptyShip.GetHPTotal(), 4);
    ASSERT_EQ(emptyShip.GetHPNow(), 5);
    ASSERT_EQ(emptyShip.GetCost(), 6);

    TShip otherShip(emptyShip);
    ASSERT_EQ(otherShip.GetShipType(), 1);
    ASSERT_EQ(otherShip.GetShipName(), "");
    ASSERT_EQ(CapitanInfoEqual(otherShip.GetCapitanInfo(), emptyInfo), true);
    ASSERT_EQ(otherShip.GetMaxSpeed(), 2);
    ASSERT_EQ(otherShip.GetNowSpeed(), 3);
    ASSERT_EQ(otherShip.GetHPTotal(), 4);
    ASSERT_EQ(otherShip.GetHPNow(), 5);
    ASSERT_EQ(otherShip.GetCost(), 6);

    TCapitanInfo notEmptyInfo("a", "b", "c", "d");
    TShip notEmptyShip(11, "name", notEmptyInfo, 22, 33, 44, 55, 66);
    otherShip = notEmptyShip;
    ASSERT_EQ(otherShip.GetShipType(), 11);
    ASSERT_EQ(otherShip.GetShipName(), "name");
    ASSERT_EQ(CapitanInfoEqual(otherShip.GetCapitanInfo(), notEmptyInfo), true);
    ASSERT_EQ(otherShip.GetMaxSpeed(), 22);
    ASSERT_EQ(otherShip.GetNowSpeed(), 33);
    ASSERT_EQ(otherShip.GetHPTotal(), 44);
    ASSERT_EQ(otherShip.GetHPNow(), 55);
    ASSERT_EQ(otherShip.GetCost(), 66);
}

TEST(TWeapon, Setters) {
    TCapitanInfo notEmptyInfo("a", "b", "c", "d");
    TShip notEmptyShip(11, "name", notEmptyInfo, 22, 33, 44, 55, 66);
    TCapitanInfo emptyInfo;

    ASSERT_EQ(notEmptyShip.GetShipType(), 11);
    notEmptyShip.SetShipType(100);
    ASSERT_EQ(notEmptyShip.GetShipType(), 100);

    ASSERT_EQ(notEmptyShip.GetShipName(), "name");
    notEmptyShip.SetShipName("");
    ASSERT_EQ(notEmptyShip.GetShipName(), "");

    ASSERT_EQ(CapitanInfoEqual(notEmptyShip.GetCapitanInfo(), notEmptyInfo), true);
    notEmptyShip.SetCapitanInfo(emptyInfo);
    ASSERT_EQ(CapitanInfoEqual(notEmptyShip.GetCapitanInfo(), emptyInfo), true);

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

TEST(TWeapon, MakeShot) {
    TCapitanInfo notEmptyInfo("a", "b", "c", "d");
    TShip notEmptyShip(11, "name", notEmptyInfo, 22, 33, 44, 55, 66);

    notEmptyShip.MakeDamage(10);
    ASSERT_EQ(notEmptyShip.GetHPNow(), 45);

    notEmptyShip.MakeDamage(100);
    ASSERT_EQ(notEmptyShip.GetHPNow(), 0);
}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

