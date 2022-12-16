//
// Created by grigorijivanenko on 29.11.22.
//

#include "gtest/gtest.h"
#include "../code/TWeaponHolder.h"


bool operator == (const TWeaponHolder& lhs, const std::vector<TWeapon*>& rhs) {
    return
        TWeaponHolder::SameGuns(lhs.GetGunByPlace(ShipFront), rhs[0]) &&
        TWeaponHolder::SameGuns(lhs.GetGunByPlace(ShipBack), rhs[1]) &&
        TWeaponHolder::SameGuns(lhs.GetGunByPlace(ShipLeftSide), rhs[2]) &&
        TWeaponHolder::SameGuns(lhs.GetGunByPlace(ShipRightSide), rhs[3]);
}

TEST(TWeaponHolder, InitConstructorAndAssign) {
    TWeaponHolder holder;
    ASSERT_EQ(holder.GetGunByPlace(ShipFront), nullptr);
    ASSERT_EQ(holder.GetGunByPlace(ShipBack), nullptr);
    ASSERT_EQ(holder.GetGunByPlace(ShipLeftSide), nullptr);
    ASSERT_EQ(holder.GetGunByPlace(ShipRightSide), nullptr);

    TWeaponHolder holder1(nullptr, nullptr, nullptr, nullptr);
    ASSERT_EQ(holder, holder1);

    TWeapon a(1, 2, 3, 4, 5, 6, 7, 8);
    TWeapon b(11, 12, 13, 14, 15, 16, 17, 18);
    TWeaponHolder holder2(nullptr, &a, &b, nullptr);
    std::vector<TWeapon*> tmp = {nullptr, &a, &b, nullptr};
    ASSERT_EQ(holder2, tmp);

    TWeaponHolder holder3(&b, &b, &b, &b);
    tmp = {&b, &b, &b, &b};
    ASSERT_EQ(holder3, tmp);

    TWeaponHolder holder4(holder3);
    ASSERT_EQ(holder4, holder3);

    holder2 = holder4;
    ASSERT_EQ(holder2, holder4);

    //make shot to check copy-creating
    TWeapon* Gun1 = holder3.GetGunByPlace(ShipBack);
    TWeapon* Gun2 = holder3.GetGunByPlace(ShipLeftSide);
    Gun1->MakeShot(0, 300);
    ASSERT_EQ(Gun1->GetShotsNow() + 1, b.GetShotsNow());
    ASSERT_EQ(Gun2->GetShotsNow(), b.GetShotsNow());
}

TEST(TWeaponHolder, SetByPlace) {
    TWeapon a(1, 2, 3, 4, 5, 6, 7, 8);
    TWeapon b(11, 12, 13, 14, 15, 16, 17, 18);
    TWeapon c(21, 22, 23, 24, 25, 26, 27, 28);
    TWeapon d(31, 32, 33, 34, 35, 36, 37, 38);

    TWeaponHolder holder(&a, &b, &c, &d);
    holder.SetGunByPlace(ShipFront, &c);
    ASSERT_EQ(
            TWeaponHolder::SameGuns(
                    holder.GetGunByPlace(ShipFront),
                    holder.GetGunByPlace(ShipLeftSide)),
            true);
    holder.GetGunByPlace(ShipFront)->MakeShot(0, 300);
    ASSERT_EQ(holder.GetGunByPlace(ShipFront)->GetShotsNow() + 1, c.GetShotsNow());
    ASSERT_EQ(holder.GetGunByPlace(ShipFront)->GetShotsNow() + 1, holder.GetGunByPlace(ShipLeftSide)->GetShotsNow());
}

TEST(TWeaponHolder, MakeShot) {
    TWeapon a(0, 100, 4, 0, 20, 0, 4, 0);
    TWeapon b(0, 1000, 10, 0, 10, 0, 1, 0);
    TWeaponHolder holder(nullptr, &b, &a, &b);
    ASSERT_EQ(holder.MakeShot(20 * 20, 4), 100);
    ASSERT_EQ(holder.GetGunByPlace(ShipBack)->GetShotsNow(), 1);
    ASSERT_EQ(holder.GetGunByPlace(ShipLeftSide)->GetShotsNow(), 3);
    ASSERT_EQ(holder.GetGunByPlace(ShipRightSide)->GetShotsNow(), 1);

    ASSERT_EQ(holder.MakeShot(10 * 10, 8), 100);
    ASSERT_EQ(holder.GetGunByPlace(ShipBack)->GetShotsNow(), 1);
    ASSERT_EQ(holder.GetGunByPlace(ShipLeftSide)->GetShotsNow(), 2);
    ASSERT_EQ(holder.GetGunByPlace(ShipRightSide)->GetShotsNow(), 1);

    ASSERT_EQ(holder.MakeShot(10 * 10, 200), 1000 + 1000 + 100);
    ASSERT_EQ(holder.GetGunByPlace(ShipBack)->GetShotsNow(), 0);
    ASSERT_EQ(holder.GetGunByPlace(ShipLeftSide)->GetShotsNow(), 1);
    ASSERT_EQ(holder.GetGunByPlace(ShipRightSide)->GetShotsNow(), 0);

    ASSERT_EQ(holder.MakeShot(10 * 10, 201), 0);
    ASSERT_EQ(holder.GetGunByPlace(ShipBack)->GetShotsNow(), 0);
    ASSERT_EQ(holder.GetGunByPlace(ShipLeftSide)->GetShotsNow(), 1);
    ASSERT_EQ(holder.GetGunByPlace(ShipRightSide)->GetShotsNow(), 0);

    ASSERT_EQ(holder.MakeShot(10 * 10, 204), 100);
    ASSERT_EQ(holder.GetGunByPlace(ShipBack)->GetShotsNow(), 0);
    ASSERT_EQ(holder.GetGunByPlace(ShipLeftSide)->GetShotsNow(), 0);
    ASSERT_EQ(holder.GetGunByPlace(ShipRightSide)->GetShotsNow(), 0);

    ASSERT_EQ(holder.MakeShot(0, 500), 0);
    ASSERT_EQ(holder.GetGunByPlace(ShipLeftSide)->GetShotsNow(), 0);

    holder = TWeaponHolder(&a, &a, &a, &a);
    ASSERT_EQ(holder.MakeShot(20 * 20, 100), 100 * 4);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}