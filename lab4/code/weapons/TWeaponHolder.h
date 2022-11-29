//
// Created by grigorijivanenko on 29.11.22.
//

#ifndef LAB4_TWEAPONHOLDER_H
#define LAB4_TWEAPONHOLDER_H

#include <memory>
#include <vector>

#include "../enums/enum_place_on_ship.h"
#include "TWeapon.h"

class TWeaponHolder {
private:
    std::vector<std::pair<EPlaceOnShip, std::unique_ptr<TWeapon>>> Weapons_;
    std::unique_ptr<TWeapon> createUniquePtrByGunPrt(TWeapon* gun);
public:
    TWeaponHolder();
    TWeaponHolder(TWeapon* GunFront, TWeapon* GunBack, TWeapon* GunLeftSide, TWeapon* GunRightSide);
    TWeapon* GetGunByPlace(EPlaceOnShip place);
    void SetGunByPlace(EPlaceOnShip place, TWeapon* what);
};

#endif //LAB4_TWEAPONHOLDER_H
