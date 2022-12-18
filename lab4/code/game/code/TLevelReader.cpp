//
// Created by grigorijivanenko on 18.12.22.
//

#include "TLevelReader.h"
#include <memory>

int TLevelReader::ReadInt(std::istream& file, const std::string& what) {
    std::string line;
    getline(file, line);
    std::string beg = line.substr(0, what.size());
    if (beg != what) {
        std::string errorReading = "Error reading " + what;
        throw errorReading;
    }
    if (line.size() <= what.size() + 2 || line[what.size()] != ':' || line[what.size() + 1] != ' ') {
        std::string errorReading = "Wrong line format of " + what;
        throw errorReading;
    }
    std::string mainPart = line.substr(what.size() + 2);
    for (auto x : mainPart)
        if (!('0' <= x && x <= '9')) {
            std::string tmp;
            tmp.push_back(x);
            std::string errorReading = "Integer positive - so must contain only digits, but(" + tmp + ") detected";
            throw errorReading;
        }
    try {
        int result = std::stoi(mainPart);
        return result;
    } catch(...) {
        std::string errorReading = what + " - is not integer(" + mainPart + ")";
        throw errorReading;
    }
}

std::string TLevelReader::ReadString(std::istream& file, const std::string& what) {
    std::string line;
    getline(file, line);
    std::string beg = line.substr(0, what.size());
    if (beg != what) {
        std::string errorReading = "Error reading " + what;
        throw errorReading;
    }
    if (line.size() <= what.size() + 2 || line[what.size()] != ':' || line[what.size() + 1] != ' ') {
        std::string errorReading = "Wrong line format of " + what;
        throw errorReading;
    }
    std::string mainPart = line.substr(what.size() + 2);
    return mainPart;
}

void TLevelReader::ReadEmpty(std::istream &file) {
    std::string s;
    getline(file, s);
    if (s.size()) {
        std::string errorReading = "not empty line!";
        throw errorReading;
    }
}

TCapitanInfo TLevelReader::ReadCapitanInfo(std::istream& file) {
    std::string name = ReadString(file, "CapitanName");
    std::string surname = ReadString(file, "CapitanSurname");
    std::string patronymic = ReadString(file, "CapitanPatronymic");
    std::string rank = ReadString(file, "CapitanRank");
    TCapitanInfo res(name, surname, patronymic, rank);
    return res;
}

TWeapon TLevelReader::ReadWeapon(std::istream& file) {
    int weaponType = ReadInt(file, "WeaponType");
    int damage = ReadInt(file, "Damage");
    int callDown = ReadInt(file, "CallDown");
    int range = ReadInt(file, "Range");
    int shotsTotal = ReadInt(file, "ShotsTotal");
    int cost = ReadInt(file, "Cost");
    TWeapon res(weaponType, damage, callDown, 0, range, shotsTotal, 0, cost);
    return res;
}

std::unique_ptr<TShip> TLevelReader::ReadShip(std::istream& file, const MyList<TCapitanInfo>& capitans) {
    int type = ReadInt(file, "ShipType");
    int capitanInfoId = ReadInt(file, "CapitanInfoId");
    TCapitanInfo capitanInfo = capitans.getById(capitanInfoId);
    int MaxSpeed = ReadInt(file, "MaxSpeed");
    int HPTotal = ReadInt(file, "HPTotal");
    int Cost = ReadInt(file, "Cost");
    if (type == 1) { //TCargoShip
        int WeightTotal = ReadInt(file, "WeightTotal");
        double SlowK = 1.0 / ReadInt(file, "SlowK");
        std::unique_ptr<TCargoShip> ptr = std::make_unique<TCargoShip>(
                0, 0, 1, "", capitanInfo, MaxSpeed, 0, HPTotal, 0, Cost, WeightTotal, 0, SlowK);
        return std::move(ptr);
    } else if (type == 2) {
        std::unique_ptr<TWarShip> ptr = std::make_unique<TWarShip>(
                0, 0, 1, "", capitanInfo, MaxSpeed, 0, HPTotal, 0, Cost, TWeaponHolder());
        return std::move(ptr);
    } else if (type == 3) {
        int WeightTotal = ReadInt(file, "WeightTotal");
        double SlowK = 1.0 / ReadInt(file, "SlowK");
        std::unique_ptr<TCargoWarShip> ptr= std::make_unique<TCargoWarShip>(
                0, 0, 1, "", capitanInfo, MaxSpeed, 0, HPTotal, 0, Cost, WeightTotal, 0, SlowK, TWeaponHolder());
        return std::move(ptr);
    }
    std::string except = "Wrong ShipType";
    throw except;
    return nullptr;
}

TBase TLevelReader::ReadBase(std::istream& file) {

}