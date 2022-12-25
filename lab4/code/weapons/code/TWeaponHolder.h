//
// Created by grigorijivanenko on 29.11.22.
//

#ifndef LAB4_TWEAPONHOLDER_H
#define LAB4_TWEAPONHOLDER_H

#include <memory>
#include <vector>

#include "../../enums/enum_place_on_ship.h"
#include "TWeapon.h"

/*!
 * \brief Класс, хранящий все вооружение боевого корабля.
 */

class TWeaponHolder {
private:
    std::vector<std::pair<EPlaceOnShip, std::unique_ptr<TWeapon>>> Weapons_;
    static std::unique_ptr<TWeapon> createUniquePtrByGunPtr(TWeapon* gun) {
        return gun
               ? std::move(std::make_unique<TWeapon>(*gun))
               : nullptr;
    }
public:
    TWeaponHolder();
    TWeaponHolder(TWeapon* gunFront, TWeapon* gunBack, TWeapon* gunLeftSide, TWeapon* gunRightSide);
    TWeaponHolder(const TWeaponHolder& other);
    TWeaponHolder& operator =(const TWeaponHolder& other);
    bool operator ==(const TWeaponHolder& other) const;

    /*!
     * Возвращает указатель на орудие по его позиции. Если орудия там нет, вернет nullptr
     * @param place
     * @return
     */
    TWeapon* GetGunByPlace(EPlaceOnShip place) const;

    /*!
     *  Принимает позицию на корабле и указатель на орудие, которое мы собираемся установить.
     *  Корректно работает с nullptr
     *  Если орудие на этой позиции было, оно удалится.
     * @param place
     * @param what
     */
    void SetGunByPlace(EPlaceOnShip place, TWeapon* what);

    /*!
     * Вернет урон всех орудий Holder-а, выстреливших в момент timenow на расстояние, квадрат которого sqDistance
     * @param sqDistance
     * @param timeNow
     * @return
     */
    int MakeShot(int sqDistance, int timeNow);

    /*!
     * Проверяет, совпадают ли орудия, на которые указывают указатели
     * @param lhs
     * @param rhs
     * @return
     */
    static bool SameGuns(const TWeapon* lhs, const TWeapon* rhs) {
        if (!lhs && !rhs)
            return true;
        if (!lhs || !rhs)
            return false;
        return *lhs == *rhs;
    }
    /*!
     * Используется для вывода информации в магазине
     */
    void Print() const;

    int GetCost() const;
};

#endif //LAB4_TWEAPONHOLDER_H
