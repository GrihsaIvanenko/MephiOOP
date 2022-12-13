//
// Created by grigorijivanenko on 13.12.22.
//

#include "TObjectOnMap.h"

TObjectOnMap::TObjectOnMap(int x, int y)
    : X_(x)
    , Y_(y)
{ }

TObjectOnMap::TObjectOnMap(const TObjectOnMap& other)
    : X_(other.X_)
    , Y_(other.Y_)
{ }

TObjectOnMap& TObjectOnMap::operator =(const TObjectOnMap& other) {
    X_ = other.X_;
    Y_ = other.Y_;
    return *this;
}
bool TObjectOnMap::operator ==(const TObjectOnMap& other) const {
    return
        X_ == other.X_ &&
        Y_ == other.Y_;
}

void TObjectOnMap::SetX(int x) {
    X_ = x;
}
void TObjectOnMap::SetY(int y) {
    Y_ = y;
}

int TObjectOnMap::GetX() const {
    return X_;
}

int TObjectOnMap::GetY() const {
    return Y_;
}

int TObjectOnMap::DistTo(const TObjectOnMap& other) const {
    int dx = X_ - other.X_;
    int dy = Y_ - other.Y_;
    return dx * dx + dy * dy;
}