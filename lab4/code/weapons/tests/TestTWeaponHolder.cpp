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

    TWeapon a(1, 2, 3, 4, 5, 6, 7);
    TWeapon b(11, 12, 13, 14, 15, 16, 17);
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
    ASSERT_EQ(
            TWeaponHolder::SameGuns(
                    holder.GetGunByPlace(ShipFront),
                    holder.GetGunByPlace(ShipLeftSide)),
            true);
    holder.GetGunByPlace(ShipFront)->MakeShot();
    ASSERT_EQ(holder.GetGunByPlace(ShipFront)->GetShotsNow() + 1, c.GetShotsNow());
    ASSERT_EQ(holder.GetGunByPlace(ShipFront)->GetShotsNow() + 1, holder.GetGunByPlace(ShipLeftSide)->GetShotsNow());
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}