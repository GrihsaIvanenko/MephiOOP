//
// Created by grigorijivanenko on 18.12.22.
//

#include "gtest/gtest.h"

#include "../../../../game/code/TLevelReader.h"

#include <fstream>

TEST(TLevelReader, ReadInt1) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readInt/test1.txt";
    std::ifstream file(pathToLevel.c_str());
    int val = TLevelReader().ReadInt(file, "int1");
    ASSERT_EQ(val, 4);
}

TEST(TLevelReader, ReadInt2) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readInt/test2.txt";
    std::ifstream file(pathToLevel.c_str());
    try {
        int val = TLevelReader().ReadInt(file, "intWithError");
        ASSERT_EQ(true, false);
    } catch (const std::string& ex) {
        ASSERT_EQ("Integer positive - so must contain only digits, but(a) detected", ex);
    }
}

TEST(TLevelReader, ReadInt3) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readInt/test3.txt";
    std::ifstream file(pathToLevel.c_str());
    try {
        int val = TLevelReader().ReadInt(file, "intWithError");
        ASSERT_EQ(true, false);
    } catch (const std::string& ex) {
        ASSERT_EQ("Error reading intWithError", ex);
    }
}

TEST(TLevelReader, ReadInt4) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readInt/test4.txt";
    std::ifstream file(pathToLevel.c_str());
    int val = TLevelReader().ReadInt(file, "another int");
    ASSERT_EQ(val, 25);
}

TEST(TLevelReader, ReadInt5) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readInt/test3.txt";
    std::ifstream file(pathToLevel.c_str());
    try {
        int val = TLevelReader().ReadInt(file, "not text");
        ASSERT_EQ(true, false);
    } catch (const std::string& ex) {
        ASSERT_EQ("Error reading not text", ex);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TLevelReader, ReadString1) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readString/test1.txt";
    std::ifstream file(pathToLevel.c_str());
    std::string val = TLevelReader().ReadString(file, "line1");
    ASSERT_EQ(val, "4a2");
}

TEST(TLevelReader, ReadString2) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readString/test2.txt";
    std::ifstream file(pathToLevel.c_str());
    try {
        std::string val = TLevelReader().ReadString(file, "line2");
        ASSERT_EQ(true, false);
    } catch (const std::string& ex) {
        ASSERT_EQ("Wrong line format of line2", ex);
    }
}

TEST(TLevelReader, ReadString3) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readString/test3.txt";
    std::ifstream file(pathToLevel.c_str());
    try {
        std::string val = TLevelReader().ReadString(file, "not line3");
        ASSERT_EQ(true, false);
    } catch (const std::string& ex) {
        ASSERT_EQ("Error reading not line3", ex);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TLevelReader, ReadCapitanInfo1) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readCapitanInfo/test1.txt";
    std::ifstream file(pathToLevel.c_str());
    TCapitanInfo val = TLevelReader().ReadCapitanInfo(file);
    ASSERT_EQ(val, TCapitanInfo("Jack", "Vorobey", "The best", "1"));
}

TEST(TLevelReader, ReadCapitanInfo2) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readCapitanInfo/test2.txt";
    std::ifstream file(pathToLevel.c_str());
    try {
        TCapitanInfo val = TLevelReader().ReadCapitanInfo(file);
        ASSERT_EQ(true, false);
    } catch (const std::string& ex) {
        ASSERT_EQ("Error reading CapitanRank", ex);
    }
}

TEST(TLevelReader, ReadCapitanInfo3) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readCapitanInfo/test3.txt";
    std::ifstream file(pathToLevel.c_str());
    try {
		TCapitanInfo val = TLevelReader().ReadCapitanInfo(file);
		ASSERT_EQ(true, false);
	} catch (const std::string& ex) {
		ASSERT_EQ("Error reading CapitanSurname", ex);
	}
}

TEST(TLevelReader, ReadCapitanInfo4) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readCapitanInfo/test4.txt";
    std::ifstream file(pathToLevel.c_str());
    try {
		TCapitanInfo val = TLevelReader().ReadCapitanInfo(file);
		ASSERT_EQ(true, false);
	} catch (const std::string& ex) {
		ASSERT_EQ("Error reading CapitanName", ex);
	}
}

