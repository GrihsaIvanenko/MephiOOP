//
// Created by grigorijivanenko on 29.11.22.
//

#ifndef LAB4_TWEAPON_H
#define LAB4_TWEAPON_H

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

    int MakeShot(int sqDistance, int timeNow);
};

#endif //LAB4_TWEAPON_H

