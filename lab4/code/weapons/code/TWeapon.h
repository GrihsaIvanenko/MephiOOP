//
// Created by grigorijivanenko on 29.11.22.
//

#ifndef LAB4_TWEAPON_H
#define LAB4_TWEAPON_H

/*!
 * \brief Класс, описывающий вооружение
 */


class TWeapon {
    friend class TWeaponTestHelper;
private:
    int WeaponType_;
    int Damage_;
    int CallDown_;
    int LastShot_;
    int Range_;
    int ShotsTotal_;
    int ShotsNow_;
    int Cost_;

public:
    TWeapon(int weaponType, int damage, int callDown, int lastShot, int range, int shotsTotal, int shotsNow, int cost);
    TWeapon(const TWeapon& other);
    TWeapon& operator =(const TWeapon& other);
    bool operator ==(const TWeapon& other) const;

    void SetWeaponType(int weaponType);
    void SetDamage(int damage);
    void SetCallDown(int callDown);
    void SetLastShot(int callDown);
    void SetRange(int range);
    void SetShotsTotal(int shotsTotal);
    void SetShotsNow(int shotsNow);
    void SetCost(int cost);

    int GetWeaponType() const;
    int GetDamage() const;
    int GetCallDown() const;
    int GetLastShot() const;
    int GetRange() const;
    int GetShotsTotal() const;
    int GetShotsNow() const;
    int GetCost() const;

    /*!
     * Возвращает урон, если орудие успело перезарядиться, есть пули, и цель ближе, чем радиус стрельбы.
     * @param sqDistance  Передавать квадрат расстояния до объекта
     * @param timeNow Время выстрела
     * @return
     */
    int MakeShot(int sqDistance, int timeNow);

    /*!
     * Используется для вывода информации в магазине
     */
    void Print() const;
};

#endif //LAB4_TWEAPON_H

