//
// Created by grigorijivanenko on 29.11.22.
//

#include "TShip.h"
#include <iostream>

TShip::TShip(int x, int y, int shipType, const std::string &shipName, const TCapitanInfo &capitanInfo, int maxSpeed,
             int nowSpeed, int hpTotal, int hpNow, int cost)
    : TObjectOnMap(x, y)
    , ShipType_(shipType)
    , ShipName_(shipName)
    , CapitanInfo_(capitanInfo)
    , MaxSpeed_(maxSpeed)
    , NowSpeed_(nowSpeed)
    , HPTotal_(hpTotal)
    , HPNow_(hpNow)
    , Cost_(cost)
{ }

TShip::TShip(const TShip &other)
    : TObjectOnMap(
            other.GetX(),
            other.GetY())
    , ShipType_(other.ShipType_)
    , ShipName_(other.ShipName_)
    , CapitanInfo_(other.CapitanInfo_)
    , MaxSpeed_(other.MaxSpeed_)
    , NowSpeed_(other.NowSpeed_)
    , HPTotal_(other.HPTotal_)
    , HPNow_(other.HPNow_)
    , Cost_(other.Cost_)
{ }

TShip& TShip::operator=(const TShip &other) {
    static_cast<TObjectOnMap&>(*this) = other;
    ShipType_ = other.ShipType_;
    ShipName_ = other.ShipName_;
    CapitanInfo_ = other.CapitanInfo_;
    MaxSpeed_ = other.MaxSpeed_;
    NowSpeed_ = other.NowSpeed_;
    HPTotal_ = other.HPTotal_;
    HPNow_ = other.HPNow_;
    Cost_ = other.Cost_;
    return *this;
}

bool TShip::operator ==(const TShip& other) const {
    return
        static_cast<const TObjectOnMap&>(*this) == static_cast<const TObjectOnMap&>(other) &&
        ShipType_ == other.ShipType_ &&
        ShipName_ == other.ShipName_ &&
        CapitanInfo_ == other.CapitanInfo_ &&
        MaxSpeed_ == other.MaxSpeed_ &&
        NowSpeed_ == other.NowSpeed_ &&
        HPTotal_ == other.HPTotal_ &&
        HPNow_ == other.HPNow_ &&
        Cost_ == other.Cost_;
}

void TShip::SetShipType(int shipType) {
    ShipType_ = shipType;
}

void TShip::SetShipName(const std::string& shipName) {
    ShipName_ = shipName;
}

void TShip::SetCapitanInfo(const TCapitanInfo& capitanInfo) {
    CapitanInfo_ = capitanInfo;
}

void TShip::SetMaxSpeed(int maxSpeed) {
    MaxSpeed_ = maxSpeed;
}

void TShip::SetNowSpeed(int nowSpeed) {
    NowSpeed_ = nowSpeed;
}

void TShip::SetHPTotal(int hpTotal) {
    HPTotal_ = hpTotal;
}

void TShip::SetHPNow(int hpNow) {
    HPNow_ = hpNow;
}

void TShip::SetCost(int cost) {
    Cost_ = cost;
}

int TShip::GetShipType() const {
    return ShipType_;
}

std::string TShip::GetShipName() const {
    return ShipName_;
}

TCapitanInfo TShip::GetCapitanInfo() const {
    return CapitanInfo_;
}

int TShip::GetMaxSpeed() const {
    return MaxSpeed_;
}

int TShip::GetNowSpeed() const {
    return NowSpeed_;
}

int TShip::GetHPTotal() const {
    return HPTotal_;
}

int TShip::GetHPNow() const {
    return HPNow_;
}

int TShip::GetCost() const {
    return Cost_;
}

void TShip::BeDamaged(int damage) {
    HPNow_ = std::max(HPNow_ - damage, 0);
}

void TShip::Print() const {
    std::cout << "MaxSpeed = " << MaxSpeed_ << '\n';
    std::cout << "HPTotal = " << HPTotal_ << '\n';
    std::cout << "Cost = " << Cost_ << '\n';
}

std::unique_ptr<TShip> TShip::Clone() const {
    return std::make_unique<TShip>(*this);
}


