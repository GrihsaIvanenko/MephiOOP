//
// Created by grigorijivanenko on 16.12.22.
//

#include "gtest/gtest.h"
#include "../code/TPirateBase.h"

TWeaponHolder makeWeaponHolder(int type) {
    TWeapon a(0, 100, 1, 0, 20, 0, 3, 0);
    TWeapon b(0, 1000, 1, 0, 10, 0, 1, 0);
    if (type == 1)
        return TWeaponHolder(nullptr, &a, &a, &b);
    else if (type == 2)
        return TWeaponHolder(nullptr, &a, &b, &b);
    else
        return TWeaponHolder(nullptr, nullptr, nullptr, nullptr);
}

TEST(TShip, InitConstructorAndAssign) {
    TCapitanInfo emptyInfo;
    TWarShip notEmptyShip(0, 0, 11, "name", emptyInfo, 22, 33, 44, 55, 66, makeWeaponHolder(2));
    TSpawnDescriptor spawner1(notEmptyShip, 10, 10, 10);
    TSpawnDescriptor spawner2(notEmptyShip, 11, 11, 11);

    TPirateBase obj(0, 0, BASE_P, spawner1);

    TPirateBase otherObj(obj);
    ASSERT_EQ(obj, otherObj);

    TPirateBase thirdObj(0, 0, BASE_P, spawner2);
    otherObj = thirdObj;
    ASSERT_EQ(otherObj, thirdObj);
}

TEST(TShip, Setters) {
    TCapitanInfo emptyInfo;
    TWarShip notEmptyShip(0, 0, 11, "name", emptyInfo, 22, 33, 44, 55, 66, makeWeaponHolder(2));
    TSpawnDescriptor spawner1(notEmptyShip, 10, 10, 10);
    TSpawnDescriptor spawner2(notEmptyShip, 11, 11, 11);

    TPirateBase obj(0, 0, BASE_P, spawner1);

    ASSERT_EQ(obj.GetSpawnDescriptor(), spawner1);
    obj.SetSpawnDescriptor(spawner2);
    ASSERT_EQ(obj.GetSpawnDescriptor(), spawner2);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

