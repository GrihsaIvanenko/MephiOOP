//
// Created by grigorijivanenko on 01.12.22.
//

#include <cmath>

#include "TCargoShip.h"

TCargoShip::TCargoShip(
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
        double slowK)
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
    , WeightTotal_(weightTotal)
    , WeightNow_(weightNow)
    , SlowK_(slowK)
{ }

TCargoShip::TCargoShip(const TCargoShip& other)
    : TShip(other)
    , WeightTotal_(other.WeightTotal_)
    , WeightNow_(other.WeightNow_)
    , SlowK_(other.SlowK_)
{ }

TCargoShip& TCargoShip::operator = (const TCargoShip& other) {
    static_cast<TShip&>(*this) = other;
    WeightTotal_ = other.WeightTotal_;
    WeightNow_ = other.WeightNow_;
    SlowK_ = other.SlowK_;
    return *this;
}

bool TCargoShip::operator == (const TCargoShip& other) const {
    return
        static_cast<const TShip&>(*this) == static_cast<const TShip&>(other) &&
        WeightTotal_ == other.WeightTotal_ &&
        WeightNow_ == other.WeightNow_ &&
        SlowK_ == other.SlowK_;
}

void TCargoShip::SetWeightTotal(int weightTotal) {
    WeightTotal_ = weightTotal;
}

void TCargoShip::SetWeightNow(int weightNow) {
    WeightNow_ = weightNow;
}

void TCargoShip::SetSlowK(double SlowK) {
    SlowK_ = SlowK;
}

int TCargoShip::GetWeightTotal() const {
    return WeightTotal_;
}

int TCargoShip::GetWeightNow() const {
    return WeightNow_;
}

double TCargoShip::GetSlowK() const {
    return SlowK_;
}

int TCargoShip::SpeedByWeight(int weight) const {
    if (weight > WeightTotal_)
        return -1;
    double perUsed = 1.0 - weight / (double)WeightTotal_;
    double vChangeable = MaxSpeed_ * SlowK_;
    double vStart = MaxSpeed_ - vChangeable;
    double vAdd = perUsed * vChangeable;
    int res = round(vStart + vAdd);
    return res;
}

int TCargoShip::WeightMaxBySpeed(int speed) const {
    if (speed > MaxSpeed_)
        return -1;
    double vChangeable = MaxSpeed_ * SlowK_;
    double vStart = MaxSpeed_ - vChangeable;
    if (vStart > (double)speed)
        return WeightTotal_;
    double perUSed = 1.0 - (speed - vStart) / vChangeable;
    double weightICan = perUSed * WeightTotal_;
    int res = round(weightICan);
    return res;
}