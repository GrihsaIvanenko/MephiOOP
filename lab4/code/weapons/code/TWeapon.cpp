//
// Created by grigorijivanenko on 29.11.22.
//

#include "TWeapon.h"
#include <iostream>

TWeapon::TWeapon(int weaponType, int damage, int callDown, int lastShot, int range, int shotsTotal, int shotsNow, int cost)
    : WeaponType_(weaponType)
    , Damage_(damage)
    , CallDown_(callDown)
    , LastShot_(lastShot)
    , Range_(range)
    , ShotsTotal_(shotsTotal)
    , ShotsNow_(shotsNow)
    , Cost_(cost)
{ }

TWeapon::TWeapon(const TWeapon &other)
    : WeaponType_(other.WeaponType_)
    , Damage_(other.Damage_)
    , CallDown_(other.CallDown_)
    , LastShot_(other.LastShot_)
    , Range_(other.Range_)
    , ShotsTotal_(other.ShotsTotal_)
    , ShotsNow_(other.ShotsNow_)
    , Cost_(other.Cost_)
{ }

TWeapon& TWeapon::operator =(const TWeapon& other) {
    WeaponType_ = other.WeaponType_;
    Damage_ = other.Damage_;
    CallDown_ = other.CallDown_;
    LastShot_ = other.LastShot_;
    Range_ = other.Range_;
    ShotsTotal_ = other.ShotsTotal_;
    ShotsNow_ = other.ShotsNow_;
    Cost_ = other.Cost_;
    return *this;
}

bool TWeapon::operator ==(const TWeapon& other) const {
    return
        WeaponType_ == other.WeaponType_ &&
        Damage_ == other.Damage_ &&
        CallDown_ == other.CallDown_ &&
        LastShot_ == other.LastShot_ &&
        Range_ == other.Range_ &&
        ShotsTotal_ == other.ShotsTotal_ &&
        ShotsNow_ == other.ShotsNow_ &&
        Cost_ == other.Cost_;
}

void TWeapon::SetWeaponType(int weaponType) {
    WeaponType_ = weaponType;
}

void TWeapon::SetDamage(int damage) {
    Damage_ = damage;
}

void TWeapon::SetCallDown(int callDown) {
    CallDown_ = callDown;
}

void TWeapon::SetLastShot(int lastShot) {
    LastShot_ = lastShot;
}

void TWeapon::SetRange(int range) {
    Range_ = range;
}

void TWeapon::SetShotsTotal(int shotsTotal) {
    ShotsTotal_ = shotsTotal;
}

void TWeapon::SetShotsNow(int shotsNow) {
    ShotsNow_ = shotsNow;
}

void TWeapon::SetCost(int cost) {
    Cost_ = cost;
}

int TWeapon::GetWeaponType() const {
    return WeaponType_;
}

int TWeapon::GetDamage() const {
    return Damage_;
}

int TWeapon::GetLastShot() const {
    return LastShot_;
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

int TWeapon::MakeShot(int sqDistance, int timeNow) {
    if (LastShot_ + CallDown_ > timeNow)
        return 0;
    if (ShotsNow_ == 0)
        return 0;
    if (Range_ * Range_ < sqDistance)
        return 0;
    --ShotsNow_;
    LastShot_ = timeNow;
    return Damage_;
}

void TWeapon::Print() const {
    std::cout << "          Damage = " << Damage_ << '\n';
    std::cout << "          CallDown = " << CallDown_ << '\n';
    std::cout << "          Range = " << Range_ << '\n';
    std::cout << "          ShotsTotal = " << ShotsTotal_ << '\n';
    std::cout << "          Cost = " << Cost_ << '\n';
}
