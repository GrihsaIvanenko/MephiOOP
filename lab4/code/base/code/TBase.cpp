//
// Created by grigorijivanenko on 13.12.22.
//

#include "TBase.h"

TBase::TBase(int x, int y, int baseType)
    : TObjectOnMap(x, y)
    , BaseType_(baseType)
{ }

TBase::TBase(const TBase& other)
    : TObjectOnMap(other)
    , BaseType_(other.BaseType_)
{ }

TBase& TBase::operator =(const TBase& other) {
    static_cast<TObjectOnMap&>(*this) = other;
    BaseType_ = other.BaseType_;
    return *this;
}

bool TBase::operator ==(const TBase& other) const {
    return
        static_cast<const TObjectOnMap&>(*this) == static_cast<const TObjectOnMap&>(other) &&
        BaseType_ == other.BaseType_;
}

void TBase::SetBaseType(int baseType) {
    BaseType_ = baseType;
}

int TBase::GetBaseType() const {
    return BaseType_;
}
