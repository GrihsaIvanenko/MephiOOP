//
// Created by grigorijivanenko on 20.12.22.
//

#include "TMission.h"

TMission::TMission(const TCapitanInfo &capitan, int moneyTotal, int weightTotal, int weightNeedToPass, int width,
                   int height, const TBase &a, const TBase &b, MyList<TPirateBase>&& pirateBases)
   : Capitan_(capitan)
   , Convoy_()
   , Pirates_()
   , WeightPutted_(0)
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

int TMission::GetWeightPutted() const {
    return WeightPutted_;
}

int TMission::GetWeightTotal() const {
    return WeightTotal_;
}

int TMission::GetWeightNeedToPass() const {
    return WeightNeedToPass_;
}

int TMission::GetWeightCompleted() const {
    return WeightCompleted_;
}

int TMission::GetWidth() const {
    return Width_;
}

int TMission::GetHeight() const {
    return Height_;
}

TBase& TMission::GetBaseA() {
    return A_;
}

TBase& TMission::GetBaseB() {
    return B_;
}

MyList<TWarShip>& TMission::GetPirates() {
    return Pirates_;
}

MyList<TPirateBase>& TMission::GetPirateBases() {
    return PirateBases_;
}

MyList<std::unique_ptr<TShip>>& TMission::GetConvoy() {
    return Convoy_;
}

void TMission::SetMoney(int money) {
    MoneyTotal_ = money;
}

void TMission::SetWeightPutted(int weightPutted) {
    WeightPutted_ = weightPutted;
}

void TMission::SetWeightCompleted(int WeightCompleted) {
    WeightCompleted_ = WeightCompleted;
}


