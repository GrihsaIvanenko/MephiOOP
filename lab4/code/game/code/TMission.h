//
// Created by grigorijivanenko on 13.12.22.
//

#ifndef LAB4_TMISSION_H
#define LAB4_TMISSION_H

#include "../../ships/code/TCapitanInfo.h"
#include "../../container/code/MyList.h"
#include "../../ships/code/TCargoWarShip.h"
#include "../../base/code/TBase.h"
#include "../../base/code/TPirateBase.h"

#include <memory>

class TMission {
private:
    TCapitanInfo Capitan_;
    MyList<std::unique_ptr<TShip>> Convoy_;
    MyList<TWarShip> Pirates_;
    int MoneyTotal_;
    int WeightPutted_;
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
    TMission(
            const TCapitanInfo& capitan,
            int moneyTotal,
            int weightTotal,
            int weightNeedToPass,
            int width,
            int height,
            const TBase& a,
            const TBase& b,
            MyList<TPirateBase>&& pirateBases);

    void SetMoney(int money);
    void SetWeightPutted(int weightPutted);

    int GetMoney() const;
    int GetWeightPutted() const;
    int GetWeightTotal() const;

    MyList<std::unique_ptr<TShip>>& GetConvoy() {
        return Convoy_;
    }

};

#endif //LAB4_TMISSION_H
