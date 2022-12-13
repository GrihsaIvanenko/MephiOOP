//
// Created by grigorijivanenko on 13.12.22.
//

#ifndef LAB4_TMISSION_H
#define LAB4_TMISSION_H

#include "../../ships/code/TCapitanInfo.h"
#include "../../container/code/MyList.h"
#include "../../ships/code/TShip.h"
#include "../../ships/code/TWarShip.h"
#include "../../base/code/TBase.h"
#include "../../base/code/TPirateBase.h"

class TMission {
private:
    TCapitanInfo Capitan_;
    MylLst<TShip> Convoy_;
    MylLst<TWarShip> Pirates_;
    int MoneyTotal_;
    int MoneyUsed_;
    int WeightTotal_;
    int WeightNeedToPass_;
    int WeightCompleted_;
    int WeightLost_;
    int Width_;
    int Height_;
    TBase A_;
    TBase B_;
    MyList<TPirateBase> PirateBases_;
public:

};

#endif //LAB4_TMISSION_H
