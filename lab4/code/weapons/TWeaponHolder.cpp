//
// Created by grigorijivanenko on 29.11.22.
//

#include "TWeaponHolder.h"
#include <cassert>

std::unique_ptr<TWeapon> TWeaponHolder::createUniquePtrByGunPrt(TWeapon* gun) {
    return gun
        ? std::move(std::make_unique<TWeapon>(*gun))
        : nullptr;
}

TWeaponHolder::TWeaponHolder() {
    Weapons_.emplace_back(ShipFront, nullptr);
    Weapons_.emplace_back(ShipBack, nullptr);
    Weapons_.emplace_back(ShipLeftSide, nullptr);
    Weapons_.emplace_back(ShipRightSide, nullptr);
}

TWeaponHolder::TWeaponHolder(TWeapon *GunFront, TWeapon *GunBack, TWeapon *GunLeftSide, TWeapon *GunRightSide)
    : TWeaponHolder() {
    assert(Weapons_.size() == 4);
    SetGunByPlace(ShipFront, GunFront);
    SetGunByPlace(ShipBack, GunBack);
    SetGunByPlace(ShipLeftSide, GunLeftSide);
    SetGunByPlace(ShipRightSide, GunRightSide);
}

TWeapon* TWeaponHolder::GetGunByPlace(EPlaceOnShip placeSearch) {
    for (auto& [placeNow, gunPtr] : Weapons_)
        if (placeNow == placeSearch)
            return gunPtr ? gunPtr.get() : nullptr;
    throw "Holder does not contains placeSearch!";
}

void TWeaponHolder::SetGunByPlace(EPlaceOnShip placeSearch, TWeapon *what) {
    for (auto& [placeNow, GunPtr] : Weapons_)
        if (placeNow == placeSearch) {
            GunPtr = std::move(createUniquePtrByGunPrt(what));
            return;
        }
    throw "Holder does not contains placeSearch!";
}
