//
// Created by grigorijivanenko on 18.12.22.
//

#ifndef LAB4_TLEVELREADER_H
#define LAB4_TLEVELREADER_H

#include "TMission.h"

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
    TBase ReadBase(std::istream& file, const std::string& what);

    MyList<int> ReadInts(std::istream& file, const std::string& what);
    MyList<TCapitanInfo> ReadCapitanInfos(std::istream& file);
    MyList<TWeapon> ReadWeapons(std::istream& file);
    MyList<std::unique_ptr<TShip>> ReadShips(std::istream& file, const MyList<TCapitanInfo>& capitans);

    TSpawnDescriptor ReadSpawnDescriptor(std::istream& file, const MyList<std::unique_ptr<TShip>>& ships);
    MyList<TSpawnDescriptor> ReadSpawnDescriptors(std::istream& file, const MyList<std::unique_ptr<TShip>>& ships);

    TPirateBase ReadPirateBase(std::istream& file, const MyList<TSpawnDescriptor>& desctiptors);
    MyList<TPirateBase> ReadPirateBases(std::istream& file, const MyList<TSpawnDescriptor>& descriptots);
public:
    std::pair<std::unique_ptr<TMission>, std::pair<MyList<TWeapon>, MyList<std::unique_ptr<TShip>>>>
        ReadMissionInfoFromStream(std::istream& file);
};

#endif //LAB4_TLEVELREADER_H
