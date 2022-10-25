#include "lib_curve/curve.h"
#include "gtest/gtest.h"

using namespace std;

TEST(KonhoidNicomed, DefaultConstructor)
{
    KonhoidNicomed a1;
    ASSERT_EQ(1.0, a1.GetA());
    ASSERT_EQ(1.0, a1.GetL());
}

TEST(KonhoidNicomed, InitConstructors) {
    KonhoidNicomed a1(2.0, 3.0);
    ASSERT_EQ(2.0, a1.GetA());
    ASSERT_EQ(3.0, a1.GetL());
}

TEST(KonhoidNicomed, Setters) {
    KonhoidNicomed a(3.0, 2.0);
    a.SetA(5.0);
    ASSERT_EQ(5.0, a.GetA());
    ASSERT_EQ(2.0, a.GetL());
    a.SetL(5.0);
    ASSERT_EQ(5.0, a.GetA());
    ASSERT_EQ(5.0, a.GetL());
}

TEST(KonhoidNicomed, Parameters) {
    KonhoidNicomed a(2.0, 3.0);
    ASSERT_EQ(ERROR_NO_Y_BY_X, a.GetYbyX(6.0).errorCode);
    ASSERT_DOUBLE_EQ(-8.4852813742385695, a.GetYbyX(3.0).x);
    ASSERT_EQ(ERROR_NO_X_BY_FI, a.DistByFi(1.57079632679, 0).errorCode);
    ASSERT_EQ(ERROR_INVALID_FI, a.DistByFi(3, 1).errorCode); 
    ASSERT_DOUBLE_EQ(3.6209069176044189, a.DistByFi(1, 0).x);
    ASSERT_DOUBLE_EQ(8.3333333333333339, a.RadiusCurvature(0));
    ASSERT_DOUBLE_EQ(0.33333333333333331, a.RadiusCurvature(1));
    ASSERT_DOUBLE_EQ(0.49267018868046808, a.SquareOfLoop());
    vector<Point> p = {Point(4.7, -2.27631389273), Point(4.7, 2.27631389273)};
    vector<Point> q = a.GetInflectionPoints();
    ASSERT_EQ(p.size(), q.size());
    for (int i = 0; i < p.size(); ++i) {
        ASSERT_EQ(eq(p[i].x, q[i].x), true);
        ASSERT_EQ(eq(p[i].y, q[i].y), true);
    }
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
