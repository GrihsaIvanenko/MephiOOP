//
// Created by grigorijivanenko on 06.12.22.
//

#ifndef LAB4_TCARGOWARSHIP_H
#define LAB4_TCARGOWARSHIP_H

#include "TWarShip.h"
#include "TCargoShip.h"

class TCargoWarShip : public TCargoShip, public TWarShip {
public:
    TCargoWarShip(
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
            int WeightTotal,
            int WeightNow,
            double SlowK,
            const TWeaponHolder& holder);
    TCargoWarShip(const TCargoWarShip& other);
    TCargoWarShip& operator =(const TCargoWarShip& other);
    bool operator ==(const TCargoWarShip& other) const;
};

#endif //LAB4_TCARGOWARSHIP_H
