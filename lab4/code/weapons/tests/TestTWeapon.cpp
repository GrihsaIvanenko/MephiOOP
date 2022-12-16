#include "gtest/gtest.h"

#include "../code/TWeapon.h"

TEST(TWeapon, InitConstructorAndAssign) {
    TWeapon weapon(1, 2, 3, 4, 5, 6, 7, 8);
    ASSERT_EQ(weapon.GetWeaponType(), 1);
    ASSERT_EQ(weapon.GetDamage(), 2);
    ASSERT_EQ(weapon.GetCallDown(), 3);
    ASSERT_EQ(weapon.GetLastShot(), 4);
    ASSERT_EQ(weapon.GetRange(), 5);
    ASSERT_EQ(weapon.GetShotsTotal(), 6);
    ASSERT_EQ(weapon.GetShotsNow(), 7);
    ASSERT_EQ(weapon.GetCost(), 8);

    TWeapon weapon1(weapon);
    ASSERT_EQ(weapon1, weapon);

    TWeapon weapon2(11, 12, 13, 14, 15, 16, 17, 18);
    weapon = weapon2;
    ASSERT_EQ(weapon, weapon2);
}

TEST(TWeapon, Setters) {
    TWeapon weapon(1, 2, 3, 4, 5, 6, 7, 8);

    ASSERT_EQ(weapon.GetWeaponType(), 1);
    weapon.SetWeaponType(100);
    ASSERT_EQ(weapon.GetWeaponType(), 100);

    ASSERT_EQ(weapon.GetDamage(), 2);
    weapon.SetDamage(100);
    ASSERT_EQ(weapon.GetDamage(), 100);

    ASSERT_EQ(weapon.GetCallDown(), 3);
    weapon.SetCallDown(100);
    ASSERT_EQ(weapon.GetCallDown(), 100);

    ASSERT_EQ(weapon.GetLastShot(), 4);
    weapon.SetLastShot(100);
    ASSERT_EQ(weapon.GetLastShot(), 100);

    ASSERT_EQ(weapon.GetRange(), 5);
    weapon.SetRange(100);
    ASSERT_EQ(weapon.GetRange(), 100);

    ASSERT_EQ(weapon.GetShotsTotal(), 6);
    weapon.SetShotsTotal(100);
    ASSERT_EQ(weapon.GetShotsTotal(), 100);

    ASSERT_EQ(weapon.GetShotsNow(), 7);
    weapon.SetShotsNow(100);
    ASSERT_EQ(weapon.GetShotsNow(), 100);

    ASSERT_EQ(weapon.GetCost(), 8);
    weapon.SetCost(100);
    ASSERT_EQ(weapon.GetCost(), 100);
}

TEST(TWeapon, MakeShot) {
    TWeapon weaponNotEmpty(0, 30, 5, 0, 3, 10, 4, 0);

    ASSERT_EQ(weaponNotEmpty.MakeShot(8, 10), 30);
    ASSERT_EQ(weaponNotEmpty.GetShotsNow(), 3);

    ASSERT_EQ(weaponNotEmpty.MakeShot(9, 20), 30);
    ASSERT_EQ(weaponNotEmpty.GetShotsNow(), 2);

    ASSERT_EQ(weaponNotEmpty.MakeShot(9, 21), 0);
    ASSERT_EQ(weaponNotEmpty.GetShotsNow(), 2);

    ASSERT_EQ(weaponNotEmpty.MakeShot(10, 100), 0);
    ASSERT_EQ(weaponNotEmpty.GetShotsNow(), 2);

    TWeapon weaponEmpty(0, 40, 0, 10, 0, 10, 0, 0);
    ASSERT_EQ(weaponEmpty.MakeShot(10, 100), 0);
    ASSERT_EQ(weaponEmpty.GetShotsNow(), 0);
}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

