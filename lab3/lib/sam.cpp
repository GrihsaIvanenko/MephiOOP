#include "sam.h"
#include <iostream>

using namespace std;

Sam::Sam() : size_(0), numbers_(0) {
    Fill();
}

Sam::Sam(int size) : size_(size), numbers_(size) {
    Fill();
}

Sam::Sam(const MyVector& numbers): size_(numbers.Size()), numbers_(numbers.Size()) {
    for (int i = 0; i < size_; ++i)
        numbers_[i] = numbers.At(i);
}

Sam::Sam(Sam& other) : size_(other.size_), numbers_(other.size_) {
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


void Sam::PushBack() {
     numbers_.PushBack(GenRand()); 
     ++size_;
}

void Sam::PushBack(const double& val) {
    numbers_.PushBack(val);
	++size_;
}

double Sam::operator [](int id) const {
    return numbers_.At(id);
}

double Sam::Mean() const {
    if (size_ == 0)
        throw "Error: Set is empty!";
    double sum = 0;
    for (int i = 0; i < size_; ++i)
        sum += numbers_.At(i);
    return sum / size_;
}

void Sam::IncreaseSizeTo(int size) {
    while (size_ < size) {
        numbers_.PushBack(GenRand());
        ++size_;
    }
}

Sam Sam::SelectFromTo(double from, double to) const {
    Sam ans;
    for (int i = 0; i < size_; ++i)
        if (from <= numbers_.At(i) && numbers_.At(i) <= to)
            ans.PushBack(numbers_.At(i));
    return ans;
}

int Sam::Size() const {
    return size_;
}

ostream& operator <<(ostream& out, const Sam& to_print) {
    out << "Set of " << to_print.Size() << " elems: {";
    for (int i = 0; i + 1 < to_print.Size(); ++i)
        out << to_print[i] << ", ";
    if (to_print.Size() > 0)
        out << to_print[to_print.Size() - 1];
    return out << "}";
}
