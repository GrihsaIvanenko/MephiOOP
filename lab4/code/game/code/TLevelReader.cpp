//
// Created by grigorijivanenko on 18.12.22.
//

#include "TLevelReader.h"

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
}

TBase TLevelReader::ReadBase(std::istream& file, const std::string& what) {
    int x = ReadInt(file, "Base_X");
    int y = ReadInt(file, "Base_Y");
    int type = ReadInt(file, "Base_Type");
    if (type == 1) {
        TBase baseA(x, y, type);
        return baseA;
    }
    if (type == 2) {
        TBase baseB(x, y, type);
        return baseB;
    }
    std::string ex = "Wrong base type(" + std::to_string(type) + ") in " + what;
    throw ex;
}

MyList<int> TLevelReader::ReadInts(std::istream& file, const std::string& what) {
    int count = ReadInt(file, what + "Count");
    ReadEmpty(file);
    if (count < 0) {
        std::string ex = "Wrong count of " + what;
        throw ex;
    }
    MyList<int> res;
    for (int i = 0; i < count; ++i) {
        int item = ReadInt(file, what);
        ReadEmpty(file);
        res.insert(std::move(item), res.end());
    }
    return std::move(res);
}

MyList<TCapitanInfo> TLevelReader::ReadCapitanInfos(std::istream& file) {
    int count = ReadInt(file, "CapitansCount");
    ReadEmpty(file);
    if (count < 0) {
        std::string ex = "Wrong count of CapitansCount";
        throw ex;
    }
    MyList<TCapitanInfo> res;
    for (int i = 0; i < count; ++i) {
        TCapitanInfo item = ReadCapitanInfo(file);
        ReadEmpty(file);
        res.insert(std::move(item), res.end());
    }
    return std::move(res);
}

MyList<TWeapon> TLevelReader::ReadWeapons(std::istream& file) {
    int count = ReadInt(file, "WeaponCount");
    ReadEmpty(file);
    if (count < 0) {
        std::string ex = "Wrong count of WeaponCount";
        throw ex;
    }
    MyList<TWeapon> res;
    for (int i = 0; i < count; ++i) {
        TWeapon item = ReadWeapon(file);
        ReadEmpty(file);
        res.insert(std::move(item), res.end());
    }
    return std::move(res);
}

MyList<std::unique_ptr<TShip>> TLevelReader::ReadShips(std::istream& file, const MyList<TCapitanInfo>& capitans) {
    int count = ReadInt(file, "ShipsCount");
    ReadEmpty(file);
    if (count < 0) {
        std::string ex = "Wrong count of ShipsCount";
        throw ex;
    }
    MyList<std::unique_ptr<TShip>> res;
    for (int i = 0; i < count; ++i) {
        std::unique_ptr<TShip> item = ReadShip(file, capitans);
        ReadEmpty(file);
        res.insert(std::move(item), res.end());
    }
    return std::move(res);
}

TSpawnDescriptor TLevelReader::ReadSpawnDescriptor(std::istream& file, const MyList<std::unique_ptr<TShip>>& ships) {
    int spawnShipId = ReadInt(file, "ShipSpawnType");
    if (spawnShipId < 0 || spawnShipId >= ships.size()) {
        std::string ex = "Wrong ShipType";
        throw ex;
    }
    if (!(dynamic_cast<TWarShip*>(ships.getById(spawnShipId).get()))) {
        std::string ex = "Not TWarShip";
        throw ex;
    }
    TWarShip spawnShip(*dynamic_cast<TWarShip*>(ships.getById(spawnShipId).get()));

    int spamCount = ReadInt(file, "SpamCount");
    if (spamCount < 0) {
        std::string ex = "SpamCount < 0";
        throw ex;
    }
    int loopTime = ReadInt(file, "LoopTime");
    if (loopTime < 0) {
        std::string ex = "LoopTime < 0";
        throw ex;
    }
    TSpawnDescriptor res(spawnShip, spamCount, loopTime, 0);
    return res;
}

MyList<TSpawnDescriptor> TLevelReader::ReadSpawnDescriptors(std::istream& file, const MyList<std::unique_ptr<TShip>>& ships) {
    int count = ReadInt(file, "SpawnDescriptorsCount");
    ReadEmpty(file);
    if (count < 0) {
        std::string ex = "Wrong count of SpawnDescriptors";
        throw ex;
    }
    MyList<TSpawnDescriptor> res;
    for (int i = 0; i < count; ++i) {
        TSpawnDescriptor item = ReadSpawnDescriptor(file, ships);
        ReadEmpty(file);
        res.insert(std::move(item), res.end());
    }
    return std::move(res);
}

TPirateBase TLevelReader::ReadPirateBase(std::istream& file, const MyList<TSpawnDescriptor>& descriptors) {
    int x = ReadInt(file, "Base_X");
    int y = ReadInt(file, "Base_Y");
    int type = ReadInt(file, "Base_Type");
    if (type != 3) {
        std::string ex = "Type of pirateBase must be 3 instead of " + std::to_string(type);
        throw ex;
    }
    int descriptorId = ReadInt(file, "DescriptorNumber");
    TSpawnDescriptor desc = descriptors.getById(descriptorId);
    TPirateBase res(x, y, type, desc);
    return res;
}

MyList<TPirateBase> TLevelReader::ReadPirateBases(std::istream& file, const MyList<TSpawnDescriptor>& descriptots) {
    int count = ReadInt(file, "TPirateBaseCount");
    ReadEmpty(file);
    if (count < 0) {
        std::string ex = "Wrong count of TPirateBase";
        throw ex;
    }
    MyList<TPirateBase> res;
    for (int i = 0; i < count; ++i) {
        TPirateBase item = ReadPirateBase(file, descriptots);
        ReadEmpty(file);
        res.insert(std::move(item), res.end());
    }
    return std::move(res);
}

std::pair<std::unique_ptr<TMission>, std::pair<MyList<TWeapon>, MyList<std::unique_ptr<TShip>>>>
        TLevelReader::ReadMissionInfoFromStream(std::istream& file) {
    MyList<TCapitanInfo> capitans = ReadCapitanInfos(file);
    int capitanId = ReadInt(file, "CapitanNumber");
    TCapitanInfo capitan = capitans.getById(capitanId);
    ReadEmpty(file);

    MyList<TWeapon> weapons = ReadWeapons(file);

    MyList<std::unique_ptr<TShip>> ships = ReadShips(file, capitans);

    int moneyTotal = ReadInt(file, "moneyTotal");
    int weightTotal = ReadInt(file, "weightTotal");
    int weightNeedToPass = ReadInt(file, "weightNeedToPass");
    int width = ReadInt(file, "width");
    int height = ReadInt(file, "height");
    ReadEmpty(file);
    TBase A = ReadBase(file, "Base A");
    ReadEmpty(file);
    TBase B = ReadBase(file, "Base B");
    ReadEmpty(file);
    MyList<TSpawnDescriptor> descriptors = ReadSpawnDescriptors(file, ships);
    MyList<TPirateBase> pirateBases = ReadPirateBases(file, descriptors);

    std::unique_ptr<TMission> newMission =
            std::make_unique<TMission>(
                    capitan,
            moneyTotal,
            weightTotal,
            weightNeedToPass,
            width,
            height,
            A,
            B,
            std::move(pirateBases)
    );
    return std::make_pair(std::move(newMission), std::make_pair(std::move(weapons), std::move(ships)));
}