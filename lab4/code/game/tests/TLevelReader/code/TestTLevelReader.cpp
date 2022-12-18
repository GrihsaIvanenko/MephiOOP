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

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}