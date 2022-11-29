//
// Created by grigorijivanenko on 29.11.22.
//

#ifndef LAB4_TSHIP_H
#define LAB4_TSHIP_H

#include <string>
#include "TCapitanInfo.h"

class TShip {
private:
    int ShipType_;
    std::string ShipName_;
    TCapitanInfo CapitanInfo_;
    int MaxSpeed_;
    int NowSpeed_;
    int HPTotal_;
    int HPNow_;
    int Cost_;
public:
    TShip(
            int ShipType,
            const std::string& ShipName,
            const TCapitanInfo& CapitanInfo,
            int MaxSpeed,
            int NowSpeed,
            int HpTotal,
            int HpNow,
            int Cost);
    TShip(const TShip& other);
    TShip& operator =(const TShip& other);

    void SetShipType(int shipType);
    void SetShipName(const std::string& shipName);
    void SetCapitanInfo(const TCapitanInfo& capitanInfo);
    void SetMaxSpeed(int maxSpeed);
    void SetNowSpeed(int nowSpeed);
    void SetHPTotal(int hpTotal);
    void SetHPNow(int hpNow);
    void SetCost(int cost);

    int GetShipType() const;
    std::string GetShipName() const;
    TCapitanInfo GetCapitanInfo() const;
    int GetMaxSpeed() const;
    int GetNowSpeed() const;
    int GetHPTotal() const;
    int GetHPNow() const;
    int GetCost() const;

    void MakeDamage(int Damage);
};

#endif //LAB4_TSHIP_H
