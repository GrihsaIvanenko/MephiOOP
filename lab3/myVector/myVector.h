#ifndef MYVECTOR
#define MYVECTOR

class MyVector {

private:
    unsigned int usedSize_;
    unsigned int allocatedSize_;
    double* data;
    static unsigned int getPow(unsigned int forWhat);
public:
    MyVector();
    MyVector(unsigned int size);
    ~MyVector();
    unsigned int Size() const;
    void PushBack(const double& item);
    void PopBack();
    double& operator [](int id);
    double At(int id) const;
};

#endif
