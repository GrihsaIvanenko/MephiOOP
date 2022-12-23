//
// Created by grigorijivanenko on 29.11.22.
//

#include <cassert>
#include <iostream>

#include "TWeaponHolder.h"

TWeaponHolder::TWeaponHolder() {
    Weapons_.emplace_back(ShipFront, nullptr);
    Weapons_.emplace_back(ShipBack, nullptr);
    Weapons_.emplace_back(ShipLeftSide, nullptr);
    Weapons_.emplace_back(ShipRightSide, nullptr);
}

TWeaponHolder::TWeaponHolder(TWeapon *gunFront, TWeapon *gunBack, TWeapon *gunLeftSide, TWeapon *gunRightSide)
    : TWeaponHolder() {
    assert(Weapons_.size() == 4);
    SetGunByPlace(ShipFront, gunFront);
    SetGunByPlace(ShipBack, gunBack);
    SetGunByPlace(ShipLeftSide, gunLeftSide);
    SetGunByPlace(ShipRightSide, gunRightSide);
}

TWeaponHolder::TWeaponHolder(const TWeaponHolder& other)
    : TWeaponHolder() {
    assert(Weapons_.size() == 4);
    for (auto& [placeNow, gunPtr] : other.Weapons_)
        if (gunPtr)
            SetGunByPlace(placeNow, gunPtr.get());
}

TWeaponHolder& TWeaponHolder::operator =(const TWeaponHolder& other) {
    for (auto& [placeNow, gunPtr] : other.Weapons_)
        if (gunPtr)
            SetGunByPlace(placeNow, gunPtr.get());
    return *this;
}

bool TWeaponHolder::operator ==(const TWeaponHolder& other) const {
    for (int id = 0; id < 4; ++id)
        if (!SameGuns(this->Weapons_[id].second.get(), other.Weapons_[id].second.get()))
            return false;
    return true;
}

TWeapon* TWeaponHolder::GetGunByPlace(EPlaceOnShip placeSearch) const {
    for (auto& [placeNow, gunPtr] : Weapons_)
        if (placeNow == placeSearch)
            return gunPtr ? gunPtr.get() : nullptr;
    throw "Holder does not contains placeSearch!";
}

void TWeaponHolder::SetGunByPlace(EPlaceOnShip placeSearch, TWeapon* what) {
    for (auto& [placeNow, GunPtr] : Weapons_)
        if (placeNow == placeSearch) {
            GunPtr = std::move(createUniquePtrByGunPtr(what));
            return;
        }
    throw "Holder does not contains placeSearch!";
}

int TWeaponHolder::MakeShot(int sqDistance, int timeNow) {
    int totalDamage = 0;
    for (auto& [placeNow, GunPtr] : Weapons_)
        if (GunPtr)
            totalDamage += GunPtr->MakeShot(sqDistance, timeNow);
    return totalDamage;
}

void TWeaponHolder::Print() const {
    std::cout << "      gun in Front\n";
    if (Weapons_[0].second) {
        Weapons_[0].second->Print();
    } else {
        std::cout << "          No Gun\n";
    }

    std::cout << "      gun in Back\n";
    if (Weapons_[1].second) {
        Weapons_[1].second->Print();
    } else {
        std::cout << "          No Gun\n";
    }

    std::cout << "      gun in Left\n";
    if (Weapons_[2].second) {
        Weapons_[2].second->Print();
    } else {
        std::cout << "          No Gun\n";
    }

    std::cout << "      gun in Right\n";
    if (Weapons_[3].second) {
        Weapons_[3].second->Print();
    } else {
        std::cout << "          No Gun\n";
    }
}

int TWeaponHolder::GetCost() const {
    int ans = 0;
    for (auto& [placeNow, GunPtr] : Weapons_)
        if (GunPtr)
           ans += GunPtr->GetCost();
    return ans;
}
