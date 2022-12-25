//
// Created by grigorijivanenko on 13.12.22.
//

#ifndef LAB4_TBASE_H
#define LAB4_TBASE_H

#define BASE_A 1
#define BASE_B 2
#define BASE_P 3

#include "TObjectOnMap.h"

/*!
 * \brief База на карте.
 * Есть поле BaseType - код базы: начальная точка маршрута(1), конечная(2) или же это база пиратов(3).
 */

class TBase : public TObjectOnMap {
private:
    int BaseType_;
public:
    TBase(int x, int y, int baseType);
    TBase(const TBase& other);
    TBase& operator =(const TBase& other);
    bool operator ==(const TBase& other) const;

    void SetBaseType(int baseType);

    int GetBaseType() const;
};

#endif //LAB4_TBASE_H