TEST(TLevelReader, ReadCapitanInfo5) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readCapitanInfo/test5.txt";
    std::ifstream file(pathToLevel.c_str());
    try {
		TCapitanInfo val = TLevelReader().ReadCapitanInfo(file);
		ASSERT_EQ(true, false);
	} catch (const std::string& ex) {
		ASSERT_EQ("Wrong line format of CapitanName", ex);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TLevelReader, ReadWeapon) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readWeapon/test1.txt";
    std::ifstream file(pathToLevel.c_str());
	TWeapon val = TLevelReader().ReadWeapon(file);
	ASSERT_EQ(val, TWeapon(0, 10, 5, 0, 10, 20, 0, 30));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MyList<TCapitanInfo> GetCapitanInfo() {
    MyList<TCapitanInfo> res;
    res.insert(TCapitanInfo("1", "1", "1", "1"), res.end());
    res.insert(TCapitanInfo("2", "2", "2", "2"), res.end());
    res.insert(TCapitanInfo("3", "3", "3", "3"), res.end());
    return res;
}

TEST(TLevelReader, ReadShip1) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readShip/test1.txt";
    std::ifstream file(pathToLevel.c_str());
    MyList<TCapitanInfo> capitanInfos = GetCapitanInfo();
    std::unique_ptr<TShip> ptr = TLevelReader().ReadShip(file, capitanInfos);
    TCargoShip* shipPtr = dynamic_cast<TCargoShip*>(ptr.get());
    if (!shipPtr) {
        ASSERT_EQ(true, false);
    }
    ASSERT_EQ(*shipPtr, TCargoShip(0, 0, 1, "", capitanInfos.getById(1), 30, 0, 100, 0, 300, 1000, 0, 1.0 / 2));
}

TEST(TLevelReader, ReadShip2) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readShip/test2.txt";
    std::ifstream file(pathToLevel.c_str());
    MyList<TCapitanInfo> capitanInfos = GetCapitanInfo();
    std::unique_ptr<TShip> ptr = TLevelReader().ReadShip(file, capitanInfos);
    TWarShip* shipPtr = dynamic_cast<TWarShip*>(ptr.get());
    if (!shipPtr) {
        ASSERT_EQ(true, false);
    }
    ASSERT_EQ(*shipPtr, TWarShip(0, 0, 1, "", capitanInfos.getById(0), 30, 0, 100, 0, 200, TWeaponHolder()));
}

TEST(TLevelReader, ReadShip3) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readShip/test3.txt";
    std::ifstream file(pathToLevel.c_str());
    MyList<TCapitanInfo> capitanInfos = GetCapitanInfo();
    std::unique_ptr<TShip> ptr = TLevelReader().ReadShip(file, capitanInfos);
    TCargoWarShip* shipPtr = dynamic_cast<TCargoWarShip*>(ptr.get());
    if (!shipPtr) {
        ASSERT_EQ(true, false);
    }
    ASSERT_EQ(*shipPtr, TCargoWarShip(0, 0, 1, "", capitanInfos.getById(2), 30, 0, 100, 0, 400, 1000, 0, 1.0 / 2, TWeaponHolder()));
}

TEST(TLevelReader, ReadShip4) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readShip/test4.txt";
    std::ifstream file(pathToLevel.c_str());
    MyList<TCapitanInfo> capitanInfos = GetCapitanInfo();
    try {
        std::unique_ptr<TShip> ptr = TLevelReader().ReadShip(file, capitanInfos);
        ASSERT_EQ(true, false);
    } catch (const std::string& ex) {
        ASSERT_EQ(ex, "Wrong ShipType");
    }
}

TEST(TLevelReader, ReadShip5) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readShip/test5.txt";
    std::ifstream file(pathToLevel.c_str());
    MyList<TCapitanInfo> capitanInfos = GetCapitanInfo();
    try {
        std::unique_ptr<TShip> ptr = TLevelReader().ReadShip(file, capitanInfos);
        ASSERT_EQ(true, false);
    } catch (const std::string& ex) {
        ASSERT_EQ(ex, "Bad id = 7 in range [0, 3)");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TLevelReader, ReadBase1) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readBase/test1.txt";
    std::ifstream file(pathToLevel.c_str());
    TBase baseA = TLevelReader().ReadBase(file, "BaseA");
    ASSERT_EQ(baseA, TBase(1, 0, 1));
}

TEST(TLevelReader, ReadBase2) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readBase/test2.txt";
    std::ifstream file(pathToLevel.c_str());
    TBase baseB = TLevelReader().ReadBase(file, "BaseB");
    ASSERT_EQ(baseB, TBase(1, 0, 2));
}

