//
// Created by grigorijivanenko on 17.12.22.
//

#include "TLevelSelector.h"

#include <string>
#include <iostream>
#include <fstream>

std::unique_ptr<TMission> TLevelSelector::ChooseLevel() {
    std::string pathToLevel = ReadLevelName();
    std::ifstream file(pathToLevel.c_str());
    if (!file) {
        std::string reasonToFinishGame = "Error opening file with level!";
        throw reasonToFinishGame;
    }
    std::unique_ptr<TMission> newMission = readMissionInfoFromStream(file);
    return std::move(newMission);
}

std::string TLevelSelector::ReadLevelName() {
    std::string levelNumber = ReadLevelNumberFromKeyboard();
    std::string levelName = "../../../resources/levels/" + levelNumber;
    if (CheckExists(levelName)) {
        return levelName;
    }
    std::string reasonToFinishGame = "File with level number" + levelNumber + "does not exist!";
    throw reasonToFinishGame;
}

std::string TLevelSelector::ReadLevelNumberFromKeyboard() {
    std::cout << "Enter level number\n";
    std::string s;
    getline(std::cin, s);
    try {
        int number = std::stoi(s);
        std::string levelNumber = std::to_string(number);
        return levelNumber;
    } catch(...) {
        std::string reasonToFinishGame = "Enter an integer - level number!";
        throw reasonToFinishGame;
    }
}

bool TLevelSelector::CheckExists(const std::string& path) {
    std::ifstream file(path.c_str());
    if (file)
        return true;
    else
        return false;
}

std::unique_ptr<TMission> TLevelSelector::readMissionInfoFromStream(std::istream& file) {
    try {
        MyList<TCapitanInfo> capitans = readTCapitanInfos(file);
        /*int capitanId = readInt.txt(file, "capitanNumber");
        ValidateCapitan(capitans, capitanId);

        MyList<TWeapon> weapons =  ReadTWeaponKinds(file);

        MyList<TShip> ships = ReadTShipKinds(file, capitans, weapons);

        MyList<int> weaponsEnableToBuy = ReadInts(file, "weapon numbers enable to buy");
        validateWeapons(weapons, weaponsEnableToBuy);

        MyList<int> shipsEnableToBuy = ReadInts(file, "ship numbers enable to buy");
        validateShips(ships, shipsEnableToBuy, capitans);


        int moneyTotal = readInt.txt(file, "moneyTotal");
        int weightTotal = readInt.txt(file, "weightTotal");
        int weightNeedToPass = readInt.txt(file, "weightNeedToPass");
        int width = readInt.txt(file, "width");
        int height = readInt.txt(file, "height");
        TBase A = ReadBase(file, "Base A");
        TBAse B = ReadBase(file, "Base B");
        MyList<TPirateBase> pirateBases = readBases(file, "Pirate bases");

        std::unique_ptr<TMission> newMission =
                std::make_unique<TMission>(
                capitanInfo,
                moneyTotal,
                weightTotal,
                weightNeedToPass,
                width,
                height,
                A,
                B,
                std::move(pirateBases)
        );
        return std::move(newMission);*/

    } catch(const std::string& what_happen) {
        std::string reasonToFinishGame = "Error parsing file(" + what_happen + ")";
        throw reasonToFinishGame;
    }
}

/////////////////////////////////////////////////////////////



TCapitanInfo TLevelSelector::ReadCapitanInfo(std::istream& file, const std::string& what) {
    std::string name = ReadString(file, what + "Name");
    std::string surname = ReadString(file, what + "Surname");
    std::string patronymic = ReadString(file, what + "Patronymic");
    std::string rank = ReadString(file, what + "Rank");
    TCapitanInfo res(name, surname, patronymic, rank);
    return res;
}


TBase TLevelSelector::ReadBase(std::istream& file, const std::string& what) {}

MyList<int> TLevelSelector::ReadInts(std::istream& file, const std::string& what) {
    int size = ReadInt(file, what + "Count");
    MyList<int> res;
    for (int i = 1; i <= size; ++i) {
        std::string status = what + "id";
        int item = ReadInt(file, status);
        res.insert(item, res.begin());
    }
    return std::move(res);
}

MyList<TCapitanInfo> TLevelSelector::TLevelSelector::readTCapitanInfos(std::istream& file) {
    int size = ReadInt(file, "CapitansCount");
    MyList<TCapitanInfo> capitans;
    for (int i = 1; i <= size; ++i) {
        std::string status = "Capitan";
        TCapitanInfo res = ReadCapitanInfo(file, status);
        capitans.insert(res, capitans.begin());
    }
    return std::move(capitans);
}
/*
MyList<TWeapon> TLevelSelector::ReadTWeaponKinds(std::istream& file);
MyList<TShip> TLevelSelector::ReadTShipKinds(std::istream& file);
MyList<TBase> TLevelSelector::readBases(std::istream& file, const std::string& what);

void TLevelSelector::ValidateCapitan(std::istream& file, const MyList<TCapitanInfo>& capitans, int capitanId);
void TLevelSelector::ValidateWeapons(const MyList<TWeapon> weapons, const MyList<int>& weaponsEnableToBuy);
void TLevelSelector::ValidateShips(
        const MyList<TShip> weapons,
        const MyList<int>& shipsEnableToBuy,
        const MyList<TCapitanInfo>& capitans);*/