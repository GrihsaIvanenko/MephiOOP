#include "myVector.h"
#include <cassert>
#include <iostream>
using namespace std;

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
    if (allocatedSize_ != 0)
        data = new double[allocatedSize_];
    else
        data = nullptr;
    for (int i = 0; i < allocatedSize_; ++i)
        data[i] = 0;
}

MyVector::MyVector(const MyVector& other) {
    usedSize_ = other.usedSize_;
    allocatedSize_ = allocatedSize_;
    if (allocatedSize_ > 0)
        data = new double[allocatedSize_];
    else
        data = nullptr;
    for (int i = 0; i < other.usedSize_; ++i)
        data[i] = other.At(i);
    for (int i = other.Size(); i < allocatedSize_; ++i)
        data[i] = 0;
}

MyVector::MyVector(MyVector&& other) : usedSize_(0), allocatedSize_(0), data(nullptr) {
    swap(usedSize_, other.usedSize_);
    swap(allocatedSize_, other.allocatedSize_);
    swap(data, other.data);
}

MyVector::~MyVector() {
    if (allocatedSize_ != 0)
        delete[] data;
}

unsigned int MyVector::Size() const {
    return usedSize_;
}

void MyVector::PushBack(const double& val) {
    if (usedSize_ == allocatedSize_) {
        int newAllocatedSize_ = (allocatedSize_ == 0) ? 1 : (allocatedSize_ << 1);
        double* ndata = new double[newAllocatedSize_];
        for (int i = 0; i < allocatedSize_; ++i) {
            ndata[i] = data[i];
        }
        for (int i = allocatedSize_; i < newAllocatedSize_; ++i)
            ndata[i] = 0;
        if (allocatedSize_ != 0)
            delete[] data;
        allocatedSize_ = newAllocatedSize_;
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

MyVector& MyVector::operator =(MyVector&& other) {
    if (this != &other) {
        swap(usedSize_, other.usedSize_);
        swap(allocatedSize_, other.allocatedSize_);
        swap(data, other.data);
    }
    return *this;
}

double MyVector::At(int id) const {
    return data[id];
}

const MyVector& MyVector::operator =(const MyVector& other) {
    if (allocatedSize_ != 0)
        delete[] data;
    usedSize_ = other.usedSize_;
    allocatedSize_ = MyVector::getPow(usedSize_);
    if (allocatedSize_ != 0)
        data = new double[allocatedSize_];
    else
        data = nullptr;
    for (int i = 0; i < other.usedSize_; ++i)
        data[i] = other.At(i);
    for (int i = other.Size(); i < allocatedSize_; ++i)
        data[i] = 0;
    return *this;
}
