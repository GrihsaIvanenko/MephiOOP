//
// Created by grigorijivanenko on 13.12.22.
//

#include "TPirateBase.h"

TPirateBase::TPirateBase(int x, int y, const TSpawnDescriptor &spawner)
    : TBase(x, y)
    , Spawner_(spawner)
{ }

TPirateBase::TPirateBase(const TBase &other)
    : TBase(other)
    , Spawner_(other.Spawner_)
{ }

TPirateBase& TPirateBase::operator =(const TPirateBase& other) {
    static_cast<TBase&>(*this) = other;
    Spawner_ = other.Spawner_;
    return this;
}

bool TPirateBase::operator == (const TPirateBase& other) {
    return
        static_cast<TBase&>(this) == static_cast<TBase&>(other) &&
        Spawner_ == other.Spawner_;
}

void TPirateBase::SetSpawnDescription(const TSpawnDescriptor& spawner) {
    Spawner_ = spawner;
}

TSpawnDescriptor TPirateBase::GetSpawnDescriptor() const {
    return Spawner_;
}
