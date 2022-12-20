//
// Created by grigorijivanenko on 20.12.22.
//

#ifndef LAB4_TSHOP_H
#define LAB4_TSHOP_H

#include "TMission.h"

class TShop {
public:
    int ReadInt(std::istream& file);
    void PrintOptions(const std::vector<std::string>>& options);
    void PrintInfo(std::unique_ptr<TMission>& mission);

    bool AskPlay(std::istream& file);
    void ByShip(std::unique_ptr<TMission>& mission, const MyList<std::unique_ptr<TShip>>& ships, std::istream& file);
    void SellShip(std::unique_ptr<TMission>& mission, std::istream& file);
    void BuyGun(std::unique_ptr<TMission>& mission, const MyList<TWeapons>& guns, std::istream& file);
    void SellGun(std::unique_ptr<TMission>& mission, std::istream& file);

    std::unique_ptr<TMission> MainMenu(
        std::unique_ptr<TMission> mission,
        MyList<TWeapon>&& weapons_,
        MyList<std::unique_ptr<TShip>>&& ships_,
        std::istream& file);
public:
    std::unique_ptr<TMission> Shop(
        std::pair<std::unique_ptr<TMission>, std::pair<MyList<TWeapon>, MyList<std::unique_ptr<TShip>>>>&& data,
        std::istream& file);
};
#endif //LAB4_TSHOP_H