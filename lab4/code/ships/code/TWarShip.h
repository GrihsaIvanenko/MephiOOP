//
// Created by grigorijivanenko on 01.12.22.
//

#ifndef LAB4_TWARSHIP_H
#define LAB4_TWARSHIP_H

#include "../../weapons/code/TWeaponHolder.h"
#include "TShip.h"

class TWarShip : virtual public TShip {
private:
    TWeaponHolder Holder_;
public:
    TWarShip(
            int x,
            int y,
            int shipType,
            const std::string& shipName,
            const TCapitanInfo& capitanInfo,
            int maxSpeed,
            int nowSpeed,
            int hpTotal,
            int hpNow,
            int cost,
            const TWeaponHolder& holder);
    TWarShip(const TWarShip& other);
    TWarShip& operator =(const TWarShip& other);
    bool operator ==(const TWarShip& other) const;

    void SetHolder(const TWeaponHolder& holder);

    TWeaponHolder GetHolder() const;

    int MakeShot(const TObjectOnMap& to, int timeNow);
};

#endif //LAB4_TWARSHIP_H
