#include "curve.h"

bool eq(double who, double what) {
    return fabs(who - what) < EPS;
}

Point::Point(double x_, double y_)
    :x(x_)
    ,y(y_)
{ }

bool operator == (const Point a, const Point b) {
    return eq(a.x, b.x) && eq(a.y, b.y);
}

DoubleOrError::DoubleOrError(double x_, Status errorCode_)
    :x(x_)
    ,errorCode(errorCode_)
{ }

KonhoidNicomed::KonhoidNicomed()
    :a_(1.0)
    ,l_(1.0)
{ }

KonhoidNicomed::KonhoidNicomed(double a, double l)
    :a_(a)
    ,l_(l)
{ }

void KonhoidNicomed::SetA(double a) {
    a_ = a;
}

void KonhoidNicomed::SetL(double l) {
    l_ = l;
}

double KonhoidNicomed::GetA() const {
    return a_;
}

double KonhoidNicomed::GetL() const {
    return l_;
}

DoubleOrError KonhoidNicomed::GetYbyX(double x)const {
    bool onLeftPart = (x >= 0) ? true : false;
    if (eq(l_, 0.0))
        return eq(x, 0.0)
            ? DoubleOrError(0.0, OK)
            : DoubleOrError(0.0, ERROR_NO_Y_BY_X);
    double cosFi = (onLeftPart) ? (a_ - x) / l_ : (x - a_) / l_;
    if (fabs(cosFi) >= 1.0)
        return DoubleOrError(0.0, ERROR_NO_Y_BY_X);
    //cosFi != 0 because r = r/cos(fi) +- l
    double r = x / cosFi;
    double sinFi = sqrt(1 - cosFi * cosFi);
    return DoubleOrError(r * sinFi, OK);
}

DoubleOrError KonhoidNicomed::DistByFi(double fi, bool onLeftPart)const {
    double cosFi = cos(fi);
    if (eq(cosFi, 0.0))
        return DoubleOrError(0.0, ERROR_NO_X_BY_FI);
    if (cosFi < 0)
        return DoubleOrError(0.0, ERROR_INVALID_FI);
    double r = onLeftPart ? a_ / cosFi - l_ : a_ / cosFi + l_;
    return DoubleOrError(r * cosFi, OK);
}

double KonhoidNicomed::RadiusCurvature(bool onLeftPart) const {
    return onLeftPart ? (l_ - a_) * (l_ - a_) / l_ : (l_ + a_) * (l_ + a_) / l_;
}

double KonhoidNicomed::SquareOfLoop() const {
    if (l_ <= a_)
        return 0.0;
    return a_ * sqrt(l_ * l_ - a_ * a_)
        - 2 * a_ * l_ * log(
            (l_ + sqrt(l_ * l_ -  a_ * a_)) / a_)
        + l_ * l_ * acos(a_ / l_);
}
std::vector<Point> KonhoidNicomed::GetInflectionPoints()const {
    std::vector<Point> ans;
    double x;
    if (l_ / a_ > 1.0) {
        x = 2.35 * a_;
    } else if (eq(l_ / a_, 1.0)) {
        x = a_ * sqrt(3);
        ans.emplace_back(0, 0);
    } else {
        x = a_ * 1.38;    
    }
    double y = GetYbyX(x).x;
    ans.emplace_back(x, y);
    ans.emplace_back(x, -y);
    return ans;
}