TEST(TLevelReader, ReadBase3) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readBase/test3.txt";
    std::ifstream file(pathToLevel.c_str());
    try {
        TBase base = TLevelReader().ReadBase(file, "BaseA");
        ASSERT_EQ(true, false);
    } catch (const std::string& ex) {
        ASSERT_EQ(ex, "Wrong base type(3) in BaseA");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TLevelReader, ReadInts1) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readInts/test1.txt";
    std::ifstream file(pathToLevel.c_str());
    MyList<int> listTest = TLevelReader().ReadInts(file, "Number");
    MyList<int> listANS;
    listANS.insert(1, listANS.end());
    listANS.insert(2, listANS.end());
    listANS.insert(3, listANS.end());
    ASSERT_EQ(listTest, listANS);
}

TEST(TLevelReader, ReadInts2) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readInts/test2.txt";
    std::ifstream file(pathToLevel.c_str());
    try {
        MyList<int> listTest = TLevelReader().ReadInts(file, "Number");
        ASSERT_EQ(true, false);
    } catch (const std::string& ex) {
        ASSERT_EQ(ex, "Integer positive - so must contain only digits, but(-) detected");
    }
}

TEST(TLevelReader, ReadInts3) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readInts/test3.txt";
    std::ifstream file(pathToLevel.c_str());
    try {
        MyList<int> listTest = TLevelReader().ReadInts(file, "Number");
        ASSERT_EQ(true, false);
    } catch (const std::string& ex) {
        ASSERT_EQ(ex, "Error reading Number");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


TEST(TLevelReader, ReadCapitanInfos1) {
     std::string pathToLevel = "./game/tests/TLevelReader/data/readCapitanInfos/test1.txt";
     std::ifstream file(pathToLevel.c_str());
     MyList<TCapitanInfo> capitans = TLevelReader().ReadCapitanInfos(file);
     ASSERT_EQ(capitans.size(), 3);
     ASSERT_EQ(capitans.getById(0), TCapitanInfo("Jack", "Vorobey", "The best", "1"));
 }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


TEST(TLevelReader, ReadWeapons1) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readWeapons/test1.txt";
    std::ifstream file(pathToLevel.c_str());
    MyList<TWeapon> weapons = TLevelReader().ReadWeapons(file);
    ASSERT_EQ(weapons.size(), 2);
 }



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TLevelReader, ReadShips1) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readShips/test1.txt";
    std::ifstream file(pathToLevel.c_str());
     MyList<TCapitanInfo> capitanInfos = GetCapitanInfo();
    MyList<std::unique_ptr<TShip>> ships = TLevelReader().ReadShips(file, capitanInfos);
    ASSERT_EQ(ships.size(), 3);
 }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MyList<std::unique_ptr<TShip>> GetShips() {
    MyList<TCapitanInfo> capitans = GetCapitanInfo();
    MyList<std::unique_ptr<TShip>> res;
    res.insert(std::make_unique<TCargoShip>(
            0, 0, 1, "", capitans.getById(1), 30, 0, 100, 0, 300, 1000, 0, 1.0 / 2), res.end());
    res.insert(std::make_unique<TWarShip>(
            0, 0, 2, "", capitans.getById(0), 30, 0, 100, 0, 300, TWeaponHolder()), res.end());
    res.insert(std::make_unique<TCargoWarShip>(
            0, 0, 3, "", capitans.getById(1), 30, 0, 100, 0, 400, 1000, 0, 1.0 / 2, TWeaponHolder()), res.end());
    return res;
}

TEST(TLevelReader, ReadSpawnDescriptor1) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readSpawnDescriptor/test1.txt";
    std::ifstream file(pathToLevel.c_str());
    MyList<std::unique_ptr<TShip>> ships = GetShips();
    TSpawnDescriptor res = TLevelReader().ReadSpawnDescriptor(file, ships);
    ASSERT_EQ(res.Spawn(15).getById(0), *(dynamic_cast<TWarShip*>(ships.getById(1).get())));
}

TEST(TLevelReader, ReadSpawnDescriptor2) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readSpawnDescriptor/test2.txt";
    std::ifstream file(pathToLevel.c_str());
    MyList<std::unique_ptr<TShip>> ships = GetShips();
    try {
        TSpawnDescriptor res = TLevelReader().ReadSpawnDescriptor(file, ships);
        ASSERT_EQ(true, false);
    } catch (const std::string& ex) {
        ASSERT_EQ(ex, "Not TWarShip");
    }
}

TEST(TLevelReader, ReadSpawnDescriptor3) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readSpawnDescriptor/test3.txt";
    std::ifstream file(pathToLevel.c_str());
    MyList<std::unique_ptr<TShip>> ships = GetShips();
    try {
        TSpawnDescriptor res = TLevelReader().ReadSpawnDescriptor(file, ships);
        ASSERT_EQ(true, false);
    } catch (const std::string& ex) {
        ASSERT_EQ(ex, "Wrong ShipType");
    }
}

