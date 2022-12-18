//
// Created by grigorijivanenko on 18.12.22.
//

#ifndef LAB4_TLEVELREADER_H
#define LAB4_TLEVELREADER_H

#include "../soon/TMission.h"

#include <memory>
#include <iostream>

class TLevelReader {
public:
    int ReadInt(std::istream& file, const std::string& what);
    std::string ReadString(std::istream& file, const std::string& what);
    void ReadEmpty(std::istream& file);

    TCapitanInfo ReadCapitanInfo(std::istream& file);
    TWeapon ReadWeapon(std::istream& file);
    std::unique_ptr<TShip> ReadShip(std::istream& file, const MyList<TCapitanInfo>& capitans);
    TBase ReadBase(std::istream& file);

    MyList<int> ReadInts(std::istream& file, const std::string& what);
    MyList<TCapitanInfo> readTCapitanInfos(std::istream& file);
    MyList<TWeapon> ReadTWeaponKinds(std::istream& file);
    MyList<TShip> ReadTShipKinds(std::istream& file);
    MyList<TBase> readBases(std::istream& file, const std::string& what);

    void ValidateCapitan(std::istream& file, const MyList<TCapitanInfo>& capitans, int capitanId);
    void ValidateWeapons(const MyList<TWeapon> weapons, const MyList<int>& weaponsEnableToBuy);
    void ValidateShips(
            const MyList<TShip> weapons,
            const MyList<int>& shipsEnableToBuy,
            const MyList<TCapitanInfo>& capitans);
    std::unique_ptr<TMission> readMissionInfoFromStream(std::istream& file);
};

#endif //LAB4_TLEVELREADER_H
