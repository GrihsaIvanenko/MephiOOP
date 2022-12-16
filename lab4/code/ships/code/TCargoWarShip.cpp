//
// Created by grigorijivanenko on 06.12.22.
//

#include "TCargoWarShip.h"

TCargoWarShip::TCargoWarShip(
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
        int weightTotal,
        int weightNow,
        double slowK,
        const TWeaponHolder& holder)
    : TShip (
        x,
        y,
        shipType,
        shipName,
        capitanInfo,
        maxSpeed,
        nowSpeed,
        hpTotal,
        hpNow,
        cost)
    , TCargoShip(
            x,
            y,
            shipType,
            shipName,
            capitanInfo,
            maxSpeed,
            nowSpeed,
            hpTotal,
            hpNow,
            cost,
            weightTotal,
            weightNow,
            slowK)
    , TWarShip(
            x,
            y,
            shipType,
            shipName,
            capitanInfo,
            maxSpeed,
            nowSpeed,
            hpTotal,
            hpNow,
            cost,
            holder)
{ }

TCargoWarShip::TCargoWarShip(const TCargoWarShip& other)
    : TShip(other)
    , TCargoShip(other)
    , TWarShip(other)
{ }

TCargoWarShip& TCargoWarShip::operator =(const TCargoWarShip& other) {
        static_cast<TCargoShip&>(*this) = other;
        static_cast<TWarShip&>(*this) = other;
        return *this;
}

bool TCargoWarShip::operator ==(const TCargoWarShip& other) const {
    return
        static_cast<const TCargoShip&>(*this) == static_cast<const TCargoShip&>(other) &&
        static_cast<const TWarShip&>(*this) == static_cast<const TWarShip&>(other);
}
