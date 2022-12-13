//
// Created by grigorijivanenko on 13.12.22.
//

#ifndef LAB4_PIRATEBASE_H
#define LAB4_PIRATEBASE_H

#include "TBase.h"
#include "TSpawnDescriptor.h"

class TPirateBase : public TBase {
private:
    TSpawnDescriptor Spawner_;
public:
    TPirateBase(int x, int y, const TSpawnDescriptor& spawner);
    TPirateBase(const TBase& other);
    TPirateBase& operator =(const TPirateBase& other);
    bool operator ==(const TPirateBase& other) const;

    void SetSpawnDescriptor(const TSpawnDescriptor& x);

    TSpawnDescriptor GetSpawnDescriptor() const;
};

#endif //LAB4_PIRATEBASE_H
