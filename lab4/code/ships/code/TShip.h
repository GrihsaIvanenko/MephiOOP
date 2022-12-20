//
// Created by grigorijivanenko on 29.11.22.
//

#ifndef LAB4_TSHIP_H
#define LAB4_TSHIP_H

#include <string>
#include <memory>

#include "TCapitanInfo.h"
#include "../../base/code/TObjectOnMap.h"

class TShip : public TObjectOnMap {
protected:
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
            int x,
            int y,
            int shipType,
            const std::string& shipName,
            const TCapitanInfo& capitanInfo,
            int maxSpeed,
            int nowSpeed,
            int hpTotal,
            int hpNow,
            int cost);
    TShip(const TShip& other);
    TShip& operator =(const TShip& other);
    bool operator ==(const TShip& other) const;

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

    void BeDamaged(int damage);

    virtual void Print() const;
    virtual std::unique_ptr<TShip> Clone() const;
};

#endif //LAB4_TSHIP_H
