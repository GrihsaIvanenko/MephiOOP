//
// Created by grigorijivanenko on 29.11.22.
//

#include "gtest/gtest.h"
#include "TWeaponHolder.h"
#include <vector>

TEST(TWeaponHolder, InitConstructor) {
    TWeaponHolder holder;
    ASSERT_EQ(holder.GetGunByPlace(ShipFront), nullptr);
    ASSERT_EQ(holder.GetGunByPlace(ShipBack), nullptr);
    ASSERT_EQ(holder.GetGunByPlace(ShipLeftSide), nullptr);
    ASSERT_EQ(holder.GetGunByPlace(ShipRightSide), nullptr);
}

bool isTWeaponSame(TWeapon* lhs, TWeapon* rhs) {
    if (!lhs && !rhs)
        return true;
    if (!lhs || !rhs)
        return false;
    return
        lhs->GetWeaponType() == rhs->GetWeaponType() &&
        lhs->GetDamage() == rhs->GetDamage() &&
        lhs->GetCallDown() == rhs->GetCallDown() &&
        lhs->GetRange() == rhs->GetRange() &&
        lhs->GetShotsTotal() == rhs->GetShotsTotal() &&
        lhs->GetShotsNow() == rhs->GetShotsNow() &&
        lhs->GetCost() == rhs->GetCost();
}

bool isTWeaponHolderSame(TWeaponHolder& holder, const std::vector<TWeapon*>& data) {
    assert(data.size() == 4);
    return
        isTWeaponSame(holder.GetGunByPlace(ShipFront), data[0]) &&
    isTWeaponSame(holder.GetGunByPlace(ShipBack), data[1]) &&
    isTWeaponSame(holder.GetGunByPlace(ShipLeftSide), data[2]) &&
    isTWeaponSame(holder.GetGunByPlace(ShipRightSide), data[3]);
}

TEST(TWeaponHolder, Constructor) {
    TWeapon a(1, 2, 3, 4, 5, 6, 7);
    TWeapon b(11, 12, 13, 14, 15, 16, 17);

    TWeaponHolder holder1(nullptr, nullptr, nullptr, nullptr);
    ASSERT_EQ(isTWeaponHolderSame(holder1, {nullptr, nullptr, nullptr, nullptr}), true);

    TWeaponHolder holder2(nullptr, &a, &b, nullptr);
    ASSERT_EQ(isTWeaponHolderSame(holder2, {nullptr, &a, &b, nullptr}), true);

    TWeaponHolder holder3(&b, &b, &b, &b);
    ASSERT_EQ(isTWeaponHolderSame(holder3, {&b, &b, &b, &b}), true);

    TWeapon* Gun1 = holder3.GetGunByPlace(ShipBack);
    TWeapon* Gun2 = holder3.GetGunByPlace(ShipLeftSide);
    Gun1->MakeShot();
    ASSERT_EQ(Gun1->GetShotsNow() + 1, b.GetShotsNow());
    ASSERT_EQ(Gun2->GetShotsNow(), b.GetShotsNow());
}

TEST(TWeaponHolder, SetByPlace) {
    TWeapon a(1, 2, 3, 4, 5, 6, 7);
    TWeapon b(11, 12, 13, 14, 15, 16, 17);
    TWeapon c(21, 22, 23, 24, 25, 26, 27);
    TWeapon d(31, 32, 33, 34, 35, 36, 37);

    TWeaponHolder holder(&a, &b, &c, &d);
    holder.SetGunByPlace(ShipFront, &c);
    ASSERT_EQ(isTWeaponSame(holder.GetGunByPlace(ShipFront), holder.GetGunByPlace(ShipLeftSide)), true);
    holder.GetGunByPlace(ShipFront)->MakeShot();
    ASSERT_EQ(holder.GetGunByPlace(ShipFront)->GetShotsNow() + 1, c.GetShotsNow());
    ASSERT_EQ(holder.GetGunByPlace(ShipFront)->GetShotsNow() + 1, holder.GetGunByPlace(ShipLeftSide)->GetShotsNow());
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}