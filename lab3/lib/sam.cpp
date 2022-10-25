#include "sam.h"

using namespace std;

Sam::Sam() : size_(1) {
    Fill();
}

Sam::Sam(int size) : size_(size) {
    Fill();
}

Sam::Sam(const double *numbers, const int n): size_(n) {
    for (int i = 0; i < size_; ++i)
        numbers_[i] = numbers[i];
}

Sam::Sam(Sam& other) : size_(other.size_) {
    for (int i = 0; i < size_; ++i)
        numbers_[i] = other.numbers_[i];
}

double Sam::GenRand() {
    double res = 0;
    double val = 0.5;
    for (int i = 0; i < 32; ++i) {
        if (rand() % 2)
            res += val;
        val /= 2.0;
    }
    return res;
}

void Sam::Fill() {
    for (int i = 0; i < size_; ++i)
        numbers_[i] = GenRand();
}

void Sam::Reset() {
    Fill();
}

void Sam::Print() {
    cout << "Set of" << size_ << "elems: {";
    for (int i = 0; i < size_; ++i)
        cout << numbers_[i] << ", ";
    cout << "}";
}

void Sam::PushBack() {
    PushBack(GenRand()); 
}

void Sam::PushBack(double val) {
    if (size_ == 100)
        throw "Error: Out of range";
    numbers_[size_++] = val; 
}

double Sam::GetByIndex(int id) {
    if (id < 0 || size_ <= id)
        throw "Error: Out of range";
    return numbers_[id];
}

double Sam::Mean() {
    if (size_ == 0)
        throw "Error: Set is empty!";
    double sum = 0;
    for (int i = 0; i < size_; ++i)
        sum += numbers_[i];
    return sum / size_;
}

void Sam::IncreaseSizeTo(int size) {
    if (size <= size_) {
        size_ = size;
        return;
    }
    if (size > 100)
        throw "Error: Out of range";
    while (size_ < size)
        numbers_[size_++] = GenRand();
}

Sam Sam::SelectFromTo(double from, double to) {
    Sam ans;
    for (int i = 0; i < size_; ++i)
        if (from <= numbers_[i] && numbers_[i] <= to)
            ans.PushBack(numbers_[i]);
    return ans;
}


int Sam::GetSize() {
    return size_;
}
