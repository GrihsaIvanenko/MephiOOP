#ifndef SAMH
#define SAMH

#include <iostream>
#include "./../myVector/myVector.h"

using namespace std;

class Sam {
private:
    MyVector numbers_;
    int size_;
    static double GenRand();
    void Fill();
public:
    Sam();
    Sam(int size);
    Sam(const MyVector& numbers);
    Sam(const Sam& other);
    void Reset();
    void PushBack();
    void PushBack(const double& val);
    double operator [](int id) const;
	double Mean() const;
    void IncreaseSizeTo(int size);
    Sam SelectFromTo(double from, double to) const;
    int Size() const;
};

ostream& operator <<(ostream& out, const Sam& to_print);

#endif //SAMH
