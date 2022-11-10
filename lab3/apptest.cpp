#include "gtest/gtest.h"
#include "lib/sam.h"
#include "myVector/myVector.h"
#include <cmath> 


TEST(MyVector, DefaultConstuctor) {
    MyVector v;
    ASSERT_EQ(0, v.Size());
}

TEST(MyVector, SizeConstructor) {
    MyVector v(2);
    ASSERT_EQ(2, v.Size());
    ASSERT_EQ(0.0, v[0]);
    ASSERT_EQ(0.0, v[1]);
}

TEST(MyVector, CopyConstructor) {
    MyVector v(2);
    v[0] = 1.0;
    v[1] = 0.2;
    MyVector v1(v);
    ASSERT_EQ(v1.Size(), v.Size());
    ASSERT_EQ(v1[0], v[0]);
    ASSERT_EQ(v1[1], v[1]);
}

TEST(MyVector, MoveConstructor) {
    MyVector v(2);
    v[0] = 1.0;
    v[1] = 0.2;
    MyVector v1(std::move(v));
    ASSERT_EQ(v1.Size(), 2);
    ASSERT_EQ(v.Size(), 0);
    ASSERT_EQ(v1[0], 1.0);
    ASSERT_EQ(v1[1], 0.2);
}

TEST(MyVector, PushBack_PopBack) {
    MyVector v;
    for (int i = 0; i < 10; ++i) {
        v.PushBack(0.4);
        ASSERT_EQ(v.Size(), i + 1);
        ASSERT_EQ(v[v.Size() - 1], 0.4);
    }
    for (int i = 0; i < 10; ++i)
        v.PopBack();
    ASSERT_EQ(v.Size(), 0);
    v.PushBack(0.1);
    ASSERT_EQ(v.Size(), 1);
    ASSERT_EQ(v.At(v.Size() - 1), 0.1);
}

TEST(MyVector, OPERATOR_EQUAL) {
    MyVector a(2);
    a[0] = 0.1;
    a[1] = 0.2;
    a.PushBack(0.3);
    MyVector b;
    b = a;
    b.PushBack(0.4);
    ASSERT_EQ(b[3], 0.4);
    ASSERT_EQ(b.Size(), 4);
    ASSERT_EQ(a.Size(), 3);
}

TEST(Sam, Constructors) {
    Sam a;
    ASSERT_EQ(a.Size(), 0);

    Sam b(2);
    ASSERT_EQ(b.Size(), 2);
    ASSERT_EQ(0.0 <= b[0] && b[0] <= 1.0, true);
    ASSERT_EQ(0.0 <= b[1] && b[1] <= 1.0, true);

    MyVector v(3);
    v[0] = 0.2;
    v[1] = 0.7;
    v[2] = 0.1;
    Sam c(v);
    ASSERT_EQ(c.Size(), 3);
    ASSERT_EQ(c[0], v[0]);
    ASSERT_EQ(c[1], v[1]);
    ASSERT_EQ(c[2], v[2]);

    Sam d(b);
    ASSERT_EQ(b.Size(), d.Size());
    ASSERT_EQ(b[0], d[0]);
    ASSERT_EQ(b[1], d[1]);

    Sam e(move(d));
    ASSERT_EQ(e.Size(), 2);
    ASSERT_EQ(d.Size(), 0);
    ASSERT_EQ(e[0], b[0]);
    ASSERT_EQ(e[1], b[1]);
}

TEST(Sam, PushBack) {
    MyVector v(3);
    v[0] = 0.2;
    v[1] = 0.7;
    v[2] = 0.1;
    Sam c(v);
    c.PushBack();
    ASSERT_EQ(c.Size(), 4);
    c.PushBack(1.0);
    ASSERT_EQ(c.Size(), 5);
    ASSERT_EQ(c[c.Size() - 1], 1.0);
}

TEST(Sam, Mean) {
    MyVector v(3);
    v[0] = 0.1;
    v[1] = 0.2;
    v[2] = 0.3;
    Sam c(v);
    double mean = c.Mean();
    ASSERT_EQ(fabs(mean - 0.2) <= 1e-5, true);
}

TEST(Sam, IncreaseSizeTo) {
    Sam a;
    a.IncreaseSizeTo(10);
    ASSERT_EQ(a.Size(), 10);
    a.IncreaseSizeTo(5);
    ASSERT_EQ(a.Size(), 10);
    a.IncreaseSizeTo(20);
    ASSERT_EQ(a.Size(), 20);
}

TEST(Sam, SelectFromTo) {
    MyVector v(3);
    v[0] = 0.1;
    v[1] = 0.2;
    v[2] = 0.3;
    Sam c(v);
    Sam T1 = c.SelectFromTo(0.0, 0.05);
    ASSERT_EQ(T1.Size(), 0);
    Sam T2 = c.SelectFromTo(0.0, 0.25);
    ASSERT_EQ(T2.Size(), 2);
    ASSERT_EQ(T2[0], 0.1);
    ASSERT_EQ(T2[1], 0.2);
    Sam T3 = c.SelectFromTo(0.25, 0.50);
    ASSERT_EQ(T3.Size(), 1);
    ASSERT_EQ(T3[0], 0.3);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
