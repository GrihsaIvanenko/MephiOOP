//
// Created by grigorijivanenko on 13.12.22.
//

#include "TPirateBase.h"

TPirateBase::TPirateBase(int x, int y, int baseType, const TSpawnDescriptor& spawner)
    : TBase(x, y, baseType)
    , Spawner_(spawner)
{ }

TPirateBase::TPirateBase(const TPirateBase& other)
    : TBase(other)
    , Spawner_(other.Spawner_)
{ }

TPirateBase& TPirateBase::operator =(const TPirateBase& other) {
    static_cast<TBase&>(*this) = other;
    Spawner_ = other.Spawner_;
    return *this;
}

bool TPirateBase::operator == (const TPirateBase& other) const {
    return
        static_cast<const TBase&>(*this) == static_cast<const TBase&>(other) &&
        Spawner_ == other.Spawner_;
}

void TPirateBase::SetSpawnDescriptor(const TSpawnDescriptor& spawner) {
    Spawner_ = spawner;
}

void TPirateBase::SetXYInSpawn() {
    Spawner_.SetXY(GetX(), GetY());
}

TSpawnDescriptor& TPirateBase::GetSpawnDescriptor(){
    return Spawner_;
}
