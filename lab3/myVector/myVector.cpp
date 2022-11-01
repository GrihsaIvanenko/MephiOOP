#include "myVector.h"
#include <cassert>

unsigned int MyVector::getPow(unsigned int forWhat) {
    if (forWhat == 0)
        return 0;
    unsigned int ans = 1;
    while (ans < forWhat)
        ans += ans;
    return ans;
}

MyVector::MyVector() : usedSize_(0), allocatedSize_(0), data(nullptr) { }

MyVector::MyVector(unsigned int size) : usedSize_(size) {
    allocatedSize_ = getPow(size);
    data = new double[allocatedSize_];
    for (int i = 0; i < allocatedSize_; ++i)
        data[i] = 0;
}

MyVector::~MyVector() {
    delete[] data;
}

unsigned int MyVector::Size() const {
    return usedSize_;
}

void MyVector::PushBack(const double& val) {
    if (usedSize_ == allocatedSize_) {
        double* ndata = new double[allocatedSize_ << 1];
        for (int i = 0; i < allocatedSize_; ++i) {
            ndata[i] = data[i];
            ndata[i + allocatedSize_] = 0;
        }
        delete[] data;
        allocatedSize_ += allocatedSize_;
        data = ndata;
    }
    data[usedSize_++] = val;
}

void MyVector::PopBack() {
    assert(usedSize_ > 0);
    --usedSize_;
}

double& MyVector::operator [](int id) {
    return data[id];
}

double MyVector::At(int id) const {
    return data[id];
}
