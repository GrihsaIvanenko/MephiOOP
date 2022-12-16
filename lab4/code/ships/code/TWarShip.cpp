//
// Created by grigorijivanenko on 01.12.22.
//

#include "TWarShip.h"

TWarShip::TWarShip(
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
        const TWeaponHolder& holder)
    : TShip(
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
    , Holder_(holder)
{ }

TWarShip::TWarShip(const TWarShip& other)
    : TShip(other)
    , Holder_(other.Holder_)
{ }

TWarShip& TWarShip::operator =(const TWarShip& other) {
    static_cast<TShip&>(*this) = other;
    Holder_ = other.Holder_;
    return *this;
}
bool TWarShip::operator ==(const TWarShip& other) const {
    return
        static_cast<const TShip&>(*this) == static_cast<const TShip&>(other) &&
        Holder_ == other.Holder_;
}

void TWarShip::SetHolder(const TWeaponHolder& holder) {
    Holder_ = holder;
}

TWeaponHolder TWarShip::GetHolder() const {
    return Holder_;
}

bool TWarShip::MakeShot(TShip& to, int timeNow) {
    int damage = Holder_.MakeShot(DistTo(to), timeNow);
    to.BeDamaged(damage);
    return to.GetHPNow() != 0;
}