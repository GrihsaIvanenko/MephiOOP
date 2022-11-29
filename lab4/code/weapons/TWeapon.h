//
// Created by grigorijivanenko on 29.11.22.
//

#ifndef LAB4_TWEAPON_H
#define LAB4_TWEAPON_H

class TWeapon {
private:
    int WeaponType_;
    int Damage_;
    int CallDown_;
    int Range_;
    int ShotsTotal_;
    int ShotsNow_;
    int Cost_;

public:
    TWeapon(int WeaponType, int Damage, int CallDown, int Range, int ShotsTotal, int ShotsNow, int Cost);
    TWeapon& operator =(const TWeapon& other);
    void SetWeaponType(int WeaponType);
    void SetDamage(int Damage);
    void SetCallDown(int CallDown);
    void SetRange(int Range);
    void SetShotsTotal(int ShotsTotal);
    void SetShotsNow(int ShotsNow);
    void SetCost(int Cost);

    int GetWeaponType() const;
    int GetDamage() const;
    int GetCallDown() const;
    int GetRange() const;
    int GetShotsTotal() const;
    int GetShotsNow() const;
    int GetCost() const;

    int MakeShot();
};

#endif //LAB4_TWEAPON_H
