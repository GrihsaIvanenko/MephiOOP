//
// Created by grigorijivanenko on 13.12.22.
//

#ifndef LAB4_PIRATEBASE_H
#define LAB4_PIRATEBASE_H

#include "TBase.h"
#include "TSpawnDescriptor.h"

/*!
 * \brief Класс, описывающий базу пиратов. Есть поле - спавнер
 */

class TPirateBase : public TBase {
private:
    TSpawnDescriptor Spawner_;
public:
    TPirateBase(int x, int y, int baseType, const TSpawnDescriptor& spawner);
    TPirateBase(const TPirateBase& other);
    TPirateBase& operator =(const TPirateBase& other);
    bool operator ==(const TPirateBase& other) const;

    void SetSpawnDescriptor(const TSpawnDescriptor& x);

    /*!
     * Вызывает аналогичный метод у spawner для задания координаты, где будут появляться новые корабли.
     */
    void SetXYInSpawn();

    TSpawnDescriptor& GetSpawnDescriptor();
};

#endif //LAB4_PIRATEBASE_H