TEST(TLevelReader, ReadSpawnDescriptor4) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readSpawnDescriptor/test2.txt";
    std::ifstream file(pathToLevel.c_str());
    MyList<std::unique_ptr<TShip>> ships = GetShips();
    try {
        TSpawnDescriptor res = TLevelReader().ReadSpawnDescriptor(file, ships);
        ASSERT_EQ(true, false);
    } catch (const std::string& ex) {
        ASSERT_EQ(ex, "Not TWarShip");
    }
}

TEST(TLevelReader, ReadSpawnDescriptor5) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readSpawnDescriptor/test5.txt";
    std::ifstream file(pathToLevel.c_str());
    MyList<std::unique_ptr<TShip>> ships = GetShips();
    try {
        TSpawnDescriptor res = TLevelReader().ReadSpawnDescriptor(file, ships);
        ASSERT_EQ(true, false);
    } catch (const std::string& ex) {
        ASSERT_EQ(ex, "Integer positive - so must contain only digits, but(-) detected");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TLevelReader, ReadSpawnDescriptors1) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readSpawnDescriptors/test1.txt";
    std::ifstream file(pathToLevel.c_str());
    MyList<std::unique_ptr<TShip>> ships = GetShips();
    MyList<TSpawnDescriptor> descriptors = TLevelReader().ReadSpawnDescriptors(file, ships);
    ASSERT_EQ(descriptors.size(), 5);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MyList<TSpawnDescriptor> GetDescriptors() {
    MyList<std::unique_ptr<TShip>> ships = GetShips();
    MyList<TSpawnDescriptor> res;
    TSpawnDescriptor a(*(dynamic_cast<TWarShip*>(ships.getById(1).get())), 10, 1, 0);
    TSpawnDescriptor b(*(dynamic_cast<TWarShip*>(ships.getById(1).get())), 10, 2, 0);
    res.insert(std::move(a), res.end());
    res.insert(std::move(b), res.end());
    return std::move(res);
}

TEST(TLevelReader, ReadPirateBase1) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readPirateBase/test1.txt";
    std::ifstream file(pathToLevel.c_str());
    MyList<TSpawnDescriptor> descriptors = GetDescriptors();
    TPirateBase base = TLevelReader().ReadPirateBase(file, descriptors);
    ASSERT_EQ(base.GetSpawnDescriptor(), descriptors.getById(0));
}

TEST(TLevelReader, ReadPirateBase2) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readPirateBase/test2.txt";
    std::ifstream file(pathToLevel.c_str());
    try {
        MyList<TSpawnDescriptor> descriptors = GetDescriptors();
        TPirateBase base = TLevelReader().ReadPirateBase(file, descriptors);
        ASSERT_EQ(base.GetSpawnDescriptor(), descriptors.getById(0));
        ASSERT_EQ(true, false);
    } catch (const std::string& ex) {
        ASSERT_EQ(ex, "Type of pirateBase must be 3 instead of 2");
    }
}

TEST(TLevelReader, ReadPirateBase3) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readPirateBase/test3.txt";
    std::ifstream file(pathToLevel.c_str());
    try {
        MyList<TSpawnDescriptor> descriptors = GetDescriptors();
        TPirateBase base = TLevelReader().ReadPirateBase(file, descriptors);
        ASSERT_EQ(base.GetSpawnDescriptor(), descriptors.getById(0));
        ASSERT_EQ(true, false);
    }catch (const std::string& ex) {
        ASSERT_EQ(ex, "Bad id = 10 in range [0, 2)");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TLevelReader, ReadPirateBases) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readPirateBases/test1.txt";
    std::ifstream file(pathToLevel.c_str());
    MyList<TSpawnDescriptor> descriptors = GetDescriptors();
    MyList<TPirateBase> bases = TLevelReader().ReadPirateBases(file, descriptors);
    ASSERT_EQ(bases.size(), 4);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


TEST(TLevelReader, ReadMissionInfoFromStream1) {
    std::string pathToLevel = "./game/tests/TLevelReader/data/readMission/test1.txt";
    std::ifstream file(pathToLevel.c_str());
    std::pair<std::unique_ptr<TMission>, std::pair<MyList<TWeapon>, MyList<std::unique_ptr<TShip>>>> mission =
             TLevelReader().ReadMissionInfoFromStream(file);
    ASSERT_EQ(mission.second.first.size(), 2);
    ASSERT_EQ(mission.second.second.size(), 3);
 }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}