//
// Created by grigorijivanenko on 20.12.22.
//

#include "TMission.h"

TMission::TMission(const TCapitanInfo &capitan, int moneyTotal, int weightTotal, int weightNeedToPass, int width,
                   int height, const TBase &a, const TBase &b, MyList<TPirateBase>&& pirateBases)
   : Capitan_(capitan)
   , Convoy_()
   , Pirates_()
   , MoneyTotal_(moneyTotal)
   , WeightTotal_(weightTotal)
   , WeightNeedToPass_(weightNeedToPass)
   , WeightLost_(0)
   , Width_(width)
   , Height_(height)
   , A_(a)
   , B_(b)
   , PirateBases_(std::move(pirateBases))
{ }

int TMission::GetMoney() const {
        return MoneyTotal_;
}

void TMission::SetMoney(int money) {
    MoneyUsed_ = money;
}