//
// Created by grigorijivanenko on 01.12.22.
//

#ifndef LAB4_TWARSHIP_H
#define LAB4_TWARSHIP_H

#include "../../weapons/code/TWeaponHolder.h"
#include "TShip.h"

/*!
 * \brief Корабль, имеющий вооружение. Добавляются поле - Holder орудий
 */

class TWarShip : virtual public TShip {
protected:
    TWeaponHolder Holder_;
public:
    TWarShip(
            int x,
            int y,
            int shipType,
            const std::string& shipName,
            const TCapitanInfo& capitanInfo,
            int maxSpeed,
            int nowSpeed,
            int hpTotal,
            int hpNow,
            int cost,
            const TWeaponHolder& holder);
    TWarShip(const TWarShip& other);
    TWarShip& operator =(const TWarShip& other);
    bool operator ==(const TWarShip& other) const;

    void SetHolder(const TWeaponHolder& holder);
    TWeaponHolder& GetHolder();

    /*!
     * Используется для продажи корабля.
     * Вернет цену корабля с учетом орудий, установленных не него
     * @return
     */
    int GetCostWithGuns() const;

    /*!
     * Делает выстрел по кораблю в момент timeNow
     * Влачале вычисляется урон - результат выстрела всех орудий по кораблю
     * Затем это турон наосится цели, по которой произведенн выстрел
     * @param to
     * @param timeNow
     * @return
     */
    bool MakeShot(TShip& to, int timeNow);

    /*!
    * Определяет вывод информации в магазине об этго виде корабля.
    */
    void Print() const override;

    /*!
     * Определяет Clone для этого вида кораблей.
     * @return
     */
    std::unique_ptr<TShip> Clone() const override;
};

#endif //LAB4_TWARSHIP_H
