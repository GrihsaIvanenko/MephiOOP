//
// Created by grigorijivanenko on 29.11.22.
//

#include "TWeapon.h"

TWeapon::TWeapon(int WeaponType, int Damage, int CallDown, int Range, int ShotsTotal, int ShotsNow, int Cost)
    : WeaponType_(WeaponType)
    , Damage_(Damage)
    , CallDown_(CallDown)
    , Range_(Range)
    , ShotsTotal_(ShotsTotal)
    , ShotsNow_(ShotsNow)
    , Cost_(Cost)
{ }

TWeapon& TWeapon::operator =(const TWeapon& other) {
    WeaponType_ = other.WeaponType_;
    Damage_ = other.Damage_;
    CallDown_ = other.CallDown_;
    Range_ = other.Range_;
    ShotsTotal_ = other.ShotsTotal_;
    ShotsNow_ = other.ShotsNow_;
    Cost_ = other.Cost_;
    return *this;
}

void TWeapon::SetWeaponType(int WeaponType) {
    WeaponType_ = WeaponType;
}

void TWeapon::SetDamage(int Damage) {
    Damage_ = Damage;
}

void TWeapon::SetCallDown(int CallDown) {
    CallDown_ = CallDown;
}

void TWeapon::SetRange(int Range) {
    Range_ = Range;
}

void TWeapon::SetShotsTotal(int ShotsTotal) {
    ShotsTotal_ = ShotsTotal;
}

void TWeapon::SetShotsNow(int ShotsNow) {
    ShotsNow_ = ShotsNow;
}

void TWeapon::SetCost(int Cost) {
    Cost_ = Cost;
}

int TWeapon::GetWeaponType() const {
    return WeaponType_;
}

int TWeapon::GetDamage() const {
    return Damage_;
}

int TWeapon::GetCallDown() const {
    return CallDown_;
}

int TWeapon::GetRange() const {
    return Range_;
}

int TWeapon::GetShotsTotal() const {
    return ShotsTotal_;
}

int TWeapon::GetShotsNow() const {
    return ShotsNow_;
}

int TWeapon::GetCost() const {
    return Cost_;
}

int TWeapon::MakeShot() {
    if (ShotsNow_ > 0) {
        --ShotsNow_;
        return Damage_;
    }
    return 0;
}
