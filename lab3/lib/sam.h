#ifndef SAMH
#define SAMH

#include <iostream>

class Sam {
private:
    double numbers_[100];
    int size_;
    double GenRand();
    void Fill();
public:
    Sam();
    Sam(int size);
    Sam(const double *numbers, const int n);
    Sam(Sam& other);
    void Reset();
    void Print();
    void PushBack();
    void PushBack(double val);
    double GetByIndex(int id);
    double Mean();
    void IncreaseSizeTo(int size);
    Sam SelectFromTo(double from, double to);
    int GetSize();
};

#endif //SAMH
