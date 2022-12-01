//
// Created by grigorijivanenko on 29.11.22.
//

#ifndef LAB4_TWEAPONHOLDER_H
#define LAB4_TWEAPONHOLDER_H

#include <memory>
#include <vector>

#include "../../enums/enum_place_on_ship.h"
#include "TWeapon.h"

class TWeaponHolder {
private:
    std::vector<std::pair<EPlaceOnShip, std::unique_ptr<TWeapon>>> Weapons_;
    static std::unique_ptr<TWeapon> createUniquePtrByGunPtr(TWeapon* gun) {
        return gun
               ? std::move(std::make_unique<TWeapon>(*gun))
               : nullptr;
    }
public:
    TWeaponHolder();
    TWeaponHolder(TWeapon* gunFront, TWeapon* gunBack, TWeapon* gunLeftSide, TWeapon* gunRightSide);
    TWeaponHolder(const TWeaponHolder& other);
    TWeaponHolder& operator =(const TWeaponHolder& other);
    bool operator ==(const TWeaponHolder& other) const;

    TWeapon* GetGunByPlace(EPlaceOnShip place) const;

    void SetGunByPlace(EPlaceOnShip place, TWeapon* what);

    int MakeShot(int sqDistance);

    static bool SameGuns(const TWeapon* lhs, const TWeapon* rhs) {
        if (!lhs && !rhs)
            return true;
        if (!lhs || !rhs)
            return false;
        return *lhs == *rhs;
    }
};

#endif //LAB4_TWEAPONHOLDER_H
