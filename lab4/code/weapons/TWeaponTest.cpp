#include "gtest/gtest.h"
#include "TWeapon.h"

TEST(TWeapon, InitConstructorAndAssign) {
    TWeapon weapon(1, 2, 3, 4, 5, 6, 7);
    ASSERT_EQ(weapon.GetWeaponType(), 1);
    ASSERT_EQ(weapon.GetDamage(), 2);
    ASSERT_EQ(weapon.GetCallDown(), 3);
    ASSERT_EQ(weapon.GetRange(), 4);
    ASSERT_EQ(weapon.GetShotsTotal(), 5);
    ASSERT_EQ(weapon.GetShotsNow(), 6);
    ASSERT_EQ(weapon.GetCost(), 7);

    TWeapon weapon1(weapon);
    ASSERT_EQ(weapon1.GetWeaponType(), 1);
    ASSERT_EQ(weapon1.GetDamage(), 2);
    ASSERT_EQ(weapon1.GetCallDown(), 3);
    ASSERT_EQ(weapon1.GetRange(), 4);
    ASSERT_EQ(weapon1.GetShotsTotal(), 5);
    ASSERT_EQ(weapon1.GetShotsNow(), 6);
    ASSERT_EQ(weapon1.GetCost(), 7);

    TWeapon weapon2(11, 12, 13, 14, 15, 16, 17);
    weapon = weapon2;
    ASSERT_EQ(weapon.GetWeaponType(), 11);
    ASSERT_EQ(weapon.GetDamage(), 12);
    ASSERT_EQ(weapon.GetCallDown(), 13);
    ASSERT_EQ(weapon.GetRange(), 14);
    ASSERT_EQ(weapon.GetShotsTotal(), 15);
    ASSERT_EQ(weapon.GetShotsNow(), 16);
    ASSERT_EQ(weapon.GetCost(), 17);
    
    ASSERT_EQ(weapon2.GetWeaponType(), 11);
    ASSERT_EQ(weapon2.GetDamage(), 12);
    ASSERT_EQ(weapon2.GetCallDown(), 13);
    ASSERT_EQ(weapon2.GetRange(), 14);
    ASSERT_EQ(weapon2.GetShotsTotal(), 15);
    ASSERT_EQ(weapon2.GetShotsNow(), 16);
    ASSERT_EQ(weapon2.GetCost(), 17);
}

TEST(TWeapon, Setters) {
    TWeapon weapon(1, 2, 3, 4, 5, 6, 7);

    ASSERT_EQ(weapon.GetWeaponType(), 1);
    weapon.SetWeaponType(100);
    ASSERT_EQ(weapon.GetWeaponType(), 100);

    ASSERT_EQ(weapon.GetDamage(), 2);
    weapon.SetDamage(100);
    ASSERT_EQ(weapon.GetDamage(), 100);

    ASSERT_EQ(weapon.GetCallDown(), 3);
    weapon.SetCallDown(100);
    ASSERT_EQ(weapon.GetCallDown(), 100);

    ASSERT_EQ(weapon.GetRange(), 4);
    weapon.SetRange(100);
    ASSERT_EQ(weapon.GetRange(), 100);

    ASSERT_EQ(weapon.GetShotsTotal(), 5);
    weapon.SetShotsTotal(100);
    ASSERT_EQ(weapon.GetShotsTotal(), 100);

    ASSERT_EQ(weapon.GetShotsNow(), 6);
    weapon.SetShotsNow(100);
    ASSERT_EQ(weapon.GetShotsNow(), 100);

    ASSERT_EQ(weapon.GetCost(), 7);
    weapon.SetCost(100);
    ASSERT_EQ(weapon.GetCost(), 100);
}

TEST(TWeapon, MakeShot) {
    TWeapon weaponNotEmpty(0, 30, 0, 0, 10, 4, 0);
    ASSERT_EQ(weaponNotEmpty.MakeShot(), 30);
    ASSERT_EQ(weaponNotEmpty.GetShotsNow(), 3);

    TWeapon weaponEmpty(0, 40, 0, 0, 10, 0, 0);
    ASSERT_EQ(weaponEmpty.MakeShot(), 0);
    ASSERT_EQ(weaponEmpty.GetShotsNow(), 0);
}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

