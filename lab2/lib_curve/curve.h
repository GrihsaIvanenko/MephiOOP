#ifndef CURVE
#define CURVE

#include <vector>
#include <cmath>     

enum Status {    
    OK,
    ERROR_NO_Y_BY_X,
    ERROR_INVALID_FI,
    ERROR_NO_X_BY_FI
};


const double EPS = 1e-9;

bool eq(double who, double what);

struct Point {
    Point(double x_, double y_);
    double x;
    double y;
};

struct DoubleOrError {
    DoubleOrError(double x, Status errorCode);
    const double x;
    const Status errorCode;
};

class KonhoidNicomed {
public:
    KonhoidNicomed();
    KonhoidNicomed(double a, double l);

    void SetA(double a);
    void SetL(double l);

    double GetA() const;
    double GetL() const;

    DoubleOrError GetYbyX(double x) const;
    DoubleOrError DistByFi(double fi, bool onLeftPart) const;//fi from -pi/2 to pi/2
    double RadiusCurvature(bool onLeftPart) const;
    double SquareOfLoop() const;
    std::vector<Point> GetInflectionPoints() const;
private:
    double a_;
    double l_;
};

#endif // CURVE
