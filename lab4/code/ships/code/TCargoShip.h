//
// Created by grigorijivanenko on 01.12.22.
//

#ifndef LAB4_TCARGOSHIP_H
#define LAB4_TCARGOSHIP_H

#include "TShip.h"

class TCargoShip : virtual public TShip {
private:
    int WeightTotal_;
    int WeightNow_;
    double SlowK_; // [0.0. 1.0) 0.0 - not matter. 1.0 - stop
public:
    TCargoShip(
            int x,
            int y,
            int ShipType,
            const std::string& ShipName,
            const TCapitanInfo& CapitanInfo,
            int MaxSpeed,
            int NowSpeed,
            int HpTotal,
            int HpNow,
            int Cost,
            int WeightTotal,
            int WeightNow,
            double SlowK);
    TCargoShip(const TCargoShip& other);
    TCargoShip& operator = (const TCargoShip& other);
    bool operator == (const TCargoShip& other) const;

    void SetWeightTotal(int weightTotal);
    void SetWeightNow(int weightNow);
    void SetSlowK(double SlowK);

    int GetWeightTotal() const;
    int GetWeightNow() const;
    double GetSlowK() const;

    int SpeedByWeight(int weight) const; //-1 if overWeight
    int WeightMaxBySpeed(int speed) const; // -1 if overSpeed
};

#endif //LAB4_TCARGOSHIP_H
